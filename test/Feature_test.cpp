#include "gtest/gtest.h"
#include "../tensor.h"
#include "../Feature.hpp"
#include "glog/logging.h"
#include "../proto/kurff.pb.h"
using namespace kurff;
TEST(case1, test){

    Tensor<CPUContext>* input = new Tensor<CPUContext>();
    int height = 100, width = 100;
    vector<int> dims{1,3,height,width};
    input->Reshape(dims);

    CHECK_EQ(input->dims()[0], 1);
    CHECK_EQ(input->dims()[1], 3);
    CHECK_EQ(input->dims()[2],100);
    CHECK_EQ(input->dims()[3],100);
    Feature<CPUContext>* feature = new HOGFeature<CPUContext>();
    //CHECK_EQ(feature, 0);
    //CHECK_NOTNULL(feature);
    
    Parameters param;
    feature->set(param);
    feature->set_input(input);
    //feature->initial();
    feature->run();

}
// TEST(case2, test){
//     EXPECT_EQ(1, 1);
// }