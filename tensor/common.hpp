// common.hpp
#ifndef _KURFF_COMMON_HPP_
#define _KURFF_COMMON_HPP_


// seralization with vector
//#include <boost/archive/>


#include <math.h>
#include <memory>
#include <string>
#include <map>
#include <vector>





namespace kurff{

    template<typename T>
    inline T round(T x){
        return ((x-floor(x))>0.5 ? ceil(x) : floor(x));
    }
    
    #define float_eps 0.000001
    template<typename T>
    static inline T min(T x, T y) { return (x <= y ? x : y); }
    template<typename T>
    static inline T max(T x, T y) { return (x <= y ? y : x); }

    template <typename Key, typename Value>
    using kurffMap = std::map<Key, Value>;
    using std::string;
    using std::unique_ptr;
    using std::vector;

};



#endif