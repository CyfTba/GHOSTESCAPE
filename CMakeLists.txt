cmake_minimum_required(VERSION 3.10)
project(GHOSTESCAPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

#根据操作系统设置文件名称
set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/affiliate SRC_AFFILIATE)
set(SRC ${SRC} ${SRC_AFFILIATE})
#引入头文件目录和库文件目录
include_directories(${CMAKE_SOURCE_DIR}/SDL3/include/)
link_directories(${CMAKE_SOURCE_DIR}/SDL3/lib/)

include_directories(${CMAKE_SOURCE_DIR}/glm/include/)
link_directories(${CMAKE_SOURCE_DIR}/glm/lib/)

add_executable(${TARGET} ${SRC})

target_link_libraries(${TARGET} SDL3 SDL3_image SDL3_mixer SDL3_ttf glm)

if(MINGW)
    target_link_options(${TARGET} PRIVATE "-mwindows")

endif()