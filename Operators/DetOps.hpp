


#ifndef _KURFF_DETOPS_HPP_
#define _KURFF_DETOPS_HPP_

#include "Operator.hpp"
#include "tensor.h"




template<typename Context>
class DetOps: public Operator<Context>{
    public:
        DetOps(){

        }
        ~DetOps(){

        }

    private:
        
        Tensor<Context>* input_;
        Tensor<Context>* output_;
    

}



#endif