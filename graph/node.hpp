#ifdef _KURFF_NODE_HPP_
#define _KURFF_NODE_HPP_

#include "tensor/common.hpp"
#include "Operator.hpp"
#include  <vector>
#include <string>
#include <fstream>
#include "glog/logging.h"


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
                ar & state_;
                ar & op_;
            }

        private:
            vector<size_t> parents_;
            vector<size_t> children_;
            size_t index_;
            shared_ptr<OperatorBase> op_;
            int state_; // indicate the state of computations
            int device_;
    };



}



#endif 



