#include "Player.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(60.0f, 70.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(3000.0f, 400.f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::Vector2f direction)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 5000.0f * jumpHeight);
	}

	
	if (direction.y >= 0)
	{
		velocity.y += 5000.0f * deltaTime;
	}

	if (velocity.x == 0.0f && velocity.y == 0.0f)
	{
		row = 0;
	}

	else
	{
		if (velocity.x > 0.0f && velocity.y == 0.0f)
		{
			faceRight = true;
			row = 1;
		}
		if (velocity.x < 0.0f && velocity.y == 0.0f)
		{
			faceRight = false;
			row = 1;
		}
		if (velocity.y < 0.0f && direction.y <= 0)
		{
			row = 2;
			if (velocity.x > 0.0f)
			{
				faceRight = true;
			}
			if (velocity.x < 0.0f)
			{
				faceRight = false;
			}
		}
		if (velocity.y > 0.0f && direction.y >= 0)
		{
			row = 2;
			if (velocity.x > 0.0f)
			{
				faceRight = true;
			}
			if (velocity.x < 0.0f)
			{
				faceRight = false;
			}
		}

	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision om the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision om the right.
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision om the bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0)
	{
		//Collision om the top.
		velocity.y = 0.0f;
	}

}

void Player::Warped(sf::RenderWindow& window)
{
	body.setPosition(215.0f, 1590.0f);
}

