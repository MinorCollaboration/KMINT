#pragma once
#include "Node.h"
#include <vector>
#include <queue>
#include <iostream>


class A_star
{
public:
	A_star();
	~A_star();
	std::vector<Node> find_path(Node start_node, Node end);
};

