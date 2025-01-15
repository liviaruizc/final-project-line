//
// Created by Livia on 6/20/2024.
//
#include <SFML/Graphics.hpp>
#include <cmath>
#include "project.h"
#include "Line.h"

#include "../cmake-build-debug/_deps/sfml-src/src/SFML/Window/Win32/CursorImpl.hpp"

// Initializing line to 0
// Default constructor
// -----------------------------------------
Line::Line() { // Setting points and slope to 0
    point1 = {0,0};
    point2 = {0,0};
    slope = 0.f;
}

// Property constructors
// -----------------------------------------
Line::Line(Point point1_in, float slope_in) {
    point1 = point1_in;
    slope = slope_in;
    ; // Calculate Point2 at Y-Intercept
}

Line::Line(Point p1_in, Point p2_in) {
    point1 = p1_in;
    point2 = p2_in;
    slope = calcSlope(); // Calculate slope through 2 points
}

// Member function definitions
// --------------------------------------
bool Line::isEmpty() {
    return point1.x == 0 && point1.y == 0 && point2.x == 0 && point2.y == 0;
}

float Line::calcSlope() const {
    float slope;
    slope = ((point2.y - point1.y)/(point2.x - point1.x));
    return slope;
}

float Line::calculateYIntercept() const {
    float yIntercept = point1.y - (slope * point1.x);
    return yIntercept;
}

float Line::calculateDistance() const {
    float distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    return distance;
}

float Line::calculateAngle() const {
    float angle = atan2(point2.y - point1.y, point2.x - point2.x);
    return angle;
}

// Drawing function for the line
void Line::draw (sf::RenderWindow &window) {

    sf::Vertex line[] =
{
        sf::Vertex(sf::Vector2f(point2.x, WIN_HEIGHT - point2.y)),
        sf::Vertex(sf::Vector2f(point1.x, WIN_HEIGHT - point1.y))
    };

    window.draw(line, 2, sf::Lines);
}







