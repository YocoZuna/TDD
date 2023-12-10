add_library(Includs STATIC
 Src/LedDriver.c
)
target_link_libraries(Includs
Test)

target_include_directories(Includs PUBLIC
Test/Src
Inc

${CMAKE_CURRENT_LIST_DIR})
