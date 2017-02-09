// common.hpp
#ifndef _KURFF_COMMON_HPP_
#define _KURFF_COMMON_HPP_
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

// seralization with vector
//#include <boost/archive/>
#include <boost/serialization/vector.hpp>

#include <math.h>
#include <memory>
#include <string>
#include <map>
#include <vector>





namespace kurff{
    #define	round(x)	((x-floor(x))>0.5 ? ceil(x) : floor(x))
    #define float_eps 0.0001
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