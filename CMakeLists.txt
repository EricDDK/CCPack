cmake_minimum_required (VERSION 2.6)
add_compile_options(-std=c++11)
project (CCPack)

add_library(
    pack 
    src/Binary.cpp
    src/Binary.h
    src/IPack.h
)

add_executable(
    main 
    test.cpp
)

target_link_libraries(main pack)
