#ifndef TESTSTATE_H
#define TESTSTATE_H
#include <queue>
#include <SFML/Window.hpp>
#include "statemanager.h"

namespace state {
    class test : public state::prototype {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void update( sf::RenderWindow &app, state::manager &man, std::queue<sf::Event> events );
        void render( sf::RenderWindow &app );
    };
};

#endif /* TESTSTATE_H */
