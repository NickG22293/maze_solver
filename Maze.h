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
	//Maze(SolverPool pool); 	

private:
	SolverPool 	m_Pool; 
	Grid 		m_Grid; 
	int			m_GridSize;

	// Kick off execution of solving the maze
	void Solve(); 
	// Run through and create connections between nodes
	void ConnectMaze(); 
	// Set the end and beginning nodes
	void MakeNodeEnd(Node n); 
	void MakeNodeBeginning(Node n);
};