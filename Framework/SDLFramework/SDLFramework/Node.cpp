#include "Node.h"
#include <cmath>
void Node::connect_node(Node * node1) {

	Hallway hallway{ this, node1,(int)sqrt(pow(this->x - node1->x,2)  + pow(this->y - node1->y,2)) };

	this->connected_nodes.push_back(hallway);
	node1->connected_nodes.push_back(hallway);

}