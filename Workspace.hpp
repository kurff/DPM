// Workspace

#include "tensor.h"
#include "Model.hpp"
#include <string>
using namespace std;

template<typename Context>
class Workspace{
    public:
        typedef KurffMap<string, unique_ptr<Tensor<Context> > > TensorMap;
        typedef CaffeMap<string, unique_ptr<Model<Context> > > ModelMap;
        Workspace():tensor_map_(new TensorMap ()){


        }

        ~Workspace(){


        }

        Tensor<Context> *get(const string &name){
            if (!HasBlob(name)){
                LOG(INFO) << "Blob " << name << " not in the workspace.";
                return nullptr;
            }
            else
            {
                return (*tensor_map_)[name].get();
            }
        }

        Tensor<Context>* create(const string& name) {
            if (HasBlob(name)) {
                LOG(INFO)  << "Tensor " << name << " already exists. Skipping.";
            } else {
                LOG(INFO) << "Creating tensor " << name;
                (*tensor_map_)[name] = unique_ptr<Tensor<Context> >(new Tensor<Context> ());
            }
            return (*tensor_map_)[name].get();
        }

        Model<Context>* get_model(const string & name){
            if (!HasModel(name)){
                LOG(INFO) << "Model " << name << " not in the workspace.";
                return nullptr;
            }
            else
            {
                return (*model_map_)[name].get();
            }

        }

        Model<Context>* create_model(const string& name){
            if (HasModel(name)) {
                LOG(INFO)  << "Model " << name << " already exists. Skipping.";
            } else {
                LOG(INFO) << "Creating Model " << name;


                if(strcmp(name,"HOG")){
                    (*model_map_)[name] = unique_ptr<Model<Context> >(new HOGModel<Context> ());
                }else if(strcmp(name,"DPM")){
                    
                }else{

                }
            }
            return (*model_map_)[name].get();

        }


    public:

        inline bool HasBlob(const string& name) const {
            return tensor_map_->count(name);
        }

        inline bool HasModel(const string& name) const {
            return model_map_->count(name);
        }


    private:

        unique_ptr<TensorMap> tensor_map_;
        unique_ptr<ModelMap> model_map_;






};