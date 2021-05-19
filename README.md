# 2-Player-Maze-Game-and-Maze-Simulation

## Game Idea
- Similar to the Pacman Game
- Two players which can freely move throughtout the maze
- Everytime a player steps on a tile the colour of the tile changes to the players designated colour
- There are power pill. The tiles visited by the player within ```x``` seconds of comsuming the power pill are permanently marked by the colour of the player and cannot be changed
- After ```N``` minutes the game terminates and scores are projected on the screen
- The player which captures more number of tiles by the end of the game wins.
## To Compile:
``` shell
$ make
```
## To Run:
``` shell
$ ./run
```
### Resources
- [Maze Generation Using Backtracking](https://en.wikipedia.org/wiki/User:Dllu/Maze)
- [SDL Functions](http://wiki.libsdl.org/)
- [Sprite](https://github.com/DarkMuffinJoe/Pacman/tree/master/Pacman/Resources)
- [Background Music](https://www.chosic.com/free-music/games/)
- [Sound Effects](https://github.com/schuay/pacman/tree/master/sound)
- [SDL tutorial](https://lazyfoo.net/tutorials/SDL/index.php)

### Installing SDL2 packages on Ubuntu
``` shell
sudo apt-get install libsdl2-2.0
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-mixer-dev
```
