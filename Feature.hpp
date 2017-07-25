
// kurff detection 
// 30-12-2016
#ifndef _KURFF_FEATURE_HPP_
#define _KURFF_FEATURE_HPP_

#include "tensor/common.hpp"
#include "proto/kurff.pb.h"
#include "tensor.h"
#include <iostream>
#include <vector>

using namespace std;


namespace kurff{

    template<typename Context>
    class Feature{
        public:
            Feature():input_(nullptr),output_(shared_ptr<Tensor<Context> > (new Tensor<Context> ())){
                
            }
            
            ~Feature(){


            }

            //set parameters
            
            virtual bool set(const Parameters& para) = 0;

            virtual bool initial() = 0;

            virtual bool run() = 0;

            void set_input(Tensor<Context>* input){
                input_ = shared_ptr<Tensor<Context> >(input);
            }

            Tensor<Context>* get_output(){
                return output_.get();
            }
            //virtual bool destroy() = 0;

            
            

        protected:
            shared_ptr< Tensor<Context> > input_;
            shared_ptr< Tensor<Context> > output_;



    };

    template<typename Context>
    class HOGFeature: public Feature<Context>{
        public:
            HOGFeature(){

            }
            ~HOGFeature(){

            }

            bool set(const Parameters& para){
                sbin_ =  para.hog_parameters().sbin();
                LOG(INFO)<<sbin_;
                return true;
            }
            bool initial(){

                return true;
            }
            bool run(){
                float uu[9] = {1.0000, 0.9397, 0.7660, 0.500, 0.1736, -0.1736, -0.5000, -0.7660, -0.9397};
                float vv[9] = {0.0000, 0.3420, 0.6428, 0.8660, 0.9848, 0.9848, 0.8660, 0.6428, 0.3420};
                int height = this->input_->dims()[2];
                int width = this->input_->dims()[3];
                vector<int> dims = this->input_->dims();
                float *im = this->input_->template mutable_data<float>();
                int blocks[2];

                
                blocks[0] = (int)round((float)height / (float)sbin_);
                blocks[1] = (int)round((float)width / (float)sbin_);
                float* hist = new float[blocks[0] * blocks[1] * 18]();
                float *norm = new float[blocks[0] * blocks[1]]();
                
                int out[3];
                out[0] = max<int>(blocks[0] - 2, 0);
                out[1] = max<int>(blocks[1] - 2, 0);
                out[2] = 27 + 4 + 1;

                
                vector<int> out_dims;
                out_dims.resize(4);
                out_dims[0] = 1; out_dims[1] = out[0];
                out_dims[2] = out[1]; out_dims[3] = out[2];
                
                this->output_->Reshape(out_dims);
                float* feat = this->output_->template mutable_data<float>();

                int visible[2];
                visible[0] = blocks[0] * sbin_;
                visible[1] = blocks[1] * sbin_;
                for (int x = 1; x < visible[1] - 1; x++)
                {
                    for (int y = 1; y < visible[0] - 1; y++)
                    {
                        // first color channel
                        float *s = im + min<int>(x, dims[1] - 2) * dims[0] + min<int>(y, dims[0] - 2);
                        float dy = *(s + 1) - *(s - 1);
                        float dx = *(s + dims[0]) - *(s - dims[0]);
                        float v = dx * dx + dy * dy;

                        // second color channel
                        s += dims[0] * dims[1];
                        float dy2 = *(s + 1) - *(s - 1);
                        float dx2 = *(s + dims[0]) - *(s - dims[0]);
                        float v2 = dx2 * dx2 + dy2 * dy2;

                        // third color channel
                        s += dims[0] * dims[1];
                        float dy3 = *(s + 1) - *(s - 1);
                        float dx3 = *(s + dims[0]) - *(s - dims[0]);
                        float v3 = dx3 * dx3 + dy3 * dy3;

                        // pick channel with strongest gradient
                        if (v2 > v)
                        {
                            v = v2;
                            dx = dx2;
                            dy = dy2;
                        }
                        if (v3 > v)
                        {
                            v = v3;
                            dx = dx3;
                            dy = dy3;
                        }

                        // snap to one of 18 orientations
                        float best_dot = 0;
                        int best_o = 0;
                        for (int o = 0; o < 9; o++)
                        {
                            float dot = uu[o] * dx + vv[o] * dy;
                            if (dot > best_dot)
                            {
                                best_dot = dot;
                                best_o = o;
                            }
                            else if (-dot > best_dot)
                            {
                                best_dot = -dot;
                                best_o = o + 9;
                            }
                        }

                        // add to 4 histograms around pixel using linear interpolation
                        float xp = ((float)x + 0.5) / (float)sbin_ - 0.5;
                        float yp = ((float)y + 0.5) / (float)sbin_ - 0.5;
                        int ixp = (int)floor(xp);
                        int iyp = (int)floor(yp);
                        float vx0 = xp - ixp;
                        float vy0 = yp - iyp;
                        float vx1 = 1.0 - vx0;
                        float vy1 = 1.0 - vy0;
                        v = sqrt(v);

                        if (ixp >= 0 && iyp >= 0)
                        {
                            *(hist + ixp * blocks[0] + iyp + best_o * blocks[0] * blocks[1]) +=
                                vx1 * vy1 * v;
                        }

                        if (ixp + 1 < blocks[1] && iyp >= 0)
                        {
                            *(hist + (ixp + 1) * blocks[0] + iyp + best_o * blocks[0] * blocks[1]) +=
                                vx0 * vy1 * v;
                        }

                        if (ixp >= 0 && iyp + 1 < blocks[0])
                        {
                            *(hist + ixp * blocks[0] + (iyp + 1) + best_o * blocks[0] * blocks[1]) +=
                                vx1 * vy0 * v;
                        }

                        if (ixp + 1 < blocks[1] && iyp + 1 < blocks[0])
                        {
                            *(hist + (ixp + 1) * blocks[0] + (iyp + 1) + best_o * blocks[0] * blocks[1]) +=
                                vx0 * vy0 * v;
                        }
                    }
                }

                // compute energy in each block by summing over orientations
                for (int o = 0; o < 9; o++)
                {
                    float *src1 = hist + o * blocks[0] * blocks[1];
                    float *src2 = hist + (o + 9) * blocks[0] * blocks[1];
                    float *dst = norm;
                    float *end = norm + blocks[1] * blocks[0];
                    while (dst < end)
                    {
                        *(dst++) += (*src1 + *src2) * (*src1 + *src2);
                        src1++;
                        src2++;
                    }
                }

                // compute features
                for (int x = 0; x < out[1]; x++)
                {
                    for (int y = 0; y < out[0]; y++)
                    {
                        float *dst = feat + x * out[0] + y;
                        float *src, *p, n1, n2, n3, n4;

                        p = norm + (x + 1) * blocks[0] + y + 1;
                        n1 = 1.0 / sqrt(*p + *(p + 1) + *(p + blocks[0]) + *(p + blocks[0] + 1) + FLOAT_EPS);
                        p = norm + (x + 1) * blocks[0] + y;
                        n2 = 1.0 / sqrt(*p + *(p + 1) + *(p + blocks[0]) + *(p + blocks[0] + 1) + FLOAT_EPS);
                        p = norm + x * blocks[0] + y + 1;
                        n3 = 1.0 / sqrt(*p + *(p + 1) + *(p + blocks[0]) + *(p + blocks[0] + 1) + FLOAT_EPS);
                        p = norm + x * blocks[0] + y;
                        n4 = 1.0 / sqrt(*p + *(p + 1) + *(p + blocks[0]) + *(p + blocks[0] + 1) + FLOAT_EPS);

                        float t1 = 0;
                        float t2 = 0;
                        float t3 = 0;
                        float t4 = 0;

                        // contrast-sensitive features
                        src = hist + (x + 1) * blocks[0] + (y + 1);
                        for (int o = 0; o < 18; o++)
                        {
                            float h1 = min<float>(*src * n1, 0.2);
                            float h2 = min<float>(*src * n2, 0.2);
                            float h3 = min<float>(*src * n3, 0.2);
                            float h4 = min<float>(*src * n4, 0.2);
                            *dst = 0.5 * (h1 + h2 + h3 + h4);
                            t1 += h1;
                            t2 += h2;
                            t3 += h3;
                            t4 += h4;
                            dst += out[0] * out[1];
                            src += blocks[0] * blocks[1];
                        }

                        // contrast-insensitive features
                        src = hist + (x + 1) * blocks[0] + (y + 1);
                        for (int o = 0; o < 9; o++)
                        {
                            float sum = *src + *(src + 9 * blocks[0] * blocks[1]);
                            float h1 = min<float>(sum * n1, 0.2);
                            float h2 = min<float>(sum * n2, 0.2);
                            float h3 = min<float>(sum * n3, 0.2);
                            float h4 = min<float>(sum * n4, 0.2);
                            *dst = 0.5 * (h1 + h2 + h3 + h4);
                            dst += out[0] * out[1];
                            src += blocks[0] * blocks[1];
                        }

                        // texture features
                        *dst = 0.2357 * t1;
                        dst += out[0] * out[1];
                        *dst = 0.2357 * t2;
                        dst += out[0] * out[1];
                        *dst = 0.2357 * t3;
                        dst += out[0] * out[1];
                        *dst = 0.2357 * t4;

                        // truncation feature
                        dst += out[0] * out[1];
                        *dst = 0;
                    }
                }

                delete[] hist;
                delete[] norm;

                return true;
            }

          private:
            int sbin_;
            


    };

    








}// namespace kurff




#endif
