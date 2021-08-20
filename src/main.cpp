#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "statemanager.h"
#include "teststate.h"
using namespace std;


queue<sf::Event> getInput( sf::RenderWindow &app );


// helper function to compare OpenGL versions between hints/actual acquired settings
// relies on std::pair<>::operator< operating lexicographically
pair<unsigned int, unsigned int> make_glversion( const sf::ContextSettings &cs ) {
    return make_pair( cs.majorVersion, cs.minorVersion );
}


int main( int argc, char *argv[] ) {
    state::manager man;
    sf::RenderWindow app;

    // get resolution
    sf::VideoMode       vmode = sf::VideoMode::getDesktopMode();

    // we only want OpenGL >= 3.3 contexts
    sf::ContextSettings hints = sf::ContextSettings();
    hints.majorVersion = 3;
    hints.minorVersion = 3;

    app.create( vmode, "sfmleton", sf::Style::Fullscreen, hints );

    if( !app.isOpen() ) {
        cerr << "Error creating SFML renderwindow" << endl;
        return EXIT_FAILURE;
    }

    // this will not run on your toaster
    if( make_glversion(app.getSettings()) < make_glversion(hints) ) {
        cerr << "OpenGL >= 3.3 context required, E_TOASTER" << endl;
        return EXIT_FAILURE;
    }

    app.setVerticalSyncEnabled( true );

    // push the initial state onto the state stack
    man.push( new state::test );

    // main event loop: here's where we run the program
    while( app.isOpen() and (!man.empty()) ) {
        // get input/window events
        queue<sf::Event> events = getInput(app);

        // update state
        man.top().update( app, man, events );

        // If state popped itself off? Stop processing and clean up.
        if( man.empty() )
            return EXIT_SUCCESS;

        // We can't continue without a window
        if( !app.isOpen() ) {
            clog << "SFML RenderWindow not open, closing program." << endl;
            return EXIT_SUCCESS;
        }

        // render state
        man.top().render( app );
    }

    return EXIT_SUCCESS;
}


queue<sf::Event> getInput( sf::RenderWindow &app ) {
    queue<sf::Event> queue;

    sf::Event e;
    while( app.pollEvent(e) )
        queue.push( e );

    return queue;
}
