#include<SDL.h>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

void draw_point(SDL_Renderer*renderer, vector<double> in, vector<int>color, int type=1)
{

    SDL_SetRenderDrawColor(renderer, color[0],color[1],color[2], 255);
    SDL_Rect X={int(in[0]),int(in[1]), int (5), int(5)};
    if (type==2)
    {
        X={int(in[0]),int(in[1]), 10, 10};
    }
    SDL_RenderFillRect(renderer,&X);
    SDL_RenderPresent(renderer);

};





