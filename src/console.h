#ifndef CONSOLE_H
#define CONSOLE_H
#include <sstream>
#include <exception>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class console_t : public std::ostream, public sf::Drawable {
    std::stringbuf buf;

    sf::Font ttf;
public:
    bool visible;

    console_t() : std::ostream(&buf), visible(false) {
        ttf.loadFromFile( "font1.ttf" );
    }

    // throw() because Microsoft Visual Studio is a piece of shit
    ~console_t() throw() { // someone? Please kill Microsoft
    }

    void draw( sf::RenderTarget &target, sf::RenderStates states ) const;
};

extern console_t console;

#endif /* CONSOLE_H */
