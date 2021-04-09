#message("CDIR: ${CMAKE_CURRENT_LIST_DIR}")
set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

message("SUB BUILDTOOLS: ${BUILDTOOLS}")

#message("bit builds: ${CMAKE_SIZEOF_VOID_P}")
# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  #message("build x64")
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
else ()
  #message("build x86")
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
endif ()