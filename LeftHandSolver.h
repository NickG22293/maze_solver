#pragma once
#include "Solver.h"
#include "Maze.h"

class LeftHandSolver :
	public Solver
{
public:
	LeftHandSolver();
	~LeftHandSolver();
	void Solve(Maze& m);
};

