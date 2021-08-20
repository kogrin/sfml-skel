#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "teststate.h"
using namespace std;



void state::test::init() {
}

void state::test::cleanup() {
}


void state::test::pause() {
}

void state::test::resume() {
}


void state::test::update( sf::RenderWindow &app, state::manager &man, std::queue<sf::Event> events ) {
    while( !events.empty() ) {
        sf::Event e = events.front();

        if( e.type == sf::Event::KeyPressed )
            switch( e.key.code ) {
                case sf::Keyboard::Escape:
                    man.pop();
                    break;

                case sf::Keyboard::Return:
                    man.push( new state::test );
                    break;

                default:
                    break;
            }

        events.pop();
    }
}

void state::test::render( sf::RenderWindow &app ) {
    app.display();
}
