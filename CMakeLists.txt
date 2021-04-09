#[[
  work in progress
]]
cmake_minimum_required(VERSION 3.20)

project(SDL2Test)
set(ENTRYPOINT SDL2Window.cpp)

set(BUILDTOOLS E:/devbuilds)


#if (WIN32)
#  message("BUILD WIN32")
#endif()
#message("OS BIT ${CMAKE_GENERATOR}") #nope
#message("OS BIT ${CMAKE_GENERATOR_PLATFORM}") #nope
#message("OS BIT ${CMAKE_SIZEOF_VOID_P}") #ok
#if (CMAKE_HOST_WIN32)
  #set(WINDOWS 1)
  #message("BUILD WIN32")
#elseif(CMAKE_HOST_APPLE)
  #set(MACOS 1)
  #message("BUILD MACOS")
#elseif(CMAKE_HOST_UNIX)
  #set(LINUX 1)
  #message("BUILD LINUX")
#endif()
#message("CDIR: ${CMAKE_CURRENT_LIST_DIR}")
message("~~~ SDL2 BUILD! ~~~")
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  # 64 bits
  message("~ 64 BITS ~")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  # 32 bits
  message("~ 32 BITS ~")
endif()
#message("CMAKE_CPU_ARCHITECTURES:${CMAKE_CPU_ARCHITECTURES}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

#module > cmake > FindSDL2.cmake
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
#current module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
#module config
find_package(SDL2 REQUIRED)
#set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
#set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")




set(SDL2_TTF E:/devbuilds/SDL2_ttf-2.0.15/include)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF})

#add_executable(SDL2Test main.cpp)
add_executable(SDL2Test ${ENTRYPOINT})

set(SDL2_TTF_LIB E:/devbuilds/SDL2_ttf-2.0.15/lib/x64/SDL2_ttf.lib)

target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_TTF_LIB})

message("PROJECT_NAME:${PROJECT_NAME}")
message("PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")
message("PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
#message("TARGET_FILE:${TARGET_FILE}") #nope
#message("SDL2_LIBRARIES:${SDL2_LIBRARIES}")

set(OUTPUTDIR "${PROJECT_SOURCE_DIR}/bin/${PROJECT_NAME}.exe")

set(SDL2DLL "${PROJECT_SOURCE_DIR}/lib/x64/SDL2.dll")
set(SDL2DLLBIN "${PROJECT_SOURCE_DIR}/bin/SDL2.dll")
#[[
  debug/release build to current dir to bin
]]

message("TARGET_FILE_DIR: ${TARGET_FILE_DIR}")

add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SDL2Test> ${OUTPUTDIR}
  COMMENT "Copying ${PROJECT_NAME} binary output to ${OUTPUTDIR}"
)
add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${SDL2DLL} ${SDL2DLLBIN}
  COMMENT "Copying ${SDL2DLL} output to ${SDL2DLLBIN}"
)

#FONT
set(FONT "${PROJECT_SOURCE_DIR}/font")
set(FONT_BIN "${PROJECT_SOURCE_DIR}/bin/font")
add_custom_target(copy-files-font ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${FONT}
    ${FONT_BIN}
)
#add_custom_command(
  #TARGET ${PROJECT_NAME}
  #POST_BUILD
  #COMMAND ${CMAKE_COMMAND} -E copy ${FONT} ${FONT_BIN}
  #COMMENT "Copying ${FONT} output to ${FONT_BIN}"
#)

set(SDL2_TTF_DLL "${BUILDTOOLS}/SDL2_ttf-2.0.15/lib/x64")
set(SDL2_TTF_DLL_BIN "${PROJECT_SOURCE_DIR}/bin")

message("BUILD DIR: ${BUILDTOOLS}")

add_custom_target(copy-files-ttf ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SDL2_TTF_DLL}
    ${SDL2_TTF_DLL_BIN}
)

#add_custom_command(
  #TARGET ${PROJECT_NAME}
  #POST_BUILD
  #COMMAND ${CMAKE_COMMAND} -E copy ${SDL2_TTF_DLL} ${SDL2_TTF_DLL_BIN}
  #COMMENT "Copying ${SDL2_TTF_DLL} output to ${SDL2_TTF_DLL_BIN}"
#)

#configure_file(
  #${SDL2_TTF_DLL} 
  #${SDL2_TTF_DLL_BIN}
  #COPYONLY
#)

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/yourFolder/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/yourFolder/)

#add_custom_command(
        #TARGET foo POST_BUILD
        #COMMAND ${CMAKE_COMMAND} -E copy
                #${CMAKE_SOURCE_DIR}/test/input.txt
                #${CMAKE_CURRENT_BINARY_DIR}/input.txt)


#[[

]]
#install(TARGETS SDL2Test
  #CONFIGURATIONS Debug
  #DESTINATION ${PROJECT_BINARY_DIR}/bin
#)
#add_custom_command(
#  TARGET SDL2Test
#  POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E echo bin=${build_dir}/${PROJECT_BIN}
#  COMMENT "Copying SDL2Test binary output to SomeFolder"
#)
#install (FILES "${PROJECT_SOURCE_DIR}/platforms/win/DynamsoftBarcodeReaderx86.dll" DESTINATION bin)
#install(TARGETS SDL2Test DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)
#install(TARGETS SDL2Test DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)
#install (FILES "${PROJECT_BINARY_DIR}/BarcodeReaderConfig.h" DESTINATION include)
#install (DIRECTORY "${PROJECT_SOURCE_DIR}/include" DESTINATION include)
