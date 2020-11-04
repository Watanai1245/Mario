#pragma once
#include "Animation.h"
#include "Collider.h"

class Enemies
{
public:
	Enemies(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, sf::Vector2f position);
	~Enemies();

	void Update(float deltaTime, sf::Vector2f direction);
	void draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f setPosition() { return body.getPosition(); }


private:
	float speed;
	sf::RectangleShape body;
	Animation animation;
	sf::Vector2f velocity;
	int row;
	bool faceRight;
};

