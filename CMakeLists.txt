cmake_minimum_required(VERSION 3.1)

project(RayTrac)

set(VECTOR_SRC RayTracing.cpp Ray.cpp Figure.cpp box.cpp .cpp Scan.cpp autotest.cpp)
set(VECTOR_HDR box.h Factorybox.h Header.h Ray.hpp )

add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})
find_package(SFML COMPONENTS graphics window system)
#target_link_libraries(${PROJECT_NAME} vector)
install (TARGETS "${PROJECT_NAME}" DESTINATION bin)	#$(CMAKE_INSTALL_PREFIX)/bin
install (FILES "${VECTOR_SRC}" DESTINATION src)  	#$(CMAKE_INSTALL_PREFIX)/src
install (FILES "${VECTOR_HDR}" DESTINATION hdr)  	#$(CMAKE_INSTALL_PREFIX)/hdr


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")