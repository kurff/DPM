// Data
#ifndef _KURFF_DATA_HPP_
#define _KURFF_DATA_HPP_

#include "tensor/common.hpp"


#include <string>
using namespace std;

namespace kurff
{
    class Box{
        public:
            Box(){

            }
            ~Box(){


            }
        

        public:
            int x0_;
            int y0_;
            int x1_;
            int y1_;
            int h_;
            int w_;
            float confidence_;
            string name_;
            int type_;




    };

    

    class Data{
        
        



    };
}

#endif