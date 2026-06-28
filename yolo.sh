# clone yaml-cpp dependency at same level as test repo
cd ..
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp
rm -rf ./build

# build yaml-cpp static library
mkdir build && cd build && cmake .. && make

# cd to original directory
cd ../../test-yaml-cpp

# build test-yaml
./build.sh

# run test-yaml
./test-yaml-cpp
