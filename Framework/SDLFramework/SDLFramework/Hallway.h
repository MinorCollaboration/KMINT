#pragma once
 class Node;

class Hallway
{
public:
	Hallway(Node * first_node, Node* second_node, int weight) : first_node{ first_node }, second_node{ second_node }, weight{ weight } {};
	~Hallway() {};
	int weight;
	Node* first_node;
	Node* second_node;


private:

};

