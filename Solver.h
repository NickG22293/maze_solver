#pragma once
#include "Node.h"

 /* Solver class is what will attempt to run through and find the end
   of the maze, in some pattern of execution. Solvers will run concurrently. 
   They are managed by the SolverPool */
class Solver
{
public:
	Node* ChooseNextNode(); 


protected:

};