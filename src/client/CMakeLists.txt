add_executable(client main.cpp)

target_include_directories(client PUBLIC ../../includes)
target_compile_features(client PUBLIC cxx_std_14)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/includes/"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
