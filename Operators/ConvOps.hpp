

#ifndef _KURFF_CONVOPS_HPP_
#define _KURFF_CONVOPS_HPP_

#include "Operator.hpp"
#include "utils/math.h"
#include "tensor.h"
#include "Workspace.hpp"

#include "../proto/kurff.pb.h"


template<typename Context>
class ConvOps: public Operator<Context>{
    public:
        ConvOps(){

        }
        ~ConvOps(){

            
        }

        bool setup(Tensor<Context>* input, Workspace* ws, const Parameters& para){
            input_ = input;
            

            int channels = input_->dims()[3];
            int height = input_->dims()[1];
            int width = input_->dims()[2];
            // calculate the shape of input_col
            conv_param_ = param.conv_parameters();
            int pad_b = conv_param_.pad_b();
            int pad_l = conv_param_.pad_l();
            int pad_r = conv_param_.pad_r();
            int kernel_h = conv_param_.kernel_h();
            int kernel_w = conv_param_.kernel_w();
            int kernel_d = conv_param_.kernel_d();
            int stride_h = conv_param_.stride_h();
            int stride_w = conv_param_.stride_w();
            int h = (height + pad_b + pad_b - kernel_h) / stride_h;            
            int w = (width + pad_l + pad_r-kernel_w)/stride_w;
            int height_col = h*w;
            int width_col = kernel_h*kernel_w*kernel_d;

            input_col_ = ws->create(string("input_col_")+name);
            input_col_->Reshape(vector<int>{height_col, width_col});
            // calculate the shape of output

            int oh = (height - kernel_h) / stride_h;
            int ow = (width - kernel_w ) / stride_w;
            int on = kernel_->dims()[0];

            output_ = ws->create(string("output_")+name);
            output_ ->Reshape(vector<int>(on,oh,ow));


            // create output 
            


            // create input_col 







            
            return true;
        }
        bool run(){

            int channels = input_->dims()[3];
            int height = input_->dims()[1];
            int width = input_->dims()[2];

            

            int pad_b = conv_param_.pad_b();
            int pad_l = conv_param_.pad_l();
            int pad_r = conv_param_.pad_r();
            int pad_t = conv_param_.pad_t();
            int kernel_h = conv_param_.kernel_h();
            int kernel_w = conv_param_.kernel_w();
            int kernel_d = conv_param_.kernel_d();
            int stride_h = conv_param_.stride_h();
            int stride_w = conv_param_.stride_w();


            math::Im2col<float, Context, StorageOrder::NHWC>(input_->template data<float>(), 
            channels, 
            height,
            width, 
            kernel_h, 
            kernel_w,
            pad_t, 
            pad_l, 
            pad_b, 
            pad_r,
            stride_h, 
            stride_w, 
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




    private:
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* input_col_;
        Tensor<Context>* kernel_; //w
        Tensor<Context>* bias_; //b
        ConvParameters conv_param_;
        //ConvParameters conv_para_;
        

        




};

#endif