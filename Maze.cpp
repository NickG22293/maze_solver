#include "Maze.h"
#include <exception>
#include <string>
#include "Errors.h"

Maze::Maze() : Maze(10)
{
}

Maze::Maze(int grid_size)
{
	m_gridSize = grid_size;

	// construct and fill the grid
	CreateGrid(); 
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

void Maze::CreateGrid()
{
	// grids are all square for now
	for (int i = 0; i < m_gridSize; i++)
	{
		std::vector<Node> nodeRow;
		for (int j = 0; j < m_gridSize; j++)
		{
			Node *n = new Node(); 
			nodeRow.push_back(*n); 
		}
		m_grid.push_back(nodeRow);
	}
}