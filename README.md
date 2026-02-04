# MtBotter
# ***IF YOU WANT TO COMMIT TO THIS PROJECT PLEASE DO SO.***
mtbotter is a library for creating simple or complex Minetest bots. You can move in
the world, add or remove blocks, punch nodes, mobs and players and receive currently a
few events such as removal or addition of a node, chat messages and time change.

About 80-90 % of the credit of this project goes to celeron55
and other authors and contributors of Minetest(engine). And to the creators of Irrlicht.
Roughly 9.9% of this repository's credit goes to Farooqkz the creator of MtBotter.
And I take the remaining 0.1% of credit for patching this bot library.

To code a bot in C++(if you want to code your bot in other languages, see Other
languages section), see CREATE-BOT.md.

## Other languages

At the moment you need to code in C++ for bots in the near future I will change that to have Lua support.

## Build

To build MtBotter run the following:
```chmod +x build.sh ``` then do ```sudo bash build.sh ``` those command will compile Irrlicht to help patch a bug it had, and it will also build MtBotter.
If you do not want to execute those commands you can go into "irrlicht/source/Irrlicht" and run ```sudo make -j$(nproc) ``` then go back into the MtBotter parent folder and run the following:
```cmake . -DRUN_IN_PLACE=TRUE -DENABLE_SOUND=0 ``` then do the make command again. The build.sh file is to automate that process.
I haven't tested compiling it on other Operating Systems such as Windows or Mac OS X
but it should work. Also yes I know adding ```sudo``` is needed I don't really understand but it all of a sudden didn't compile without ```sudo``` before ```make```.
## Run the bot
From my testing the best method of running your bot is stated here 
``` 
g++ -std=c++17 \
    -I./src \
    -I./lib/jsoncpp \
    -I./lib/lua/src \
    -I/irrlicht/include \
    mybot.cpp \
    ./lib/lua/src/lapi.c \
    ./lib/lua/src/lcode.c \
    ./lib/lua/src/ldebug.c \
    ./lib/lua/src/ldo.c \
    ./lib/lua/src/ldump.c \
    ./lib/lua/src/lfunc.c \
    ./lib/lua/src/lgc.c \
    ./lib/lua/src/llex.c \
    ./lib/lua/src/lmem.c \
    ./lib/lua/src/lobject.c \
    ./lib/lua/src/lopcodes.c \
    ./lib/lua/src/lparser.c \
    ./lib/lua/src/lstate.c \
    ./lib/lua/src/lstring.c \
    ./lib/lua/src/ltable.c \
    ./lib/lua/src/ltm.c \
    ./lib/lua/src/lundump.c \
    ./lib/lua/src/lvm.c \
    ./lib/lua/src/lzio.c \
    -L./lib -lmtbotter -ljsoncpp \
    -L/irrlicht/lib -lIrrlicht \
    -Wl,-rpath,'$ORIGIN/lib' \
    -o mybot
```
The file "mybot.cpp" is whatever you named your bot file and the name after "-o" (in my case "mybot") is the name of your bot's binary file. 
The binary file is the one you execute. To do that in my case would be "./mybot" but remember it does not need to be named "mybot".
## Todo

There are many files, functions, methods, classes and structures
 from Minetest which are not required by MtBotter such as GUI, Rendering, LocalDB,
 Sound and Server codes. They should be removed soon or late.

## Licence

MtBotter uses Minetest code and Minetest uses a copyleft licence named LGPL, thus
MtBotter is under the same licence(LGPL 2.1+).
For more information see LICENSE in project's root directory.
## Notes

This bot will strictly only connect to servers with a fully number IP address, I am working on patching that bug and it should be the seond to last one. There is also a bug so MtBotter cannot connect to servers that you are not running on your 
**own machine** I am working on this fast. 
