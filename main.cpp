#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputMgr.h"
#include "ResourceMgr.h"

int main()
{


    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::vector <std::string> files = {
        "graphics/player.png",
        "graphics/player.png",
        "graphics/player.png",
        "graphics/player.png",
        "graphics/player.png",
        "graphics/player.png",
        "graphics/player.png"
    };

    ResourceMgr<sf::Texture>::Instance().load(files);
    ResourceMgr<sf::Texture>::Instance().load("graphics/player.png");


    sf::Sprite sprite;
    sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));




    while (window.isOpen())   // 게임 루프, 창이 닫히지 않은 동안 계속 도는 반복문입니다.
    {
        InputMgr::Clear(); // 입력 초기화 
        InputMgr::Init();

        sf::Event event; 
        while (window.pollEvent(event))
        {
            

            if (event.type == sf::Event::Closed)
                window.close();


            InputMgr::UpdateEvent(event);
        }


        // update 구간

        InputMgr::Update(0.f); // 벡터 구현 전 0.f 



        if (InputMgr::GetKeyDown(sf::Keyboard::A)) // 입력상태 확인
        {
            std::cout << "Key Down: A" << std::endl;
        }
        if (InputMgr::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }
        if (InputMgr::GetKey(sf::Keyboard::A))
        {
            std::cout << "Key Held: A" << std::endl;
        }



        // Draw 구간
        window.clear();
        /*window.draw(shape);*/
        window.draw(sprite);
        window.display();



    }

    return 0;
}