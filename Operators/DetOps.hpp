


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

        bool run(){


            


        }

        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){

            
        }

    private:
        
        Tensor<Context>* input_;
        Tensor<Context>* output_;
        Tensor<Context>* thresh_;
    

};



#endif