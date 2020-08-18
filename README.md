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
- Cheat code: ``/`` to increase the length by 1 block without having to eat any food.
## Customization
```
Usage: snake [OPTION...]
A simple Snake game written in C++

  -b, --body=BODYC           Set body character
  -d, --border=BORDERC       Set border character
  -f, --food=FOODC           Set food character
  -h, --head=HEADC           Set head character
  -i, --interval=INVERVAL    Set the snake's speed (nanosecond)
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

```
## Update routine
- ``v3.0``: Unresizable and customizable canvas.
## Building and running
```bash
$ git clone this_repository
$ cd CppSnake
$ make
$ ./snake
```
