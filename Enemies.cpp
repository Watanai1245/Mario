#include "Enemies.h"
#include "Animation.h"

Enemies::Enemies(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, sf::Vector2f position) :
	animation(texture, imageCount, switchtime)
{
	speed = 100;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(60.0f, 60.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

Enemies::~Enemies()
{
}

void Enemies::Update(float deltaTime, sf::Vector2f direction)
{
	velocity.y = 0.0f;
	velocity.x = speed;
	row = 0;
	//if (body.GetPosition().x = 1500)
	//{
	//	;
	//}
	if (direction.x < 0)
	{
		faceRight = true;
	}
	if (direction.x > 0)
	{
		faceRight = false;
	}

	body.move(velocity * deltaTime);
	animation.UpdateEnemies(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
}

void Enemies::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
