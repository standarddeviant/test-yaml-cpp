
#include "yaml-cpp/emitter.h"
// #include "yaml-cpp/parser.h"
#include "yaml-cpp/yaml.h"

#include <fstream>
#include <iostream>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(X) (sizeof(X) / sizeof(X[0]))
#endif

char *c_str_arr[] = {
    "FIRST_ONE",
    "SECOND_THANG",
    "THIRD_THINGER",
    "FOURTH_MABOB",
};

std::string str_arr[] = {
    "FIRST_ONE",
    "SECOND_THANG",
    "THIRD_THINGER",
    "FOURTH_MABOB",
};

int main(int argc, char *argv[]) {
  // YAML::Parser in;
  YAML::Emitter out;

  // Stream out structured data
  out << YAML::BeginMap;

  out << YAML::Key << "name" << YAML::Value << "John Doe";
  out << YAML::Key << "skills" << YAML::Value;
  out << YAML::BeginSeq << "C++" << "Python" << "YAML" << YAML::EndSeq;

  out << YAML::Key << "custom_list" << YAML::Value;
  out << YAML::BeginSeq;
  for (int ix = 0; ix < ARRAY_SIZE(c_str_arr); ix++) {
    out << str_arr[ix];
  }
  out << YAML::EndSeq;

  out << YAML::EndMap;

  // Output to console or write to a file
  std::cout << out.c_str() << std::endl;

  std::ofstream fout("test-out.yaml");
  fout << out.c_str();
  //
  return 0;
}
