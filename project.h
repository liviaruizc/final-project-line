//
// Created by Livia on 6/20/2024.
//

#ifndef PROJECT_H
#define PROJECT_H

// GLOBAL CONSTANTS AND DATA STRUCTURES
// ------------------------------------------------------------

const unsigned int FRAME_RATE = 60;

const unsigned WIN_WIDTH = 600; // Window width
const unsigned WIN_HEIGHT = 400; // Window height

enum MenuOption { // Different methods of calculating the line
    TwoPointMethod = 1,
    PointSlopeMethod,
    PrintLine,
    DrawLine,
    Exit
};

// Defining the data type Point
struct Point {
    int x{};
    int y{};
};



#endif //PROJECT_H
