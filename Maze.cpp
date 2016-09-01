#pragma once

#include "Maze.h"
#include <exception>
#include <string>
#include "Errors.h"
#include <iostream>

#define DEBUG 1

Maze::Maze() : Maze(10)
{
}

Maze::Maze(int grid_size)
{
	m_gridSize = grid_size;

	// construct and fill the grid
	CreateGrid(); 
}

void Maze::ConnectMaze()
{
	throw NotImplementedException();
}

void Maze::MakeNodeEnd(Node& n)
{
	eNodeStatus e = END; 
	n.ChangeNodeStatus(e);
}

void Maze::MakeNodeBeginning(Node& n)
{
	eNodeStatus e = START; 
	n.ChangeNodeStatus(e); 
}

void Maze::CreateGrid()
{
	// grids are all square for now
	for (int row = 0; row < m_gridSize; row++)
	{
		std::vector<Node> nodeRow;
		for (int col = 0; col < m_gridSize; col++)
		{
			Node* n = new Node(); 
			Point* p = new Point(row, col); 
			n->SetCoords(p); 
			nodeRow.push_back(*n); 
		}
		m_grid.push_back(nodeRow);
	}
}
 
int main()
{
	Maze m(); 
	Maze m2(4); 
}