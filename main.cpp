#include "Feature.hpp"
#include "tensor/context.h"
#include "tensor.h"
using namespace kurff;
int main(int argc, char* argv[]){
    Tensor<CPUContext>* input = new Tensor<CPUContext>();
    int height = 100, width = 100;
    vector<int> dims{height,width,3};
    input->Reshape(dims);

    Feature* feature = new Feature();
    feature->set_input(input);
    feature->init();
    feature->run();




}