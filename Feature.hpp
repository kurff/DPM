
// kurff detection 
// 30-12-2016
#ifndef _KURFF_FEATURE_HPP_
#define _KURFF_FEATURE_HPP_

#include "./tensor/common.hpp"
#include "Parameters.hpp"
#include <iostream>


namespace kurff{

    template<typename Context>
    class Feature{
        public:

            Feature(){


            }
            
            ~Feature(){


            }

            //set parameters
            
            virtual bool set(const Parameters& para) = 0;

            virtual bool initial() = 0;

            virtual bool run() = 0;

            //virtual bool destroy() = 0;

            
            

        private:



    };

    template<typename Context>
    class HOGFeature: public Feature{
        public:
            HOGFeature(){

            }
            ~HOGFeature(){

            }

            bool set(const Parameters& para){
                sbin_ =  para.sbin_;     
                return true;
            }
            bool initial(){

                return true;
            }
            bool run(){
                float uu[9] = {1.0000,0.9397,0.7660,0.500,0.1736,-0.1736,-0.5000,-0.7660,-0.9397};
                float vv[9] = {0.0000,0.3420,0.6428, 0.8660, 0.9848, 0.9848, 0.8660, 0.6428, 0.3420};
                
                


                
                return true;
            }

        private:
            int sbin_;



    };










}// namespace kurff




#endif
