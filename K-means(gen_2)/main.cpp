/* written by Nguyen Minh Quang */

#include "kmeans.h"

SDL_Window*window=nullptr;
SDL_Renderer*renderer=nullptr;

int main(int argv, char*argc[] )
{
    SDL_Init(SDL_INIT_EVERYTHING);
    cout<<"choose the number of cluster:\n";
    int k;
    cin>>k;

    cout<<"choose how you enter your data:\n0 . your own points\n1 . auto generate\n2 . from file (numberic txt file only)\n";
    int n;
    cin>>n;

    vector<vector<long double>> in;
    switch(n)
    {
    case(0):
        SDL_CreateWindowAndRenderer(800,800,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);
        in=Get_Points(renderer);
        break;
    case(1):
        SDL_CreateWindowAndRenderer(800,800,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);
        in=Gen_Points(renderer);
        break;
    case(2):
        cout<<"enter file name:\n";
        string file;
        cin>>file;
        ifstream f(file);
        in=Load(f);
        f.close();
        SDL_CreateWindowAndRenderer(800,800,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);
        break;

    };



    Kmeans(renderer,in,k);
    wait();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
