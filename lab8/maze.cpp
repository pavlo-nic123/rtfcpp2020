#include "maze.h"

Maze::Maze(int n, int m)
{
	field = new MCell[m * n];
	N = n;
	M = m;
}

Maze::~Maze()
{
	delete[] field;
}

const MCell& Maze::cell(int i, int j) const
{
	return field[i * N + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (i1 == i2 && abs(j1 - j2) == 1 && cell(i1, min(j1, j2)).right()) //если они находятся в одной строке и у левой есть соединение справа
		return (true);
	if (j1 == j2 && abs(i1 - i2) == 1 && cell(min(i1, i2), j1).down()) //если они находятся в одном столбце и у верхней есть соединение снизу
		return (true);
	return false;
}

void Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 == i2 && abs(j1 - j2) == 1 /*&& !cell(i1, min(j1, j2)).right()*/) //если они находятся в одной строке и у левой нет соединения справа
	{
		field[i1 * N + min(j1, j2)].m_right = true;
		field[i1 * N + max(j1, j2)].m_left = true;
	}
	else if (j1 == j2 && abs(i1 - i2) == 1 /*&& !cell(min(i1, i2), j1).down()*/)//если они находятся в одном столбце и у верхней нет соединения снизу
	{
		field[min(i1, i2) * N + j1].m_down = true;
		field[max(i1, i2) * N + j1].m_up = true;
	}
}

void Maze::removeConnection(int i1, int j1, int i2, int j2) // не использовал has connection, т.к. она не возвращает тип соединения
{
	if (i1 == i2 && abs(j1 - j2) == 1 && cell(i1, min(j1, j2)).right()) //если они находятся в одной строке и у левой есть соединение справа
	{
		field[i1 * N + min(j1, j2)].m_right = false;
		field[i1 * N + max(j1, j2)].m_left = false;
	}
	if (j1 = j2 && abs(i1 - i2) == 1 && cell(min(i1, i2), j1).down()) //если они находятся в одном столбце и у верхней есть соединение снизу
	{
		field[min(i1, i2) * N + j1].m_down = false;
		field[max(i1, i2) * N + j1].m_up = false;
	}
}

void Maze::printMaze()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printCell(cell(i, j));
		cout << endl;
	}
}

/// rldu
/// 0000 0
/// 0001 1
/// 0010 2
/// 0011 3
/// 0100 4
/// 0101 5
/// 0110 6
/// 0111 7
/// 1000 8
/// 1001 9
/// 1010 10
/// 1011 11
/// 1100 12
/// 1101 13
/// 1110 14
/// 1111 15

void printCell(const MCell& cell)
{
	int dir = 0;
	if (cell.up())
		dir |= 1;
	if (cell.down())
		dir |= 1 << 1;
	if (cell.left())
		dir |= 1 << 2;
	if (cell.right())
		dir |= 1 << 3;
	switch (dir)
	{
	case 3://du
		cout << char(179);
		break;
	case 5://ul
		cout << char(217);
		break;
	case 6://dl
		cout << char(191);
		break;
	case 7://ldu
		cout << char(180);
		break;
	case 9://ru
		cout << char(192);
		break;
	case 10://dr
		cout << char(218);
		break;
	case 11://rdu
		cout << char(195);
		break;
	case 12://rl
		cout << char(196);
		break;
	case 13://rlu
		cout << char(193);
		break;
	case 14://rld
		cout << char(194);
		break;
	case 15://rldu
		cout << char(197);
		break;
	default:
		cout << '0';
	}
}