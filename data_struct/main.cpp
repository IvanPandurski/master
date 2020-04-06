//#include "ArrayADT.cpp"
#include <stdio.h>
//#include "menudriverprogramarrays.h"
//#include "Stack.cpp"

//#include "InfixToPostfix.h"
//#include "binarytreegenerator.h"
//#include "SDL.h"
//#include "GL/gl.h"
#include "sorting.h"
#include "hashing.h"
#include "graph.h"
#include <iostream>
int main(int argc, char *argv[])
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    std::cout << "Following is Depth First Traversal"
                " (starting from vertex 2) \n";
    g.DFS(2);




//    SDL_Window *window;                    // Declare a pointer

//        SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

//        // Create an application window with the following settings:
//        window = SDL_CreateWindow(
//            "An SDL2 window",                  // window title
//            SDL_WINDOWPOS_UNDEFINED,           // initial x position
//            SDL_WINDOWPOS_UNDEFINED,           // initial y position
//            640,                               // width, in pixels
//            480,                               // height, in pixels
//            SDL_WINDOW_OPENGL                  // flags - see below
//        );

//        // Check that the window was successfully created
//        if (window == NULL) {
//            // In the case that the window could not be made...
//            printf("Could not create window: %s\n", SDL_GetError());
//            return 1;
//        }

//        // The window is open: could enter program loop here (see SDL_PollEvent())

//        SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

//        // Close and destroy the window
//        SDL_DestroyWindow(window);

//        // Clean up
//        SDL_Quit();


    return 0;
}
