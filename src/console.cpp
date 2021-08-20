#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "console.h"

console_t console;

void console_t::draw( sf::RenderTarget &target, sf::RenderStates states ) const {
    if( !visible ) return;

    sf::RectangleShape background;
    sf::Text txt;

    background.setFillColor( sf::Color( 255, 0, 0, 127 ) );
    txt.setColor( sf::Color( 0, 0, 0, 255 ) );

    txt.setFont( ttf );
    txt.setCharacterSize( 12 );

    txt.setString( buf.str() );
    txt.setStyle( sf::Text::Regular );

    // set background to half height of screen
    sf::Vector2u screen_size = target.getSize();
    background.setSize( sf::Vector2f( (float)screen_size.x, (float)screen_size.y/2 ) );

    // set origin of text object to left bottom corner
    sf::FloatRect txt_size = txt.getLocalBounds();
    txt.setOrigin( sf::Vector2f( 0, txt_size.height+txt_size.top ) );

    // set position
    background.setPosition( 0, 0 );
    txt.setPosition( 0, screen_size.y/2 );

    target.draw( background, states );
    target.draw( txt, states );
}
