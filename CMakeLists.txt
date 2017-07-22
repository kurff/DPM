project(Feature)
set (CMAKE_CXX_STANDARD 11)


#LINK_DIRECTORIES
link_directories(/usr/local/lib/)
include_directories(/usr/local/include/)
add_executable(Demo main.cpp ./proto/kurff.pb.cc)

target_link_libraries(Demo protobuf glog)
enable_testing()
add_executable(Feature_test ./test/Feature_test.cpp ./proto/kurff.pb.cc)
target_link_libraries(Feature_test gtest gtest_main glog protobuf)

