#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Bat.h"
#include "Ball.h"

using namespace std;
using namespace sf;


int main()
{
    int x = 2880;
    int y = 1800;
    RenderWindow window(VideoMode(x,y), "Pong");
    int score = 0;
    int lives = 3;

    // Bat Instance
    Bat bat(x/2, y - 500);

    // Ball Instance
    Ball ball(x/2, 0);

    Text hud;

    Font font;
    font.loadFromFile("/Users/chatt07/Desktop/cpp_pong/fonts/game_over.ttf");

    hud.setFont(font);
    hud.setCharacterSize(200);
    hud.setFillColor(Color::White);
    hud.setPosition(20,20);

    Clock clock;

    while (window.isOpen()){
        /*
         * Handle Player Input
         */

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            bat.moveLeft();
        } else {
            bat.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            bat.moveRight();
        }
        else {
            bat.stopRight();
        }

        /*
         * Update the bat, ball and hud
         */

        // Update the dt
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // Update the HUD text
        stringstream ss;
        ss << "  Score: " << score << "    Lives: " << lives;
        hud.setString(ss.str());

        // Handle ball hitting the bottom
        if (ball.getPosition().top > window.getSize().y) {
            ball.reboundBottom();
            lives--;
            if (lives < 1){
                score = 0;
                lives = 3;
                ball.reset(x/2, y - 500);
            }
        }

        // Handle ball hitting the top
        if (ball.getPosition().top < 0) {
            ball.reboundTop();
        }

        // Handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
            ball.reboundSides();
        }

        // Has the ball hit the bat?
        if (ball.getPosition().intersects(bat.getPosition())) {
            ball.reboundBat();
            score++;
        }

        /*
         * Draw the bat, ball and hud
         */

        window.clear();

        // All Window Draws
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());

        window.display();
    }
    return 0;
}
