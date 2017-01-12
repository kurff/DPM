

#ifndef _KURFF_CONVOPS_HPP_
#define _KURFF_CONVOPS_HPP_

#include "../Operator.hpp"
#include "../Parameters.hpp"
#include "../utils/"
#include "tensor.h"


template<typename Context>
class ConvOps: public Operator<Context>{
    public:
        ConvOps(){

        }
        ~ConvOps(){

            
        }

        bool setup(Tensor<Context>* input, const Parameters& para, string name){
            input_ = input;
            conv_para_ = para.conv_params_[name];

            // create output 

            // create input_col 

            




            
            return true;
        }
        bool run(){


            return true;
        }

    private:
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* input_col_;

        ConvParameters conv_para_;


        




};

#endif