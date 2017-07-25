#include "gtest/gtest.h"
#include "tensor.h"
#include "Feature.hpp"
#include "glog/logging.h"
#include "proto/kurff.pb.h"
#include "Serialize.hpp"
//#include "Operators/ConvOps.hpp"
using namespace kurff;
TEST(case1, test){

    Tensor<CPUContext>* input = new Tensor<CPUContext>();
    int height = 2, width = 3;
    vector<int> dims{1,3,height,width};
    input->Reshape(dims);
    for(int i = 0; i < input->size(); ++i){
        input->mutable_data<float>()[i] = i;
    }
    
    LOG(INFO)<< input->DebugString();
    
    TensorProto tensor_proto;
    Serialize* seralize = new Serialize();
    tensor_proto.set_name("input");
    seralize->serialize<Tensor<CPUContext>, CPUContext, CPUContext>(input, tensor_proto.mutable_data(),"input" );

    string content = tensor_proto.SerializeAsString();
    LOG(INFO)<< content;
    TensorProto tensor;
    tensor.ParseFromString(content);
    for(int i = 0; i < input->size(); ++ i){
        CHECK_EQ(tensor.mutable_data()->mutable_data()[i],i);
    }
    
}