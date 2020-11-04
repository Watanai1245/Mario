#include <SFML\Graphics.hpp>
#include <iostream>
#include "player.h"
#include "Platform.h"
#include <vector>
#include "main.h"
#include "Coin.h"
#include"Enemies.h"

int scr = 0;
static const float VIEW_HEIGHT = 720.0f;




void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
 




int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "mario game", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080,VIEW_HEIGHT));


    

    sf::Texture playerTexture;
    playerTexture.loadFromFile("texture/mario23.png");




    sf::Texture coinTexture;
    coinTexture.loadFromFile("texture/coins.png");




    sf::Texture EnemiesTexture1;
    EnemiesTexture1.loadFromFile("texture/Enemies1.jpg");



    sf::RectangleShape background1(sf::Vector2f(7000.0f, 720.0f));
    background1.setPosition(0.0f, 0.0f);
    sf::Texture bg1;
    bg1.loadFromFile("texture/background1.png");
    background1.setTexture(&bg1);




    sf::RectangleShape background2(sf::Vector2f(7000.0f, 720.0f));
    background2.setPosition(0.0f, 900.0f);
    sf::Texture bg2;
    bg2.loadFromFile("texture/background2.png");
    background2.setTexture(&bg2);




    sf::RectangleShape WarpPoint(sf::Vector2f(40.0f, 20.0f));
    WarpPoint.setPosition(sf::Vector2f(6875.0f, 557.0f));





    Player player(&playerTexture, sf::Vector2u(3, 4), 0.15f, 300.0f, 300.0f);
    Enemies enemies1(&EnemiesTexture1, sf::Vector2u(7, 1), 0.15f, sf::Vector2f(1500.0f, 573.0f));



    sf::Font font;
    if (!font.loadFromFile("font/main_font.ttf"))
        printf("Load font fail");
    sf::Text scoretext("score", font, 30);


    std::vector<Platform> platforms;
    // ด่าน 1
    platforms.push_back(Platform(nullptr, sf::Vector2f(390.0f, 60.0f), sf::Vector2f(1148.0f, 363.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(28000.0f, 20.0f), sf::Vector2f(908.0f, 840.0)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1815.0f, 200.0f), sf::Vector2f(908.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(90.0f, 200.0f), sf::Vector2f(2045.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1811.0f, 200.0f), sf::Vector2f(3162.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(65.0f, 200.0f), sf::Vector2f(4184.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 200.0f), sf::Vector2f(4470.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 200.0f), sf::Vector2f(5220.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1325.0f, 200.0f), sf::Vector2f(6320.0f, 700.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1.0f, 720.0f), sf::Vector2f(-5.0f, 360.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(81.0f, 60.0f), sf::Vector2f(1158.0f, 153.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 53.0f), sf::Vector2f(1705.5f, 362.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(81.0f, 60.0f), sf::Vector2f(1923.5f, 361.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 53.0f), sf::Vector2f(2139.5f, 361.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 53.0f), sf::Vector2f(1812.5f, 203.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 53.0f), sf::Vector2f(2029.5f, 203.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(960.0f, 60.0f), sf::Vector2f(2875.5f, 362.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 60.0f), sf::Vector2f(2926.5f, 124.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(114.0f, 85.0f), sf::Vector2f(2896.f, 557.5f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(114.0f, 85.0f), sf::Vector2f(3527.f, 557.5f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(290.0f, 60.0f), sf::Vector2f(3827.5f, 362.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 55.0f), sf::Vector2f(4797.0f, 361.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 55.0f), sf::Vector2f(5119.0f, 361.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(81.0f, 60.0f), sf::Vector2f(4955.0f, 135.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 107.0f), sf::Vector2f(5770.0f, 556.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 360.0f), sf::Vector2f(5860.0f, 420.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 320.0f), sf::Vector2f(5913.0f, 440.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 280.0f), sf::Vector2f(5966.0f, 460.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 240.0f), sf::Vector2f(6019.0f, 480.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 200.0f), sf::Vector2f(6072.0f, 500.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 160.0f), sf::Vector2f(6125.0f, 520.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 120.0f), sf::Vector2f(6178.0f, 540.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 80.0f), sf::Vector2f(6231.0f, 560.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(53.0f, 40.0f), sf::Vector2f(6284.0f, 580.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(155.0f, 5.0f), sf::Vector2f(6926.0f, 518.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(40.0f, 80.0f), sf::Vector2f(6985.0f, 470.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1.0f, 720.0f), sf::Vector2f(7002.0f, 360.0f)));



    // ด่าน 2
    platforms.push_back(Platform(nullptr, sf::Vector2f(28000.0f, 200.0f), sf::Vector2f(908.0f, 1600.0f)));
     

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // coin 1
    std::vector<Coin> coins;
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f,sf::Vector2f(500.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(600.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1002.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1052.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1102.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1152.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1202.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1252.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1302.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1027.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1077.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1127.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1177.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1227.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1272.0f, 240.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1252.0f, 180.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1052.0f, 180.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, 90.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, 30.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -30.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -90.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -150.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1147.0f, -210.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1690.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1705.0f, 250.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1720.0f, 200.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1745.0f, 150.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1805.0f, 120.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1860.0f, 150.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1885.0f, 200.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1900.0f, 250.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1915.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1930.0f, 250.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1950.0f, 200.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1970.0f, 150.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2025.0f, 120.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2075.0f, 150.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2100.0f, 200.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2120.0f, 250.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2135.0f, 300.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1910.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1910.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1910.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1910.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(1910.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2170.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2170.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2170.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2170.0f, 625.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2170.0f, 625.0f)));

    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2420.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2480.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2540.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2600.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2660.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2720.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2780.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2840.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2900.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2960.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3020.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3080.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3140.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3200.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3260.0f, 290.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3320.0f, 290.0f)));

    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2840.0f, 50.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2900.0f, 50.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(2960.0f, 50.0f)));
    coins.push_back(Coin(&coinTexture, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(3020.0f, 50.0f)));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    float deltaTime = 0.0f;
    sf::Clock clock;





    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::Resized:
                ResizeView(window, view);
                printf("New window width: %i New window height: %i\n",evnt.size.width, evnt.size.height);
                break;

            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }

            ///////////////////////////////////////////////////////////////////////////////////////////////////

            //case sf::Event::MouseMoved:
               // printf("%d , %d\n",evnt.mouseMove.x,evnt.mouseMove.y);
              //  break;

            ///////////////////////////////////////////////////////////////////////////////////////////////
            }
        }

        std::cout << "x = " << player.GetPosition().x << " y = " << player.GetPosition().y << std::endl;

        scoretext.setPosition(player.GetPosition().x + 250.0f, 40.0f);



        if (player.GetPosition().y <= 900.0f)
        {
            scoretext.setPosition(player.GetPosition().x + 250.0f, 40.0f);
            if (player.GetPosition().x < 540.0f)
            {
                scoretext.setPosition(790.0f, 40.0f);
            }
            if (player.GetPosition().x > 6460.0f)
            {
                scoretext.setPosition(6710.0f, 40.0f);
            }
            view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
            if (player.GetPosition().x == 6850.0f)
            {
                view.setCenter(sf::Vector2f(7400.0f, 360.0f));
            }
            if (view.getCenter().x - 540.0f <= 0.0f)
            {
                view.setCenter(sf::Vector2f(540.0f, 360.0f));
            }

            if (view.getCenter().x + 540.0f >= 7000.0f)
            {
                view.setCenter(sf::Vector2f(6460.0f, 360.0f));
            }
        }




        if (player.GetPosition().y >= 900.0f)
        {
            scoretext.setPosition(player.GetPosition().x + 250.0f, 970.0f);
            if (player.GetPosition().x < 540.0f)
            {
                scoretext.setPosition(790.0f, 970.0f);
            }
            if (player.GetPosition().x > 6460.0f)
            {
                scoretext.setPosition(6710.0f, 970.0f);
            }
            view.setCenter(sf::Vector2f(player.GetPosition().x, 1260.0f));
            if (player.GetPosition().x == 6850.0f)
            {
                view.setCenter(sf::Vector2f(7400.0f, 1290.0f));
            }
            if (view.getCenter().x - 540.0f <= 0.0f)
            {
                view.setCenter(sf::Vector2f(540.0f, 1260.0f));
            }
            
            if (view.getCenter().x + 540.0f >= 7000.0f)
            {
                view.setCenter(sf::Vector2f(6460.0f, 1260.0f));
            }
            
        }
        


        ///////////////////////////////////////////////////////////////////////////////////

        sf::Vector2f direction;

        for (Platform& platform : platforms)
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
                player.OnCollision(direction);
               
      


        for (Coin& coin : coins)
        {
            coin.update(deltaTime);
            if (coin.GetCollider().Collect(player.GetCollider(), direction, 1.0f))
            {
                scr = scr + 100;
                scoretext.setString("score " + std::to_string(scr));

                coin.Collected();
            }
        }

       // if (enemies1.GetCollider().CheckEnemies(player.GetCollider(), direction, 1.0f))
        
            

        sf::Vector2f posback;



        

        ///////////////////////////////////////////////////////////////////////////////////






        player.Update(deltaTime, direction);
        enemies1.Update(deltaTime, direction);
        window.clear();
        window.setView(view);
        if (player.GetCollider().CheckCollision(Collider(WarpPoint), direction, 1.0f))
        {
            player.Warped(window);
        }
        window.draw(WarpPoint);

        for (Platform& platform : platforms)
            platform.Draw(window);

        window.draw(background1);
        window.draw(background2);
        window.draw(scoretext);
        for (Coin& coin : coins)
            coin.draw(window);
        enemies1.draw(window);
        player.Draw(window); 
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
