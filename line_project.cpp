// line_project.cpp
// COP 2006 Summer 2024
// Livia Correia
// Program calculates, prints and draws a line that is defined by two points from user
// Program also calculates slope, y-intercept, distance and angle of line.
// -------------------------------------------------------------------------


#include <SFML/Graphics.hpp>
#include <iostream>
#include <variant>

#include "Line.h"
#include "project.h"


// Functions declarations
// ------------------------------------------

Point getPoint();
float getSlope();
void printLine(Line& line);
void drawLine(Line& line);

// Functions definitions
// ------------------------------------------

int main()
{

    // Variable declarations
    int choice;
    Line line;
    Point point1;
    Point point2;
    float slope;

        while (choice != Exit) { // Condition to exit loop

            std::cout << "Type 1, 2, 3, 4 or 5 to pick one of the options: \n" // Asking user to choose a method
                         "1 - Two-point method \n"
                         "2 - Point-slope method \n"
                         "3 - Print line \n"
                         "4 - Draw line \n"
                         "5 - Exit\n"
                         "Choice: ";
            std::cin >> choice;

            switch (choice) {
                case TwoPointMethod:
                    point1 = getPoint(); // Get return from getPoint
                    point2 = getPoint();
                    line = Line(point1,point2); // Reset line to new point1 and point2
                    slope = line.calcSlope();
                break;

                case PointSlopeMethod:
                    point1 = getPoint();
                    slope = getSlope(); // Get return from getSlope
                    point2 = {0, int(line.calculateYIntercept())}; // Calculates YIntercept
                    line = Line(point1, point2); // Resets line
                break;

                case PrintLine:
                    line = Line(point1, point2);
                    printLine(line);
                    break;

                case DrawLine:
                    drawLine(line);
                    break;
            } // switch

        } // end while loop
    return 0;
} // end main

Point getPoint () {
    Point pointInFunction;
    std::cout << "Enter x: ";
    std::cin >> pointInFunction.x;
    std::cout << "Enter y: ";
    std::cin >> pointInFunction.y;
    return pointInFunction;
}

float getSlope () {
    float slope;
    std::cout << "Enter slope: ";
    std::cin >> slope;
    return slope;
}

void printLine(Line &line) {
    if (!line.isEmpty()) {
        float slope = line.calcSlope();
        std::cout << "Slope: " << slope << "\n Y-Intercept: " << line.calculateYIntercept() << "\n Distance of points: " <<
            line.calculateDistance() << "\n Angle of line: " << line.calculateAngle() << "\n";
    }
}

void drawLine (Line &line) {

    if (!line.isEmpty()) {
        sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Line Drawer"); // Creates window

        while (window.isOpen()) {

            for (auto event = sf::Event{}; window.pollEvent(event);)
            {

                if (event.type == sf::Event::Closed)
                {

                    window.close();
                }
            }

            window.clear();

            line.draw(window);

            window.display();
        }
    }
}

