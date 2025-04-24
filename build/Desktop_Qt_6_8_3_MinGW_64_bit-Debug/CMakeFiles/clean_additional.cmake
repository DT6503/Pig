# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Pig_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Pig_autogen.dir\\ParseCache.txt"
  "Pig_autogen"
  )
endif()
