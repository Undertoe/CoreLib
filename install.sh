rm /??/libs/lib64/libCoreLib.a
rm /??/libs/lib64/libCoreLibd.a
cd build/
make clean
/opt/cmake-3.13.3-Linux-x86_64/bin/cmake .. -D CMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:Path=/??/libs && make all install
make clean
/opt/cmake-3.13.3-Linux-x86_64/bin/cmake .. -D CMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:Path=/??/libs && make all install

