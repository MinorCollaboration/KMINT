#include "Node.h"
void Node::connect_node(Node * node1, int weight) {
	Hallway hallway{ this, node1,weight };

	this->connected_nodes.push_back(hallway);
	node1->connected_nodes.push_back(hallway);

}