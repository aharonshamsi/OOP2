cmake_minimum_required (VERSION 3.26)

project (oop2_ex01)
set (MY_AUTHORS "aharon_moshe_shamsian-akiva_moshe_sudranski")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
if (NOT MSVC)
    target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
endif()

add_subdirectory (include)
add_subdirectory (src)

include (cmake/Zip.cmake)
