

#ifndef _KURFF_CONVOPS_HPP_
#define _KURFF_CONVOPS_HPP_

#include "Operator.hpp"
#include "Parameters.hpp"
#include "utils/math.h"
#include "tensor.h"
#include "Workspace.hpp"


template<typename Context>
class ConvOps: public Operator<Context>{
    public:
        ConvOps(){

        }
        ~ConvOps(){

            
        }

        bool setup(Tensor<Context>* input, Workspace* ws, const Parameters& para, string name){
            input_ = input;
            conv_para_ = para.conv_params_[name];

            int channels = input_->dims()[3];
            int height = input_->dims()[1];
            int width = input_->dims()[2];
            // calculate the shape of input_col
            
            int h = (height + conv_para_.pad_b_ 
            + conv_para_.pad_b_ - conv_para_.kernel_h_) / conv_para_.stride_h_;
            
            int w = (width + conv_para_.pad_l_ + conv_para_.pad_r_
            -conv_para_.kernel_w_)/conv_para_.stride_w_;

            int height_col = h*w;
            int width_col = conv_para_.kernel_h_*conv_param_.kernel_w_*
            conv_para_.kernel_d_;

            input_col_ = ws->create(string("input_col_")+name);

            


            // calculate the shape of output


            // create output 
            


            // create input_col 







            
            return true;
        }
        bool run(){
            int channels = input_->dims()[3];
            int height = input_->dims()[1];
            int width = input_->dims()[2];

            math::Im2col<float, Context, StorageOrder::NHWC>(input_->template data<float>(), 
            channels, 
            height,
            width, 
            conv_para_.kernel_h_, 
            conv_para_.kernel_w_,
            conv_para_.pad_t_, 
            conv_para_.pad_l_, 
            conv_para_.pad_b_, 
            conv_para_.pad_r_,
            conv_para_.stride_h_, 
            conv_para_.stride_w_, 
            input_col_->template mutable_data<float>(),
            &context_);

            math::Gemm<float, Context>(CBLAS_TRANSPOSE TransA,
            CBLAS_TRANSPOSE TransB,
            M, N, K, alpha, 
            const T* A, const T* B, const T beta, T* C, &context);
            
            math::Col2im(input_col_->template data<float>(), 
            channels,
            height, 
            width, 
            patch_h, 
            patch_w,
            pad_t, 
            pad_l, 
            pad_b, 
            pad_r,
            stride_h, 
            stride_w, output_->template mutable_data<float>(),
            &context_);


            return true;
        }


        bool deseralize(){

            return true;
        }

        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & kernel_;
            ar & bias_;
        }

    private:
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* input_col_;
        Tensor<Context>* kernel_; //w
        Tensor<Context>* bias_; //b

        ConvParameters conv_para_;
        

        




};

#endif