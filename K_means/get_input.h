#include<SDL.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<double>>Get(SDL_Renderer*renderer)
{
    vector<vector<double>> result;
    SDL_Rect X;
    SDL_Event e;
    SDL_SetRenderDrawColor(renderer, 150,150,150, 255);

    bool stop=false;
    while(!stop)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT||e.type==SDL_KEYDOWN)
                {
                    return result;
                }
            else if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                vector<double>Y;
                Y.push_back(double(x));
                Y.push_back(double(y));
                result.push_back(Y);
                X={x,y,5,5};
                SDL_RenderFillRect(renderer,&X);
                SDL_RenderPresent(renderer);
            }
        }
    }


}

