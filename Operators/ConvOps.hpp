

#ifndef _KURFF_CONVOPS_HPP_
#define _KURFF_CONVOPS_HPP_

#include "../Operator.hpp"
#include "tensor.h"


template<typename Context>
class ConvOps: public Operator<Context>{
    public:
        ConvOps(){

        }
        ~ConvOps(){

            
        }

        bool setup(){
            
            return true;
        }
        bool run(){

            return true;
        }

    private:
        Tensor<Context>* input_;
        Tensor<Context>* output_;

        




};

#endif