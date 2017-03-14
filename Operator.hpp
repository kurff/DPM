


#ifndef _KURFF_OPERATOR_HPP_
#define _KURFF_OPERATOR_HPP_
#include <iostream>

#include "./tensor/common.hpp"
#include "Operator.hpp"
#include "Parameters.hpp"
#include "tensor.h"
#include "Workspace.hpp"
using namespace std;



// Operator of model 
// 

class OperatorBase{
    public:
        OperatorBase(){

        }
        ~OperatorBase(){

        }
        

                //ar & graph_;
                //ar & children_;
                //ar & index_;

        



};

template<typename Context>

class Operator: public OperatorBase{
    public:
        Operator(){


        }

        ~Operator(){


        }

        virtual bool setup(Tensor<Context>* input, Workspace* ws, const Parameters& para, string name) = 0;
        virtual bool run() = 0;
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version) = 0;
        virtual bool deseralize() = 0;

        

        

    private:
        Context context_;
};








#endif
