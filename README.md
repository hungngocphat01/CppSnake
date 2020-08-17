# CppSnake
- This is a simple Snake game written using the ``ncurses`` library in C++.
## Requirements
- A POSIX-compatible operating system (macOS, BSD, Linux, etc.).
- GNU gcc.
- A terminal emulator with a minimum size of 70x20 (to ensure ASCII arts fit within the terminal's canvas).
- On macOS: ``argp-standalone`` Homebrew package.
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
## Building and running
```bash
$ git clone this_repository
$ cd CppSnake
$ make
$ ./snake
```