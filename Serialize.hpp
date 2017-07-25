#include "tensor.h"
#include "proto/kurff.pb.h"
#include <string>
#include <google/protobuf/repeated_field.h>

namespace kurff{


class Serialize{
    typedef google::protobuf::RepeatedField<float> Field;
    public:
        Serialize(){


        }
        ~Serialize(){


        }
        template<typename T, class SrcContext, class DstContext>
        void serialize(T* t, Field* field, std::string name){
            int size = t->size();
            field->Reserve(size);
            for(int i = 0; i < size; ++ i){
                field->Add(0);
            }
            //CHECK_EQ(t->meta().name(),"f");
            //LOG(INFO)<<t->meta().name();
            const float* src = t->template data<float>();
            float* dst = field->mutable_data();
            SrcContext context;
            context.template Copy<float,SrcContext,DstContext>(size, src, dst);

            //LOG(INFO)<<field->SerializeAsString();






        }
    protected:

        
};







}