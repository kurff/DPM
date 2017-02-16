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
        size_t type_;
        string name_;
        

    public:
        ConvParameters():(){

        }



};

class HOGParameters: public ParametersBase{
    public:

    int sbin_; // HOG parameters
    string name_;
    size_t type_;
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
