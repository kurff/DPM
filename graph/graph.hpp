#ifndef _KURFF_GRAPH_HPP_
#define _KURFF_GRAPH_HPP_
#include "tensor/common.hpp"
#include "Operator.hpp"
#include  <vector>
#include <string>
#include <fstream>
#include "glog/logging.h"
using namespace std;
namespace kurff{
    //template<typename VerticeD>
    class Node{
        public:
            Node(){

            }
            ~Node(){

            }

            friend class boost::serialization::access;

            template<class Archive>
            void serialize(Archive& ar, const unsigned int version){
                ar & parents_;
                ar & children_;
                ar & index_;
                ar & device_;
            }

        private:
            vector<size_t> parents_;
            vector<size_t> children_;
            size_t index_;
            shared_ptr<OperatorBase> op_;
            int state_; // indicate the state of computations
            int device_;
    };


    // graph is an instanization of model
    template<typename Model>
    class Graph{
        public:

            const Model& model_;


            Graph(string config, Model model):config_(config),model_(model){


            }

            ~Graph(){


            }

            friend class boost::serialization::access;

            template<class Archive>
            void serialize(Archive& ar, const unsigned int version){
                ar & graph_;
                //ar & children_;
                //ar & index_;
            }


            size_t get_number_vertices(){return graph_.size();}
            Node get_node(size_t idx){return graph_[idx];}
            
            // setup a graph
            // load graph configuration and setup the graph
            bool setup(){
                ifstream fin(config_,ios::in);
                if(!fin.is_open()){
                    LOG(INFO)<<"can not open config "<<config_;
                    return false;
                }

                


                fin.close();



                return true;
            }
            
            // partion operation of graph into several group
            // 

            void partition(){


            }

            



        private:
            vector<Node> graph_;
            string config_;
            
                  




    };








}






#endif