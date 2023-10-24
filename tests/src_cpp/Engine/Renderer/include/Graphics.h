/*
 *  Copyright (C) 2020-2021 Xios
 *
 *  This file is part of Hoopoe-Engine.
 *
 *  Hoopoe-Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Hoopoe-Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Hoopoe-Engine.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef __ENGINE_RENDERER_GRAPHICS_H__
#define __ENGINE_RENDERER_GRAPHICS_H__

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

namespace Hoopoe 
{

class Graphics 
{
public:
    Graphics();

    SDL_Window *get_window();
    SDL_Renderer *get_renderer();
    int get_TILE();
    int get_SCREEN_WIDTH();
    int get_SCREEN_HEIGHT();

    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h);
    void renderTexture(SDL_Texture *texture, int x, int y);
    SDL_Texture *loadTexture(const string file);

    void renderBackground(SDL_Texture *texture);

    ~Graphics();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int TILE;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};

}

#endif
