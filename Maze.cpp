#include "Maze.h"
#include <exception>
#include <string>
#include "Errors.h"

Maze::Maze()
{

}

Maze::Maze(int grid_size)
{
	m_GridSize = grid_size;
}

void Maze::Solve()
{
	throw NotImplementedException();
}

void Maze::ConnectMaze()
{
	throw NotImplementedException();
}

void Maze::MakeNodeEnd(Node n)
{
	throw NotImplementedException();
}

void Maze::MakeNodeBeginning(Node n)
{
	throw NotImplementedException();
}