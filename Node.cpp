#include "Node.h"
#include "Errors.h"

// default delegates to 0,0
Node::Node() 
	: Node(0,0)
{
}

Node::Node(int x, int y)
	: Node(new Point(x,y))
{
}

Node::Node(Point* p)
{
	m_Coords.x = p->x; 
	m_Coords.y = p->y; 
	m_Status = NEUTRAL; 
}

void Node::ConnectNode(std::unique_ptr<Node> n)
{
	//TODO: we'll flesh this out once all classes have been stubbed 
	throw new NotImplementedException(); 
}

Point Node::GetCoords()
{
	return m_Coords;
}

bool Node::isDeadEnd()
{
	return (m_ConnectingNodes.size() > 0); 
}

void Node::ChangeNodeStatus(eNodeStatus status)
{
	m_Status = status; 
}

bool Node::isEnd()
{
	return m_Status = END; 
}

void Node::SetCoords(Point* p)
{
	m_Coords.x = p->x; 
	m_Coords.y = p->y; 
}