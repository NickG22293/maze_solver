#pragma once
#include <vector>
#include <memory>

/* generic coordinate Point struct */
class Point
{
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	Point() : Point(0, 0) {};
	int x;
	int y;
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
	Node(Point* p);

	//Retrieve coordinates in maze grid
	Point GetCoords();
	// End condition 
	bool isEnd();
	bool isStart(); 
	// No connecting nodes besides previous 
	bool isDeadEnd();
	void ChangeNodeStatus(eNodeStatus status);
	void SetCoords(Point* p);

private:
	// Connect given node to this 
	void ConnectToOtherNode(std::unique_ptr<Node> n);

	// Container of all connected nodes (max 4)
	std::vector<Point> m_ConnectingNodes;
	Point m_Coords;
	eNodeStatus m_Status;
};