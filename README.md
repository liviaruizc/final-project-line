# CMake SFML Project Template

This repository template should allow for a fast and hassle-free kick start of your next SFML project using CMake.
Thanks to [GitHub's nature of templates](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template), you can fork this repository without inheriting its Git history.

The template starts out very basic, but might receive additional features over time:

- Basic CMake script to build your project and link SFML on any operating system
- Basic [GitHub Actions](https://github.com/features/actions) script for all major platforms

## How to Use

1. Install Git and CMake. Use your system's package manager if available.
1. Follow the above instructions about how to use GitHub's project template feature to create your own project.
1. Clone your new GitHub repo and open the repo in your text editor of choice.
1. Open [CMakeLists.txt](CMakeLists.txt). Rename the project and the executable to whatever name you want.
1. If you want to add or remove any .cpp files, change the source files listed in the [`add_executable`](CMakeLists.txt#L10) call in CMakeLists.txt to match the source files your project requires. If you plan on keeping the default main.cpp file then no changes are required.
1. If you use Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
    ```
    sudo apt update
    sudo apt install \
        libxrandr-dev \
        libxcursor-dev \
        libudev-dev \
        libfreetype-dev \
        libopenal-dev \
        libflac-dev \
        libvorbis-dev \
        libgl1-mesa-dev \
        libegl1-mesa-dev
    ```
1. Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.
    - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
    - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
    - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
    - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

    Using CMake from the command line is straightforward as well.

    For a single-configuration generator (typically the case on Linux and macOS):
    ```
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build
    ```

    For a multi-configuration generator (typically the case on Windows):
    ```
    cmake -S . -B build
    cmake --build build --config Release
    ```
1. Enjoy!

## Upgrading SFML

SFML is found via CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) module.
FetchContent automatically downloads SFML from GitHub and builds it alongside your own code.
Beyond the convenience of not having to install SFML yourself, this ensures ABI compatability and simplifies things like specifying static versus shared libraries.

Modifying what version of SFML you want is as easy as changing the [`GIT_TAG`](CMakeLists.txt#L7) argument.
Currently it uses the latest in-development version of SFML 2 via the `2.6.x` tag.
If you're feeling adventurous and want to give SFML 3 a try, use the `master` tag.
Beware, this requires changing your code to suit the modified API!
The nice folks in the [SFML community](https://github.com/SFML/SFML#community) can help you with that transition and the bugs you may encounter along the way.

## But I want to...

Modify CMake options by adding them as configuration parameters (with a `-D` flag) or by modifying the contents of CMakeCache.txt and rebuilding.

### Use Static Libraries

By default SFML builds shared libraries and this default is inherited by your project.
CMake's [`BUILD_SHARED_LIBS`](https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html) option lets you pick static or shared libraries for the entire project.

### Change Compilers

See the variety of [`CMAKE_<LANG>_COMPILER`](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER.html) options.
In particular you'll want to modify `CMAKE_CXX_COMPILER` to point to the C++ compiler you wish to use.

### Change Compiler Optimizations

CMake abstracts away specific optimizer flags through the [`CMAKE_BUILD_TYPE`](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html) option.
By default this project recommends `Release` builds which enable optimizations.
Other build types include `Debug` builds which enable debug symbols but disable optimizations.
If you're using a multi-configuration generator (as is often the case on Windows), you can modify the [`CMAKE_CONFIGURATION_TYPES`](https://cmake.org/cmake/help/latest/variable/CMAKE_CONFIGURATION_TYPES.html#variable:CMAKE_CONFIGURATION_TYPES) option.

### Change Generators

While CMake will attempt to pick a suitable default generator, some systems offer a number of generators to choose from.
Ubuntu, for example, offers Makefiles and Ninja as two potential options.
For a list of generators, click [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).
To modify the generator you're using you must reconfigure your project providing a `-G` flag with a value corresponding to the generator you want.
You can't simply modify an entry in the CMakeCache.txt file unlike the above options.
Then you may rebuild your project with this new generator.

## More Reading

Here are some useful resources if you want to learn more about CMake:

- [How to Use CMake Without the Agonizing Pain - Part 1](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-1.html)
- [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
- [Better CMake YouTube series by Jefferon Amstutz](https://www.youtube.com/playlist?list=PL8i3OhJb4FNV10aIZ8oF0AA46HgA2ed8g)

## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.

# Line Drawing and Calculation Program

## Overview
This C++ program calculates and visualizes a line defined by two points provided by the user. The program offers different methods to calculate properties of the line, such as slope, y-intercept, distance, and angle. Additionally, it allows drawing the line on a graphical window using the SFML (Simple and Fast Multimedia Library) graphics library.

## Features
- **Two-point method**: Allows the user to input two points and calculate the line properties.
- **Point-slope method**: Allows the user to input a point and a slope to calculate the line's equation.
- **Print line properties**: Prints the slope, y-intercept, distance between points, and angle of the line.
- **Draw line**: Visualizes the line using SFML in a graphical window.

## Program Flow
1. **Two-point method**: The user enters two points, and the program calculates the slope and other properties.
2. **Point-slope method**: The user enters a point and the slope to determine the line's equation.
3. **Print line**: Prints the slope, y-intercept, distance between the points, and angle of the line.
4. **Draw line**: Displays the line on a graphical window using SFML.

## Code Structure
The project contains the following main files:

### `Line.h`:
Defines the `Line` class, which handles the calculation and drawing of lines. It includes member functions to:
- Calculate the slope of the line.
- Calculate the y-intercept, distance, and angle.
- Draw the line on an SFML window.

### `Line.cpp`:
Implements the methods defined in `Line.h`. Contains constructors and functions for creating lines and calculating various properties.

### `project.h`:
Contains global constants, data structures (such as `Point`), and an enumeration for menu options.

### `line_project.cpp`:
Contains the main program logic, user interaction, and a menu for selecting line operations. This is where the user inputs data, and different operations are performed based on the user's choices.

### `SFML/Graphics.hpp`:
The program uses SFML for rendering the graphical window and drawing the line.

## Installation

### Requirements
- **SFML**: Ensure you have the SFML library installed on your system.
- A C++ compiler (e.g., `g++` or `clang++`).

### Compilation
1. Save all the source files in your project directory.
2. Install SFML and link it to your project.
3. Compile the program using a C++ compiler:
   ```bash
   g++ -o line_project line_project.cpp -lsfml-graphics -lsfml-window -lsfml-system

## Running the Program
Upon running the program, a menu will appear asking the user to choose an option:

Two-point method: Enter two points to define the line.

Point-slope method: Enter a point and slope to define the line.

Print line: Print the line properties.

Draw line: Visualize the line in an SFML window.

Exit: Exit the program.

## Sample Output
Menu Options:

Type 1, 2, 3, 4 or 5 to pick one of the options:
1 - Two-point method
2 - Point-slope method
3 - Print line
4 - Draw line
5 - Exit
Choice: 1
Enter x: 10
Enter y: 20
Enter x: 30
Enter y: 40
Slope: 1
Y-Intercept: 10
Distance of points: 28.2843
Angle of line: 0.785398
Graphical Window:
When the user selects the Draw line option, an SFML window will open and display the line calculated based on the chosen method.

## Dependencies
SFML (Simple and Fast Multimedia Library): Required for graphical rendering.

Install SFML from here.

Link the SFML libraries (sfml-graphics, sfml-window, sfml-system) during compilation.
