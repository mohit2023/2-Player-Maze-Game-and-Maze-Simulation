#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 0     //-y
#define DOWN 1   //+y
#define LEFT 2   //-x
#define RIGHT 3  //+x
#define OUTFILE "MAZE"
#define WHITE fprintf(outfile, "%c%c%c", 75,0,0)
#define BLACK fprintf(outfile, "%c%c%c", 255,50,50)
#define RED   fprintf(outfile, "%c%c%c", 0,0,255)

#define nodeadend
#define backtrack

struct cell{
	bool in;  //Is this cell in the maze?
	bool up;  //Does the wall above this cell exist?
	bool left;//Does the wall to the left of this cell exist?
	int prevx, prevy; //The coordinates of the previous cell, used for backtracking.
};

class Maze{
public:
  Maze(long n, int x, int y);
  void initialize();
  void generate();
  void savebmp(int xspecial,int yspecial);
  void create();
private:
  long numin;
  int xsize;
  int ysize;
  cell **MAZE;
};
