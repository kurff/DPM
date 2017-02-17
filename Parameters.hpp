// Parameters of traditional features, such as HOG


#ifndef _KURFF_PARAMETERS_HPP_
#define _KURFF_PARAMETERS_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "./tensor/common.hpp"
#include "tensor/common.hpp"


using namespace std;




namespace kurff{

enum TypeParam{
    CONV =1,
    HOG=2,

};



class ParametersBase{
    public:
        ParametersBase(){

        }
        ~ParametersBase(){

        }

};

class ConvParameters:public ParametersBase{
    public:
        int kernel_h_;
        int kernel_w_;
        int kernel_d_;

        int pad_t_;
        int pad_l_;
        int pad_b_;
        int pad_r_;
        int stride_h_;
        int stride_w_;
        TypeParam type_;
        string name_;
        

    public:
        ConvParameters(string name):name_(name),type_(CONV){

        }



};

class HOGParameters: public ParametersBase{
    public:
        int sbin_; // HOG parameters
        string name_;
        TypeParam type_;

    public:
        HOGParameters(string name):name_(name),type_(HOG){

        }

};




class Parameters{
    public:
        Parameters(){


        }

        ~Parameters(){


        }


        

        
        

    public:
        // Convolutional parameters;
        map<string,ParametersBase*> params_;
        
        




};





} // end of namespace kurff

#endif
