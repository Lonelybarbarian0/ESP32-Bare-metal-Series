# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/kailas/esp/esp-idf/components/bootloader/subproject"
  "/home/kailas/Desktop/tick/build/bootloader"
  "/home/kailas/Desktop/tick/build/bootloader-prefix"
  "/home/kailas/Desktop/tick/build/bootloader-prefix/tmp"
  "/home/kailas/Desktop/tick/build/bootloader-prefix/src/bootloader-stamp"
  "/home/kailas/Desktop/tick/build/bootloader-prefix/src"
  "/home/kailas/Desktop/tick/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/kailas/Desktop/tick/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/kailas/Desktop/tick/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
