#pragma once

#include "IGameObject.h"

class ExampleGameObject : public IGameObject {
public:
	ExampleGameObject(int x, int y);

	~ExampleGameObject();
	bool Update(float deltaTime, int x, int y);

private:
	SDL_Texture *texture;
};