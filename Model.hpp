#ifndef _KURFF_MODEL_HPP_
#define _KURFF_MODEL_HPP_
#include <iostream>

#include "./tensor/common.hpp"
#include "Operator.hpp"
#include "tensor.h"
#include "graph/graph.hpp"
#include "Workspace.hpp"
#include "Parameters.hpp"

#include <vector>
using namespace std;

namespace kurff{

template <typename Context>
class Model{
    public:
        Model(){


        }

        ~Model(){


        }

        virtual bool deserialize() = 0;
        virtual bool setup(Workspace* ws, const Parameters& para) = 0;
        //virtual bool run() = 0;

        

    private:

        vector<shared_ptr< OperatorBase >  >  ops_;
        vector<int> devices_;

};



template <typename Context>
class HOGModel:public Model<Context>{
    public:
        HOGModel(){
            
        }
        ~HOGModel(){


        }

        bool deserialize(){

            return true;
        }
        bool setup(Workspace* ws, const Parameters& para){

            
            return true;
        }
        //bool run(){}

    private:
        Tensor<Context>* filters_;
        Tensor<Context>* bias_;
    
    
};

template <typename Context>
class DPModel{
    public:
        DPModel(){

        }

        ~DPModel(){


        }

        bool setup(Workspace* ws, const Parameters& para){

            return true;
        }


    private:
        Tensor<Context>* filters_;
        Tensor<Context>* defs_;
        Tensor<Context>* anchors_;
        Tensor<Context>* bias_;
};




} // end of namespace kurff
#endif