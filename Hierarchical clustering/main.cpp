/* written by Nguyen Minh Quang */

#include "hc.h"

SDL_Window*window=nullptr;
SDL_Renderer*renderer=nullptr;

int main(int argv, char*argc[] )
{

    SDL_Init(SDL_INIT_EVERYTHING);
    int k=7;
    vector<vector<long double>> in;
    ifstream f("dataset1.txt");
    in=Load(f);
    f.close();
    SDL_CreateWindowAndRenderer(1000,800,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);
    Normalize(in,800);
    Draw(renderer,in);
    vector<vector<vector<long double>>> XX=hc(renderer,in,k,800,1000);
    wait();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
