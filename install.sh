rm /??/libs/lib64/libCoreLib.a
rm /??/libs/lib64/libCoreLibd.a
cd build/
make clean
cmake .. -D CMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:Path=/??/libs && make all install
make clean
cmake .. -D CMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:Path=/??/libs && make all install

