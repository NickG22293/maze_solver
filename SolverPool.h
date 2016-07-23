/* this will hold all concurrently executing threads of Solvers
   attempting to solve the maze. */ 

class SolverPool
{
public: 
	SolverPool(); 
	SolverPool(size_t solvers); 
	auto enqueue_solver(Solver solver); 	
	
private: 
	// all available threads
	std::vector<Solver> 	solverPool;	
	// queue of task execution
	std::queue<Solver> 		taskQueue;
	std::mutex 				pool_mutex; 
	std::condition_variable pool_CV; 
}
