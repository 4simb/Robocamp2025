add_executable(rockpaperscissors main.cpp)

target_include_directories(rockpaperscissors PUBLIC ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(rockpaperscissors unit)