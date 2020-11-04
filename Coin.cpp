#include "Coin.h"

Coin::Coin(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, sf::Vector2f position) :
	animation(texture, imageCount, switchtime)
{
	row = 0;
	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

Coin::~Coin()
{
}

void Coin::update(float deltatime)
{
	animation.Updatecoin(row, deltatime);
	body.setTextureRect(animation.uvRect);
}

void Coin::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Coin::Collected()
{
	body.setPosition(0.0f, -100.0f);
}