#ifndef __KURFF_CORE_TYPES_H__
#define __KURFF_CORE_TYPES_H__

#include <string>

namespace kurff {

// Storage orders that are often used in the image applications.
enum StorageOrder {
  UNKNOWN = 0,
  NHWC = 1,
  NCHW = 2,
};

inline StorageOrder StringToStorageOrder(const string& str) {
  if (str == "NHWC") {
    return StorageOrder::NHWC;
  } else if (str == "NCHW") {
    return StorageOrder::NCHW;
  } else {
    return StorageOrder::UNKNOWN;
  }
}

}  // namespace kurff

#endif  // KURFF_CORE_TYPES_H_
