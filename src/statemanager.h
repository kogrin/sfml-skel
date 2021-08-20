#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <stack>
#include <queue>
#include <SFML/Graphics.hpp>

namespace state {
    class prototype;

    class manager {
        std::stack<prototype*> states;

    public:
        void push( prototype *ptr );
        void pop();
        void swap( prototype *ptr );

        bool empty();
        size_t size();

        prototype & top();

        manager() {}
        manager( prototype *ptr );

        // we have a deleted copy constructor,
        // because copying this makese no sense.
        manager( const manager &x ) = delete;
    };


    class prototype {
        // this class is where all states should inherit from.
    public:
        virtual void init()    = 0;
        virtual void cleanup() = 0;

        virtual void pause()   = 0;
        virtual void resume()  = 0;

        virtual void update( sf::RenderWindow &app, state::manager &man, std::queue<sf::Event> events ) = 0;
        virtual void render( sf::RenderWindow &app ) = 0;
    };

}

#endif /* STATEMANAGER_H */
