#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class MCell
{
	friend class Maze;
	bool m_right;
	bool m_down;
	bool m_up;
	bool m_left;
	MCell() { m_down = false, m_right = false; m_up = false; m_left = false; };
public:
	bool right() const { return m_right; };
	bool down() const { return m_down; };
	bool up() const { return m_up; };
	bool left() const { return m_left; };
};

class Maze
{
	MCell* field = nullptr;
	const MCell& cell(int i, int j) const;
	int N, M;
public:
	Maze(int n, int m);
	~Maze();
	bool hasConnection(int i1, int j1, int i2, int j2);
	void makeConnection(int i1, int j1, int i2, int j2);
	void removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
};

void printCell(const MCell& cell);