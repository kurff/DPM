#ifndef _KURFF_GRAPH_HPP_
#define _KURFF_GRAPH_HPP_
#include "tensor/common.hpp"
#include "Operator.hpp"
#include  <vector>
#include <string>
#include <fstream>
using namespace std;
namespace kurff{
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
            shared_ptr<OperatorBase> ops_;
            int state_; // indicate the state of computations
            int device_;
    };


    class Graph{
        public:
            Graph(){


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

                
                return true;
            }
            
            // partion operation of graph into several group
            // 

            void partition(){


            }

            



        private:
            vector<Node> graph_;
            




    };








}






#endif