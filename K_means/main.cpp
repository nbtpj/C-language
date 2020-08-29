#include"k_means.h"
#include<time.h>
#include<cstdlib>
#include"get_input.h"

using namespace std;
SDL_Renderer*renderer=NULL;
SDL_Window*window=NULL;


int main(int argc, char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(700,700,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);

    {
        vector <vector<double>> in=Get(renderer);
    for(auto mem : in)
    {
        for(auto x : mem) cout<<x<<' ';
        cout<<endl;
    }

    vector<vector<vector<double>>> X=K_mean(renderer,in,4);
        // hey, the 4 hey u can change to any value you want providing it is an interger bigger than 0
    SDL_Event e;
    while(true)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT)
            {
                SDL_Quit();
                return 0;
            }
        };
    };
    };
    // delay to see the result, 

}
