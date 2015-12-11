#NuCTex
The Null C Text Engine is an attempt to create a singleplayer game engine in the
style of the Multi User Dungeons of the '80s and '90s. The goal is to create a
functional game as practice for an implementation of an actual MUD engine in the
future.

##Development Status
NuCTex is currently in pre-alpha development, meaning that it is in no way a
game that can be played and enjoyed for entertainment. Current focus is in
creating a proof of concept and then expanding on it to create a game.

###Current features
* Walk around in an exciting 4-tile world!
* Experience the ability to look at your surroundings!
* Enjoy great power in avoiding the dreaded segfaults!
* Properly quit the program!

###Commands?
For a list of commands and their description, look in the `commands.md` file.

##License?
NuCTex is licensed under the MIT license. A copy is provided in the `LICENSE`
file

#Installation
To compile NuCTex, you will need gcc. NuCTex uses C99 code, so it should work
any recent version of GCC.

##Linux
1. Download the repo with `git clone https://github.com/Nullsrc/nuctex`
2. Move into the repo with `cd nuctex`
3. Compile NuCTex with `gcc -o nuctex src/*.c`, replacing
<executableName> with whatever you wish the executable to be called.
4. Run the executable with `./nuctex`

These steps have been tested with a computer running Debian 7 ARM and a computer
running 64-bit Arch Linux.

##Others(Windows, Mac, etc.)
There is currently no knowledge on compilation on other systems. Any help is
appreciated.
