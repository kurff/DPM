


#ifndef _KURFF_DETOPS_HPP_
#define _KURFF_DETOPS_HPP_

#include "Operator.hpp"
#include "tensor.h"



namespace kurff{
template<typename Context>
class DetOps: public Operator<Context>{
    public:
        DetOps(){

        }
        ~DetOps(){

        }

        bool run(){


            


        }
    private:
        
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* thresh_;
    

};

}

#endif