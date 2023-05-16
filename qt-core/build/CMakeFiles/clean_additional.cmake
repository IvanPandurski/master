# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qt-core_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qt-core_autogen.dir\\ParseCache.txt"
  "qt-core_autogen"
  )
endif()
