#include <SFML/Graphics.hpp>
#include "statemanager.h"



void state::manager::push( prototype *ptr ) {
    if( !states.empty() )
        states.top()->pause();

    states.push( ptr );
    states.top()->init();
}


void state::manager::pop() {
    if( states.empty() )
        return;

    states.top()->cleanup();
    states.pop();

    if( states.empty() )
        return;

    states.top()->resume();
}


void state::manager::swap( prototype *ptr ) {
    if( !states.empty() ) {
        states.top()->cleanup();
        states.pop();
    }

    states.push( ptr );
    states.top()->init();
}



bool state::manager::empty() {
    return states.empty();
}


size_t state::manager::size() {
    return states.size();
}


state::prototype &state::manager::top() {
    if( states.empty() )
        throw; // TODO throw a proper exception here

    return *states.top();
}
