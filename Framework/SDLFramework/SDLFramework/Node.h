
#include <vector> 

class Node
{
	
public:
	int x;
	int y;

	Node(int x, int y) :x{ x }, y{ y } {};
	~Node() {};
	std::vector<Node> connected_nodes;

private:

};

