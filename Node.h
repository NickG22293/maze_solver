#include <vector>
#include <memory>

/* generic coordinate Point struct */ 
struct Point 
{
	int x = -1; 
	int y = -1; 
};

enum eNodeStatus
{
	START,
	NEUTRAL,
	END
};

/* the maze is made up of series of Nodes in a grid a Node is just coordinates, and links to connecting 
   nodes. One node will have starting condition, and another will have ending condition */
class Node 
{
public: 
	Node(); 
	Node(int x, int y); 

	//Retrieve coordinates in maze grid
	Point GetCoords(); 
	// End condition 
	bool isEnd(); 
	// No connecting nodes besides previous 
	bool isDeadEnd(); 

private:	
	// Connect given node to this 
	void ConnectNode(std::unique_ptr<Node> n); 
	void SetCoords(int x, int y); 

	// Container of all connected nodes (max 4)
	std::vector<const Point> m_ConnectingNodes;
	Point m_Coords; 
	eNodeStatus m_Status; 	
};