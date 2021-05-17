# 2-Player-Maze-Game-and-Maze-Simulation

## Game Idea
- Similar to the Pacman Game
- Two players which can freely move throughtout the maze
- Everytime a player steps on a tile the colour of the tile changes to the players designated colour
- There are power pill. The tiles visited by the player within ```x``` seconds of comsuming the power pill are permanently marked by the colour of the player and cannot be changed
- After ```N``` minutes the game terminates and scores are projected on the screen
- The player which captures more number of tiles by the end of the game wins.
## Maze Creation
### TO-DO:
- Random Maze creation code
- Called every time the game is booted or restarted.
### Resources
- [Maze Generation Using Backtracking](https://en.wikipedia.org/wiki/User:Dllu/Maze)

### Installing SDL2 packages on Ubuntu
```shell
sudo apt-get install libsdl2-2.0
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
```
