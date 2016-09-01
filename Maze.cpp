#pragma once

#include "Maze.h"
#include <exception>
#include <string>
#include "Errors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
	// After grid has been constructed, we must connect all the nodes. This will be done in a mostly 
	// random fashion (for dead-ends, and pathway decisions) 

	// Set Maze start/end conditions
	ChooseMazeStart(); 
	ChooseMazeEnd(); 
}

void Maze::ChooseMazeStart()
{
	Node* start_Node; 

	// Using c-style rand because I'm insane
	do
	{
		start_Node = ChooseRandomPerimeterNode();
	} while (start_Node->isEnd()); 

	// Set that node to END 
	start_Node->ChangeNodeStatus(START);
}

Node* Maze::ChooseRandomPerimeterNode()
{
	Node* node; 
	std::srand(std::time(0));
	int rand_row = std::rand() % m_gridSize;
	int rand_col;
	if (rand_row == 0 || rand_row == m_gridSize - 1)
		rand_col = std::rand() % m_gridSize;
	else
	{
		rand_col = std::rand() % 2;
		if (rand_col % 2 == 0)
			rand_col = 0;
		else
			rand_col = m_gridSize;
	}
	node = &m_grid[rand_row][rand_col];
	return node; 
}

void Maze::ChooseMazeEnd()
{
	//NOTE: We'll start assuming the maze end is on the perimeter 
	Node* end_Node; 

	// Using c-style rand because I'm insane
	do
	{
		end_Node = ChooseRandomPerimeterNode(); 
	} while (end_Node->isStart()); 

	// Set that node to END 
	end_Node->ChangeNodeStatus(END); 
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
			// As each node is a part of the grid, they require coords 
			Node* n = new Node(); 
			Point* p = new Point(row, col); 
			n->SetCoords(p); 
			nodeRow.push_back(*n); 
		}
		m_grid.push_back(nodeRow);
	}
	
	// Connect all these nodes
	ConnectMaze(); 
}

void Maze::PrintMaze()
{
	for (int row = 0; row < m_gridSize; row++)
	{
		for (int col = 0; col < m_gridSize; col++)
		{
			if (m_grid[row][col].isStart() || m_grid[row][col].isEnd())
			{
				if (row == 0 || row == m_gridSize - 1)
					std::cout << "||";
				else
					std::cout << "=";
			}
			else
				std::cout << "O ";
		}
		std::cout << std::endl; 
	}
}
 
int main()
{
	Maze m(); 
	Maze m2(4); 
	m2.PrintMaze();
}