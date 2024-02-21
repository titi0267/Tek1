# Sokoban

|                              Language                               | Duration |    Concept    |                Mark                 |                  Author                  |
| :-----------------------------------------------------------------: | :------: | :-----------: | :---------------------------------: | :--------------------------------------: |
| [![Languages](https://skillicons.dev/icons?i=c)](https://c.org/en/) | 2 Weeks  | C programming | ![86%](https://progress-bar.dev/86) | [@titi0267](https://github.com/titi0267) |

### Description

Develop a copy of the sokoban game in terminal mode, using the ncurses library.

The map is not necessary square, it might have different shapes closed by a wall.

The game must be reset by pressing the space bar.

Redimensioning the terminal must be handled.

As long as the terminal is too small to display the whole map, a centered message, asking the user to enlarge the terminal, must be displayed.

The game must be able to be played with the arrow keys (LEFT, RIGHT, UP and DOWN).

A valid map can only contains the characters SPACE, '\n', '#', 'X', 'O' and 'P'.

If an invalid map is supplied, the program must exit with an error

### Launch

On linux:

- `make` to generate the binary

- `./my_sokoban -h` to see usage.

# Printf

|                              Language                               | Duration |    Concept    |                Mark                 |                  Author                  |
| :-----------------------------------------------------------------: | :------: | :-----------: | :---------------------------------: | :--------------------------------------: |
| [![Languages](https://skillicons.dev/icons?i=c)](https://c.org/en/) | 2 Weeks  | C programming | ![48%](https://progress-bar.dev/48) | [@titi0267](https://github.com/titi0267) |

### Description

Recreate the printf function to use it into your other projects thanks to a library.

### Launch

On linux:

- `make` to generate the library file.

# Ls

|                              Language                               | Duration |    Concept    |               Mark                |                  Author                  |
| :-----------------------------------------------------------------: | :------: | :-----------: | :-------------------------------: | :--------------------------------------: |
| [![Languages](https://skillicons.dev/icons?i=c)](https://c.org/en/) | 2 Weeks  | C programming | ![5%](https://progress-bar.dev/5) | [@titi0267](https://github.com/titi0267) |

### Description

You must recode the ls [-alRdrt] [FILE] command.

### Launch

On linux:

- `make` to generate the binary.

- `./my_ls` to execute.

# Navy

|                              Language                               | Duration | Concept |                Mark                 |                                          Author                                          |
| :-----------------------------------------------------------------: | :------: | :-----: | :---------------------------------: | :--------------------------------------------------------------------------------------: |
| [![Languages](https://skillicons.dev/icons?i=c)](https://c.org/en/) | 3 Weeks  | Signals | ![42%](https://progress-bar.dev/42) | [@titi0267](https://github.com/titi0267) <br> [@eIIiotwId](https://github.com/eIIiotwId) |

### Description

You all know the very famous Battleship game. Well, I hope so.

You must code a terminal version of this game using signals.

The two players are ONLY allowed to comunicate using the signals SIGUSER1 and SIGUSER2.

The map size is 8x8.

On each turn, you must display your positions, and then your enemy's positions.

At the end of the game (when all the ships of a player have been hit), you must display whether 'I won'
(and return 0) or 'Enemy won' (and return 1).

### Launch

On linux:

- `make` to generate the binary

- `./navy -h` to see usage.
