


#ifndef _KURFF_OPERATOR_HPP_
#define _KURFF_OPERATOR_HPP_
#include <iostream>

#include "./tensor/common.hpp"

using namespace std;



// Operator of model 
// 

template<typename Context>

class Operator{
    public:
        Operator(){


        }

        ~Operator(){


        }

        virtual bool setup() = 0;
        virtual bool run() = 0;

        

        

    private:

};








#endif
