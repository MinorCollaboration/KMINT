#include "Node.h"
void Node::connect_node(Node * node1) {

	Hallway hallway{ this, node1,(this->x - node1->x) - (this->y - node1->y) };

	this->connected_nodes.push_back(hallway);
	node1->connected_nodes.push_back(hallway);

}