#pragma once
#include "Animation.h"
#include "Collider.h"
class Coin
{
public:
	Coin(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, sf::Vector2f position);
	~Coin();

	void update(float deltatime);
	void draw(sf::RenderWindow& window);
	void Collected();
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	Animation animation;
	int row;
};

