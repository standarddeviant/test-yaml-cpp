g++ \
  -I../yaml-cpp/include \
  -std=c++17 \
  -o ./test-yaml-cpp \
  ./main.cpp \
  ../yaml-cpp/build/libyaml-cpp.a
