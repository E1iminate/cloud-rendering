/*************************************************************************
* Copyright 2025 Vladislav Riabov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*************************************************************************/

#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a resizable window
    SDL_Window* window = SDL_CreateWindow(
        "Minimal SDL3 App",
        800, 600,
        SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Get the window surface
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (e.type == SDL_EVENT_KEY_DOWN &&
                e.key.key == SDLK_ESCAPE) {
                running = false;
            }
        }

        // Fill with a color (RGB: 70, 130, 180 = SteelBlue)
        SDL_FillSurfaceRect(surface, nullptr,
                            SDL_MapRGB(SDL_GetPixelFormatDetails(surface->format), SDL_GetSurfacePalette(surface), 70, 130, 180));
        SDL_UpdateWindowSurface(window);

        SDL_Delay(16); // ~60 fps
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}