#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "ExampleGameObject.h"

int counter = 0;

std::vector<Node> create_graph() {
	std::vector<Node> graph;
	//create nodes
	Node node1{400, 350};
	Node node2{350,400};
	Node node3{450,400};
	//connect nodes
	node1.connected_nodes.push_back(node2);
	node2.connected_nodes.push_back(node3);
	node3.connected_nodes.push_back(node1);
	// add to graph
	graph.push_back(node1);
	graph.push_back(node2);
	graph.push_back(node3);

	return graph;

}

void draw_graph(FWApplication* application, std::vector<Node> graph) {

	for (auto const& node : graph ) {
		application->SetColor(Color(0, 0, 255, 255));
		application->DrawCircle(node.x, node.y, 10, true);
		for (auto const& connected_node : node.connected_nodes) {
			application->SetColor(Color(0, 0, 0, 255));
			application->DrawLine(node.x, node.y, connected_node.x, connected_node.y);
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

	// Dancing cow
	ExampleGameObject *example = new ExampleGameObject();
	application->AddRenderable(example);
	example->SetSize(100,100);

	

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

