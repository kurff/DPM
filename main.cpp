#include "Feature.hpp"
#include "tensor.h"
using namespace kurff;



int main(int argc, char* argv[]){
    Tensor<CPUContext>* input = new Tensor<CPUContext>();
    int height = 100, width = 100;
    vector<int> dims{height,width,3};
    input->Reshape(dims);

    Feature<CPUContext>* feature = new HOGFeature<CPUContext>();
    feature->set_input(input);
    feature->initial();
    feature->run();
}