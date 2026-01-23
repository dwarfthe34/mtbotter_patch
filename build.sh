cd irrlicht/source/Irrlicht
#cmake . -DBUILD_SHARED_LIBS=ON -DCMAKE_POSITION_INDEPENDENT_CODE=ON ..
make -j$(nproc)
cd ..
cd ..
cd ..
cmake . -DRUN_IN_PLACE=TRUE -DENABLE_SOUND=0
make -j$(nproc)
