#ifndef _KURFF_MODEL_HPP_
#define _KURFF_MODEL_HPP_
#include <iostream>

#include "./tensor/common.hpp"
#include "Operator.hpp"
#include "tensor.h"

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
        virtual bool run() = 0;
        

    private:

        vector<shared_ptr< Operator >  >  ops_;

};



template <typename Context>
class HOGModel:public Model<Context>{
    public:
        HOGModel(){
            
        }
        ~HOGModel(){


        }

    private:
    
    
};

template <typename Context>
class DPModel{
    public:
        DPModel(){

        }

        ~DPModel(){


        }

    private:
        Tensor<Context>* filters_;
        Tensor<Context>* defs_;
        Tensor<Context>* anchors_;
        


};


} // end of namespace kurff
#endif