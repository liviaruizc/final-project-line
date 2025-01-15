//
// Created by Livia on 6/20/2024.
//
#include "project.h"
#ifndef LINE_H
#define LINE_H

class Line { // Defining object properties

private: // Access specifier

    Point point1;
    Point point2;
    float slope;

public: // Access specifier


    // Constructors
    // ---------------------------------------------

    // Default
    Line ();

    // Property constructors
    // ----------------------------------------------
    Line (Point point1_in, Point point2_in);

    Line (Point point1_in, float slope);

    // Member Function Declarations
    // --------------------------------------------
    bool isEmpty ();
    float calcSlope() const;
    float calculateYIntercept () const;
    float calculateDistance () const;
    float calculateAngle () const;
    void draw (sf::RenderWindow &window);

};





#endif //LINE_H
