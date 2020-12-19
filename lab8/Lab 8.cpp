#include "maze.h"


int main()
{
	const int n = 5, m = 5;
	Maze my_maze(n, m);
	for (int i = 0; i < n-1; i++)
		for (int j = i; j< i+1 && j < m-1; j++)
		{
			my_maze.makeConnection(i, j, i, j + 1);
			my_maze.makeConnection(i, j+1, i+1, j + 1);
		}
	my_maze.printMaze();
}