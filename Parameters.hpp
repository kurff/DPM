// Parameters of traditional features, such as HOG


#ifndef _KURFF_PARAMETERS_HPP_
#define _KURFF_PARAMETERS_HPP_
#include <iostream>

#include "./tensor/common.hpp"

using namespace std;




class Parameters{
    public:
        Parameters(){


        }

        ~Parameters(){


        }


        
        

    public:




        // HOG parameters
        int sbin_; //

        // Convolutional parameters;
        int kernel_h_;
        int kernel_w_;

        int pad_t_;
        int pad_l_;
        int pad_b_;
        int pad_r_;
        int stride_h_;
        int stride_w_;



};







#endif
