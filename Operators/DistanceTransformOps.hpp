#ifndef _KURFF_DISTANCE_TRANSFORM_OPS_HPP_
#define _KURFF_DISTANCE_TRANSFORM_OPS_HPP_

#include "../Operator.hpp"
#include "../Parameters.hpp"
#include "../utils/"
#include "tensor.h"


// Distance Transform
template<typename Context>
class DTOps: public Operator<Context>{
    public:
        DTOps(){

        }
        ~DTOps(){

            
        }

        bool setup(Tensor<Context>* input, const Parameters& para, string name){
            
            input_ = input;
            

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
        Tensor<Context>* weight_;

        


        




};

#endif