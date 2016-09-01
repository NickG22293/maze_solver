#pragma once

/* A maze is comprised of many nodes, linked together with two nodes 
   representing beginning and end. Solver's will attempt to find the 
   end of the graph, possibly in a variety of algorithmic ways. */ 
#include <vector>
#include "SolverPool.h"
#include "Node.h"

class Maze 
{
	/* 2D vector of nodes represents our maze's grid */
	typedef std::vector<std::vector<Node>> Grid; 
public:
	Maze(); 
	Maze(int grid_size); 
	// Create the grid
	void CreateGrid(); 
	void PrintMaze(); 

private:
	SolverPool 	m_pool; 
	Grid 		m_grid; 
	int			m_gridSize;

	// Kick off execution of solving the maze
	void Solve(); 
	// Run through and create connections between nodes
	void ConnectMaze(); 
	// Set the end and beginning nodes
	void MakeNodeEnd(Node& n); 
	void MakeNodeBeginning(Node& n);
	// Choose where the beginning and end nodes reside
 	void ChooseMazeEnd(); 
	void ChooseMazeStart();
	Node* ChooseRandomPerimeterNode(); 
};