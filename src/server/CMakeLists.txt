add_executable(server main.cpp)

target_include_directories(server PUBLIC ../../includes)
target_compile_features(server PUBLIC cxx_std_14)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/includes"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
