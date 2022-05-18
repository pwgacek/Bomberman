cmake_minimum_required(VERSION 3.21)
project(bomberman)

set(CMAKE_CXX_STANDARD 20)

add_executable(bomberman src/main.cpp src/engine.cpp headers/engine.hpp src/map_elements/wall.cpp headers/map_elements/wall.hpp src/map.cpp headers/map.hpp src/bomberman.cpp headers/bomberman.hpp src/map_elements/mapelement.cpp headers/map_elements/mapelement.hpp src/map_elements/corridor.cpp headers/map_elements/corridor.hpp src/map_elements/chest.cpp headers/map_elements/chest.hpp src/bomb.cpp headers/bomb.hpp src/map_elements/explosion.cpp headers/map_elements/explosion.hpp src/gui/infobar.cpp headers/gui/infobar.hpp src/gui/gameover.cpp headers/gui/gameover.hpp src/gui/playagainbtn.cpp headers/gui/playagainbtn.hpp src/gui/playerinfo.cpp headers/gui/playerinfo.hpp)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(bomberman ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
