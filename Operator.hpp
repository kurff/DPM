


#ifndef _KURFF_OPERATOR_HPP_
#define _KURFF_OPERATOR_HPP_
#include <iostream>

#include "tensor/common.hpp"
#include "Operator.hpp"
#include "Parameters.hpp"
#include "tensor.h"
#include "Workspace.hpp"
#include "proto/kurff.pb.h"
#include <string.h>
using namespace std;



// Operator of model 
// 
namespace kurff{
class OperatorBase{
    public:
        OperatorBase(const OperatorDef& operator_def, Workspace* ws){

        }
        ~OperatorBase(){

        }
        
};

template<typename Context>

class Operator: public OperatorBase{
    public:
        Operator(const OperatorDef& operator_def, Workspace* ws): OperatorBase(operator_def, ws)
        , context_(operator_def.device_option()){


        }

        ~Operator(){


        }

        virtual bool setup(Tensor<Context>* input, Workspace* ws, const Parameters& para, string name) = 0;
        virtual bool run() = 0;

    protected:
        KurffMap<string, Tensor<Context> > extern_input_; // parameters of convolution
        

    private:


        Context context_;
};







}
#endif
