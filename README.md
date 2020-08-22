# CppSnake
- This is a simple Snake game written using the ``ncurses`` library in C++.
## Requirements
- A POSIX-compatible operating system (macOS, FreeBSD, Linux, etc.). Cannot run natively on Windows due to the absence of ``ncurses`` library.
- GNU gcc.
- A terminal emulator with a minimum size of 70x20 (to ensure ASCII arts fit within the terminal's canvas).
- On macOS: ``argp-standalone`` Homebrew package.
## How to play
- Use ``WASD`` to navigate, eat the food to grow up.
- Press ``Q`` to quit, ``P`` to pause or ``O`` to save the game.
- The snake's head cannot overlap the walls nor its body.
- If the terminal window is resized while playing, the game interface will be redrawn to fit the new size.<br>
If no constant canvas size is specified, the canvas will be the entire terminal, so it will be resized as well.
- Cheat code: ``/`` to increase the length by 1 block without having to eat any food. Only present if debug mode is enabled.
## Customization
```
Usage: snake [OPTION...]
  -b, --body=BODYC           Set body character.
  -B, --border=BORDERC       Set border character.
  -D, --debug                Show debug information.
  -f, --food=FOODC           Set food character.
  -h, --head=HEADC           Set head character.
  -H, --height=YSIZE         Set canvas height.
  -i, --interval=INVERVAL    Set the snake's speed (milisecond).
  -l, --load=FILENAME        Load game from filename.
  -p, --pattern=STRING       Set a custom pattern for the snake (override -h and -b).
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
v4.2: add custom pattern support.
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
