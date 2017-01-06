// Workspace

#include "tensor.h"
#include "Model.hpp"

template<typename Context>
class Workspace{
    public:
        typedef KurffMap<string, unique_ptr<Tensor<Context> > > TensorMap;
        typedef CaffeMap<string, unique_ptr<Model<Context> > > ModelMap;
        Workspace(){


        }

        ~Workspace(){


        }


    private:

        unique_ptr<TensorMap> tensor_map_;
        unique_ptr<ModelMap> model_map_;






};