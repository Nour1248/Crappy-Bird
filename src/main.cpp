#include <iostream>
#include "utils.hpp"
#include "bird.hpp"


int main()
{
    //////////////////////////////////////////////////////////////////////////////////////////
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Crappy Bird",(sf::Style::Titlebar | sf::Style::Close));
    sf::Image icon;
    icon.loadFromFile("assets/screenshot.png");
    window.setIcon(128, 128, icon.getPixelsPtr());
    // window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Texture background;
    background.create(288, 512);
    if (!background.loadFromFile("assets/sprites/background-day.png"))
    {
        std::cout<<"failed to load texture\n";
        return 0;
    }
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.scale(sf::Vector2f(WIDTH/288.0f,HEIGHT/512.0f));
    sf::Vector2f mouse;
    /////////////////////////////////////////////////////////////////////////////////////////

    fb::bird bird("assets/sprites/bluebird-upflap.png");
    fb::pipe* bottom_pipes[fb::pipes_count];
    fb::pipe* upper_pipes[fb::pipes_count];
    fb::pipe::create_bottom_pipes(bottom_pipes, "assets/sprites/pipe-red.png");
    fb::pipe::create_upper_pipes(upper_pipes, "assets/sprites/pipe-green-reversed.png");


    while (fb::STATE)
    {
        window.clear();
        window.pollEvent(event);
        fb::handle_events(event, window,fb::STATE);

        fb::time = fb::clock.getElapsedTime();

        window.draw(background_sprite);
        for (size_t i = 0; i < fb::pipes_count; i++)
        {
            window.draw(bottom_pipes[i]->get_sprite());
        }
        for (size_t i = 0; i < fb::pipes_count; i++)
        {
            window.draw(upper_pipes[i]->get_sprite());
        }

        window.draw(bird.get_sprite()); 


        fb::pipe::animate_pipes(bottom_pipes);
        fb::pipe::animate_pipes(upper_pipes);
        bird.animate(event);

        std::cout << bird.get_spriteY() << std::endl;
        mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        window.display();
        if (bird.get_spriteY() > HEIGHT || bird.get_spriteY() < 0 ||        \
        bird.got_touched(bottom_pipes) || bird.got_touched(upper_pipes))
        {
            goto end;
        }
    }
    
end:{
        window.close();
        for (size_t i = 0; i < 10; i++) {
            delete bottom_pipes[i];
            delete upper_pipes[i];
            bottom_pipes[i] = nullptr;
            upper_pipes[i] = nullptr;
        }
        return EXIT_SUCCESS;
    }
}
        // std::cout << fb::distance_x << std::endl;
        // std::cout << bird.get_sprite().getGlobalBounds().top  << std::endl;
        // std::cout << bird.get_sprite().getGlobalBounds().left << std::endl;
        // std::cout << bird.get_sprite().getPosition().x << std::endl;
        // pipe.get_sprite().setPosition(mouse);
        // pipes[0]->get_sprite().getGlobalBounds().left - 100,
        //     pipes[0]->get_sprite().getGlobalBounds().top
        // window.draw(pipes[0]->get_sprite());
        // std::cout << pipes[0]->get_sprite().getGlobalBounds().width << std::endl;
        // std::cout << pipes[0]->get_sprite().getGlobalBounds().top << std::endl;
        // pipes[0]->set_position(sf::Vector2f(pipes[0]->get_sprite().getGlobalBounds().left - 1,
        // pipes[0]->get_sprite().getGlobalBounds().top));