


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
        virtual bool seralize()  = 0;
        virtual bool deseralize() = 0;

        

        

    private:
        Context context_;
};








#endif
