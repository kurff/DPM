#ifndef _KURFF_DISTANCE_TRANSFORM_OPS_HPP_
#define _KURFF_DISTANCE_TRANSFORM_OPS_HPP_

#include "Operator.hpp"
#include "Parameters.hpp"
#include "utils/dt.hpp"
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
            

            //for(int i = 0; i < input_->dim(0);++i){
                //dt2d(input_->template);
            //}



            
            return true;
        }

        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){

            ar & weight_;
            ar & anchor_;

            
        }


    private:
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* weight_;
        Tensor<Context>* anchor_;

        


        




};

#endif