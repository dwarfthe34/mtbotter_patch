# MtBotter

mtbotter is a library for creating simple or complex Minetest bots. You can move in
the world, add or remove blocks, punch nodes, mobs and players and receive currently a
few events such as removal or addition of a node, chat messages and time change.

About 80-90 % of the credit of this project goes to celeron55
and other authors and contributors of Minetest(engine). And to the creators of Irrlicht
Roughly 9.9% of this repository's credit goes to Farooqkz the creator of MtBotter.
And I take the remaining 0.1% of credit for patching this bot library.

To code a bot in C++(if you want to code your bot in other languages, see Other
languages section), see CREATE-BOT.md

## Other languages

Currently you don't have any option but C++.

## Build

To build MtBotter run the following:
 ``` cmake . ``` (or if you want ``` cmake . -DRUN_IN_PLACE=TRUE``` to have it run in place and it also what Luanti does) after do ```make -j$(nproc)```
to use all CPU cores for faster building. 
The resulting library will appear in `/lib/` as `libmtbotter.so` on POSIX
systems(including Linux).

I haven't tested compiling it on other Operating Systems such as Windows or Mac OS X
but it should work.
If you run into any error try upgrading CMake to the latest version.
## Run the bot
From my testing the best method of running you bot is stated here 
``` 
g++ -std=c++17 -I./src -I./lib/jsoncpp -I./lib/lua/src \
	mybot.cpp -L./lib -lmtbotter -ljsoncpp -llua -o mybot
```
The file "mybot.cpp" is whatever you named your bot file and the name after "-o" (in my case "mybot") is the name of your bot's binary file. 
The binary file is the one you execute. To do that on Linux would be "./mybot" but remember it does not need to be named "mybot".
## Todo

There are many files, functions, methods, classes and structures
 from Minetest which are not required by MtBotter such as GUI, Rendering, LocalDB,
 Sound and Server codes. They should be removed soon or late.

## Licence

MtBotter uses Minetest code and Minetest uses a copyleft licence named LGPL, thus
MtBotter is under the same licence(LGPL 2.1+).
For more information see LICENSE in project's root directory.
