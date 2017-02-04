#ifndef _KURFF_MODEL_HPP_
#define _KURFF_MODEL_HPP_
#include <iostream>

#include "./tensor/common.hpp"
#include "Operator.hpp"


#include <vector>
using namespace std;



template <typename Context>
class Model{
    public:
        Model(){


        }

        ~Model(){


        }

        virtual bool deserialize() = 0;
        virtual bool run() = 0;
        

    private:

        vector<shared_ptr< Operator >  >  ops_;

};



template <typename Context>
class HOGModel:public Model<Context>{
    public:
        HOGModel(){
            
        }
        ~HOGModel(){


        }

    private:
    
        



};


#endif