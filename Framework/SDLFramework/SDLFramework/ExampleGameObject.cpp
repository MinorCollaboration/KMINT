#include "ExampleGameObject.h"
#include <SDL_render.h>

ExampleGameObject::ExampleGameObject() {
	texture = mApplication->LoadTexture("lemmling_Cartoon_cow.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

ExampleGameObject::~ExampleGameObject() {
	SDL_DestroyTexture(texture);
}

bool ExampleGameObject::Update(float deltaTime, int x , int y) {
	bool result = true;
	

	if (this->mX != x) {
		if (this->mX < x) {
			this->mX +=  1;

		}
		else {
			this->mX -= 1;
		}
		result = false;
	}

	if (this->mY != y) {
		if (this->mY < y) {
			this->mY += 1;

		}
		else {
			this->mY -= 1;
		}
		result = false;
	}

	
	return result;

}