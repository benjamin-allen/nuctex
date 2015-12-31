cmake_minimum_required(VERSION 2.6)
project(nuctex C CXX)
aux_source_directory(src/ NuCTex_src)
add_executable(nuctex ${NuCTex_src})
