#!/bin/bash

ANDROID_NDK=/home/feng/workspace/as-houyi/android-ndk-r19c

rm -rf build_dir && mkdir build_dir && cd build_dir &&
#cmake   -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
        #-DANDROID_ABI="arm64-v8a" \
	#-DANDROID_NDK=$ANDROID_NDK \
	#-DANDROID_PLATFORM=android-28 \
cmake	-DBUILD_SHARED_LIBS=true\
	-DCMAKE_BUILD_TYPE=Release\
	.. && make

