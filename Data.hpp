// Data
#ifndef _KURFF_DATA_HPP_
#define _KURFF_DATA_HPP_

#include "tensor/common.hpp"

#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace kurff
{
    class Box{
        public:

            Box():x0_(0),y0_(0),x1_(0),y1_(0),h_(0),w_(0),confidence_(0),obj_name_(""),file_(""),type_(0),cls_(0),key_(0){

            }
            ~Box(){


            }
            friend class boost::serialization::access;  
  
            template<class Archive>  
            void serialize(Archive& ar, const unsigned int version)  
            {  
                ar & x0_;  
                ar & y0_;
                ar & x1_;
                ar & y1_;
                ar & h_;
                ar & w_;
                ar & confidence_; // the confidence of the output;
                ar & obj_name_;   // the class name of this box;
                ar & file_; // the file path of image for this box
                ar & type_; // the type of this box
                ar & cls_;  // the class of this box
                ar & key_;  // the key of box, used for retrival dataset
            } 



        public:
            int x0_;
            int y0_;
            int x1_;
            int y1_;
            int h_;
            int w_;
            float confidence_;
            string obj_name_;
            string file_;
            int type_;
            int cls_;
            size_t key_; 
    };

    class Anotation{
        public:
            Anotation(){

            }
            ~Anotation(){


            }

            void deserialize(string file){
                ifstream f(file, ios::in);
                Box box;
                f >> file_;
                boxes_.clear();
                while(f >> box.x0_ >> box.y0_ >> box.x1_ >> box.y1_ >> box.obj_name_ >> box.cls_){
                    boxes_.push_back(box);
                }

                f.close();
            }


        private:
            string file_; // the full path of image
            vector<Box> boxes_;
    };


    
    // training data;
    // test data
    // validation data
    class Data{

        public:
            Data(){

            }

            ~Data(){


            }


        private:
            vector<Anotation> anotations_;

         
        



    };




}

#endif