
#include <vector> 
#include "Hallway.h"

class Node
{
	
public:
	int x;
	int y;

	Node(int x, int y) :x{ x }, y{ y } {};
	~Node() {};
	Node() {};

	std::vector<Hallway> connected_nodes;
	void connect_node(Node * node1);

private:

};

