/* generic coordinate Point struct */ 
struct Point 
{
	int x = -1; 
	int y = -1; 
}

/* the maze is made up of series of Nodes in a grid 
   a Node is just coordinates, and links to connecting 
   nodes. One node will have starting condition, 
   and another will have ending condition */
class Node 
{
public: 
	Node(); 
	Node(int x, int y); 
	Point GetCoords(); 
	bool isEnd(); 
	bool isDeadEnd(); 

private:	
	std::vector<const Point> m_ConnectingNodes; 	
} 
