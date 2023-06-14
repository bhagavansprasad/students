#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define VERTEX_RADIUS 20

struct Vertex {
    int x;
    int y;
};

void displayGraph(SDL_Renderer* renderer, struct Vertex vertices[], int numVertices, int adjacencyMatrix[][numVertices]) {
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw edges
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                SDL_RenderDrawLine(renderer, vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y);
            }
        }
    }

    // Draw vertices
    for (int i = 0; i < numVertices; i++) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect vertexRect = {vertices[i].x - VERTEX_RADIUS / 2, vertices[i].y - VERTEX_RADIUS / 2, VERTEX_RADIUS, VERTEX_RADIUS};
        SDL_RenderFillRect(renderer, &vertexRect);
    }

    // Render the updated scene
    SDL_RenderPresent(renderer);
}

int main() {
    int numVertices = 6;
    struct Vertex vertices[] = {{100, 100}, {200, 200}, {300, 100}, {400, 200}, {500, 100}, {600, 200}};
    int adjacencyMatrix[][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Graph Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Display the graph
        displayGraph(renderer, vertices, numVertices, adjacencyMatrix);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

