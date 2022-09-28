#include "Ball.h"

Ball::Ball(float startX, float startY){
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(Vector2f(20,20));
    m_Shape.setPosition(m_Position);
}
FloatRect Ball::getPosition() {
    return m_Shape.getGlobalBounds();
}
RectangleShape Ball::getShape() {
    return m_Shape;
}
float Ball::getXVelocity() {
    return m_DirectionX;
}
void Ball::reboundSides() {
    m_DirectionX = -m_DirectionX;
}
void Ball::reboundTop() {
    m_DirectionY = -m_DirectionY;
    m_Speed += 1;
}
void Ball::reboundBat() {
    m_DirectionY = -m_DirectionY;
    //m_Speed += 1;
}
void Ball::reboundBottom() {
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirectionY = -m_DirectionY;
}
void Ball::update(Time dt) {
    // Update the Ball's position
    m_Position.y += m_DirectionY*m_Speed*dt.asSeconds();
    m_Position.x += m_DirectionX*m_Speed*dt.asSeconds();

    // Move the Ball
    m_Shape.setPosition(m_Position);
}
void Ball::reset(float startX, float startY){
    m_Position.x = startX;
    m_Position.y = startY;
    m_Speed = 2000;
}
