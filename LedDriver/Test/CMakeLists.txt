add_library(Test STATIC
Src/RunTimeErrorStub.c

)

target_include_directories(Test PUBLIC
Inc
Includs
${CMAKE_CURRENT_LIST_DIR})


