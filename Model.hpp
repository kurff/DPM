#ifndef _KURFF_MODEL_HPP_
#define _KURFF_MODEL_HPP_
#include <iostream>

#include "./tensor/common.hpp"
#include "Operator.hpp"
#include "tensor.h"
#include "graph/graph.hpp"
#include "Workspace.hpp"
#include "proto/kurff.pb.h"
#include "graph/node.hpp"

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

        virtual bool deserialize(string file) = 0;

        virtual bool setup(Workspace* ws, const Parameters& para) = 0;
        //virtual bool run() = 0;

        

    protected:

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

    protected:
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

        bool deserialize(string file){

            ifstream f(file.c_str(),ios::in);
            

            f.close();

            return true;
        }

        bool setup(Workspace* ws, const Parameters& para){
            ParametersBase* ptr = para["Conv"];
            
            return true;
        }


        shared_ptr<OperatorBase > get_node(int idx){
            return ops_[idx];
        }

        bool run(){
            LOG(INFO)<<"run DPM Model";
            for(size_t i = 0; i < ops_.size(); ++ i){
                if(!ops_[i]->run()){
                    LOG(INFO)<<"error";
                    return false;
                }
            }

            return true;
        }

        

    protected:
        //  the DAG model
        vector<Node> ops_;
};




} // end of namespace kurff
#endif