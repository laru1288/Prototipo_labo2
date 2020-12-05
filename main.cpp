#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Gameplay.h"
#include "elementos.h"
#include "orco.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 500), "War of Survival");
    srand(time(NULL));    
    bool play = false;
    float deltatime;
    window.setFramerateLimit(60);
    sf::Clock clock;
    deltatime = clock.restart().asSeconds();
    Music music_menu, ambiente_music;
    Gameplay gp(deltatime);
    music_menu.openFromFile("sonidos/ori.ogg");
    music_menu.setLoop(true);
    music_menu.setVolume(10);   
    music_menu.play();
   

    while (window.isOpen())
    {
       sf::Event event;
        while (window.pollEvent(event))
        {          
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(1);
            }
            gp.cmd();
            
            

           
            gp.update(window);



            window.clear();
            gp.draw(window);

            window.display();
            
           
        }
       


    }

    return 0;

}
