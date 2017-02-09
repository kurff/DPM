#ifndef _KURFF_GRAPH_HPP_
#define _KURFF_GRAPH_HPP_
#include "tensor/common.hpp"
#include  <vector>
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
            }

        private:
            vector<size_t> parents_;
            vector<size_t> children_;
            size_t index_;
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

                        



        private:
            vector<Node> graph_;





    };








}






#endif