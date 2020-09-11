/* written by Nguyen Minh Quang */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<SDL.h>
using namespace std;

// draw point
bool Draw_Point(SDL_Renderer*renderer, vector<long double>Point, vector<int>color, int type=1)
{
    SDL_Event e;
    while(SDL_PollEvent(&e)!=0)
    {
        if(e.type== SDL_QUIT)
            return false;
    }
    SDL_SetRenderDrawColor(renderer,color[0],color[1],color[2],255);
    SDL_Rect X;
    if(type==1)
    {
        X={int(Point[0]), int(Point[1]),5,5};
    }
    else{
        X={int(Point[0]), int(Point[1]),10,10};
    }
    SDL_RenderDrawRect(renderer, &X);
    SDL_RenderPresent(renderer);
    return true;
}

// get input by clicking mouse
vector<vector<long double>> Get_Points(SDL_Renderer*renderer)
{
    SDL_Event e;
    int x,y;
    SDL_Rect X;
    bool stop=false;
    X.h=5;
    X.w=5;
    vector<vector<long double>>result;
    std::cout<<"press any key to stop !\n";
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    while(!stop)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type== SDL_QUIT|| e.type==SDL_KEYDOWN)
            {
                stop=true;
            }
            else
            {
                if(e.type==SDL_MOUSEBUTTONDOWN)
                {
                    SDL_GetMouseState(&x,&y);
                    X.x=x;
                    X.y=y;
                    result.push_back({double(x), double(y)});
                    SDL_RenderDrawRect(renderer,&X);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
    return result;
};

// auto generate input
vector<vector<long double>> Gen_Points(SDL_Renderer*renderer, int max_number=1000, int height=800, int width=800)
{
    SDL_Event e;
    int x,y;
    SDL_Rect X;
    bool stop=false;
    X.h=5;
    X.w=5;
    int Count = max_number;
    vector<vector<long double>>result;
    std::cout<<"press any key to stop !\n";
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    srand(time(NULL));
    while(!stop)
    {
        if(Count<=0)
        {
            stop=true;
        }
        while(SDL_PollEvent(&e)!=0)
        {
            if((e.type== SDL_QUIT)||( e.type==SDL_KEYDOWN))
            {
                stop=true;
            }
        }
        Count-=1;
        x=rand()*rand()%(width-10)+5;
        y=rand()%(height-10)+5;
        X.x=x;
        X.y=y;
        result.push_back({double(x), double(y)});
        SDL_RenderDrawRect(renderer,&X);
        SDL_RenderPresent(renderer);

    }
    return result;
};

// wait until keydow
void wait()
{
    SDL_Event e;
    bool stop =false;
    while(!stop)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if((e.type== SDL_QUIT)||( e.type==SDL_KEYDOWN))
            {
                stop=true;
            }
        }
    }
}

// draw chart
void Draw(SDL_Renderer*renderer,vector<vector<long double>>in,vector<int>color={255,255,255} )
{
    for(auto mem:in)
    {
            Draw_Point(renderer,mem,color);

    }
}

// key down event
bool Key_Down()
{

    SDL_Event e;
    while(SDL_PollEvent(&e)!=0)
        {
            if((e.type== SDL_QUIT)||( e.type==SDL_KEYDOWN))
            {
                return true;
            }
        }
    return false;
}

