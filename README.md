#NuCTex
The Null C Text Engine is an attempt to create a singleplayer game engine in the
style of the Multi User Dungeons and text adventure games of the '80s and '90s.
The goal is to create a functional game as practice for an implementation of an
actual MUD engine in the future.

#Goals
The short-term goal is to create a game that is text-based in style and
execution but MUD-like in size and story detail.

The long-term goal is to create a fully functional engine from which any user
can create a game with locations, monsters, and puzzles to solve.

##Development Status
NuCTex is currently in pre-alpha development, meaning that it is in no way a
game that can be played and enjoyed for entertainment. Current focus is in
creating a proof of concept and then expanding on it to create a game. There
is a list of features that must be implemented in NuCTex before it goes into
Alpha. See the milestones page for more details.

###Current features
* Walk around in an exciting 4-tile world!
* Experience the ability to look at your surroundings (and other monsters!)
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
3. Initialize the CMake project with `cmake .`
4. Compile with `make`
5. Run `./nuctex`

These steps have been tested with a computer running Debian 7 ARM and a computer
running 64-bit Arch Linux.

##Others (Windows, Mac, etc.)
For Windows, the most likely workable option is to use MinGW. Mac users should
hace access to an implementation of GCC.
