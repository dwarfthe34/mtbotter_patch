# MtBotter

mtbotter is a library for creating simple or complex Minetest bots. You can move in
the world, add or remove blocks, punch nodes, mobs and players and receive currently a
few events such as removal or addition of a node, chat messages and time change.

About 80-90 % of the credit of this project goes to celeron55
and other authors and contributors of Minetest(engine).
I take the rest remaining credit!

To code a bot in C++(if you want to code your bot in other languages, see Other
languages section), see CREATE-BOT.md

## Other languages

Currently you don't have any option but C++.

## Build

Follow [Compiling instructions of Minetest](https://github.com/minetest/minetest#compiling).
The resulting library will appear in `/lib/` as `libmtbotter.so` on POSIX
systems(including Linux).

On Linux my way to compile it is listed here,
```bash
sudo apt update
sudo apt install build-essential wget git
sudo apt install gcc-9 g++-9
gcc-9 --version
g++-9 --version
sudo apt install \
libbz2-dev \
zlib1g-dev \
libjpeg-dev \
libpng-dev \
libluajit-5.1-dev \
libcurl4-openssl-dev \
libfreetype6-dev \
libopenal-dev \
libvorbis-dev \
libsqlite3-dev \
libx11-dev \
libirrlicht-dev \
gettext
wget https://github.com/Kitware/CMake/releases/download/v3.16.0/cmake-3.16.0-Linux-x86_64.sh
sudo sh cmake-3.16.0-Linux-x86_64.sh --skip-license --prefix=/usr/local
cmake --version
cmake -DCMAKE_C_COMPILER=gcc-9 \
      -DCMAKE_CXX_COMPILER=g++-9 \
      -DCMAKE_CXX_STANDARD=20 ..
-DCMAKE_INCLUDE_PATH=/usr/include/somelib \
-DCMAKE_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu
make -j4
```
Quite intimidating I know but that's the best way I have for you for now. 

I haven't tested compiling it on other Operating Systems such as Windows or Mac OS X
but it should work.

## Todo

There are many files, functions, methods, classes and structures
 from Minetest which are not required by MtBotter such as GUI, Rendering, LocalDB,
 Sound and Server codes. They should be removed soon or late.

## Licence

MtBotter uses Minetest code and Minetest uses a copyleft licence named LGPL, thus
MtBotter is under the same licence(LGPL 2.1+).
For more information see LICENSE in project's root directory.
