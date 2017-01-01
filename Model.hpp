#ifndef _KURFF_MODEL_HPP_
#define _KURFF_MODEL_HPP_
#include <iostream>

#include "./tensor/common.hpp"

using namespace std;




class Model{
    public:
        Model(){


        }

        ~Model(){


        }

        virtual bool read() = 0;
        virtual bool run() = 0;
        

    private:

};




class HOGModel:public Model{
    public:
        HOGModel(){
            
        }
        ~HOGModel(){


        }

    private:



};


#endif