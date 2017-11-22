#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "ExampleGameObject.h"

int counter = 0;
ExampleGameObject *example;
ExampleGameObject *example1;




std::vector<Node> create_graph() {
	std::vector<Node> graph;
	//create nodes
	Node* node1 = new Node(400,350);
	Node* node2 = new Node(350,400);
	Node* node3 = new Node(450, 400);
	Node* node4 = new Node(300, 300);

	//connect nodes
	node1->connect_node(node2);
	node2->connect_node(node3);
	node3->connect_node(node1);
	node4->connect_node(node1);



	// add to graph
	graph.push_back(*node1);
	graph.push_back(*node2);
	graph.push_back(*node3);
	graph.push_back(*node4);


	return graph;

}



void draw_graph(FWApplication* application, std::vector<Node> graph) {
	graph;

	for (auto const& node : graph ) {
		application->SetColor(Color(0, 0, 255, 255));
		application->DrawCircle(node.x, node.y, 10, true);
		for (Hallway const connected_node : node.connected_nodes) {
			application->SetColor(Color(0, 0, 0, 255));
		application->DrawLine(connected_node.first_node->x , connected_node.first_node->y, connected_node.second_node->x, connected_node.second_node->y);
		}
	}
}
int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));



	

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}
		
		// This is example code, replace with your own!

		// Text drawing
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to KMint", 400, 300);
		
		// Graph drawing
		std::vector<Node> graph_list = create_graph();
		draw_graph(application,graph_list);

		// Dancing cow


		example1 = new ExampleGameObject(graph_list[1].x, graph_list[1].y);
		application->AddRenderable(example1);
		example1->SetSize(100, 100);

		// For the background
		application->SetColor(Color(255, 255, 255, 255));
		bool var = application->UpdateGameObjects(graph_list[counter].x, graph_list[counter].y);
		if (var == false ) {

		}
		else {
			if (counter+1 == graph_list.size()) {
				counter = 0;

			}
			else {
				counter += 1;

			}
		}
		
		
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}

