# CppSnake
- This is a simple Snake game written using the ``ncurses`` library in C++.
## Requirements
- A POSIX-compatible operating system (macOS, FreeBSD, Linux, etc.). You can also try it on Windows with ``argp`` and ``ncurses`` installed (somehow).
- GNU gcc.
- A terminal emulator with a minimum size of 70x20 (to ensure ASCII arts fit within the terminal's canvas).
- On macOS: ``argp-standalone`` Homebrew package.
## How to play
- Use ``WASD`` to navigate, eat the food to grow up.
- The snake's head cannot overlap the walls nor its body.
- The max length is 50, going beyond that can cause the game to be crashed. This is due the snake's blocks' coordinates are statically allocated, will implement another method later.
- If you resize the terminal window while playing, the game interface will be redrawn to fit the new size.<br>
If no constant canvas size is determined, the canvas will be resized as well.
- Cheat code: ``/`` to increase the length by 1 block without having to eat any food. Only present if debug mode is enabled.
## Customization
```
Usage: snake [OPTION...]
A simple Snake game written in C++

  -b, --body=BODYC           Set body character.
  -B, --border=BORDERC       Set border character.
  -D, --debug                Show debug information.
  -f, --food=FOODC           Set food character.
  -h, --head=HEADC           Set head character.
  -H, --height=YSIZE         Set canvas height.
  -i, --interval=INVERVAL    Set the snake's speed (nanosecond).
  -W, --width=XSIZE          Set canvas width.
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

```
## Changelog and update routine
```
######### CHANGELOG ##########
v1.0: initial release.
v2.0: add basic customization (snake head, body, game border, etc.).
v3.0: add customizable canvas size.
v4.0: save/load supported. No limit in snake length. Add score bar.
v4.1: fix score bar, fix cannot enter savefile name, fix memory leak.
```
## Building and running
```bash
$ git clone this_repository
$ cd CppSnake
$ make
$ ./snake
```
If you have trouble compiling on some Linux distros, use the following instead:
```bash
$ make CCFLAGS=-largp
```
