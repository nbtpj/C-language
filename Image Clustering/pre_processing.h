//written by Nguyen Minh Quang
#ifndef pre_processing
#define pre_processing

#include<SDL.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include <iomanip>
using namespace std;

class Image
{
private:
    double value[28][28];
public:
    Image()
    {
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++) value[i][j]=0;
        }
    };

    double length()
    {
        long result=0;
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
                result+=value[i][j]*value[i][j];
        }
        return pow(result,0.5);
    }
    friend istream& operator >>(istream&in, Image& x)
    {
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
                in>>x.value[i][j];
        }
        return in;
    }
    friend ostream& operator <<(ostream&out, Image x)
    {
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
                out<<setw(4)<<x.value[i][j];
                out<<endl;
        }
        out<<endl;
        return out;
    }
    friend double distance(Image x, Image y)
    {
        double result=0;
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
                result+=pow(x.value[i][j]-y.value[i][j],2);
        }
        return pow(result,0.5);
    }
    void show(SDL_Renderer*renderer)
    {
        SDL_Rect x;
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
            {
                SDL_SetRenderDrawColor(renderer,(int)value[i][j],(int)value[i][j],(int)value[i][j],255);
                x={j*20,i*20,20,20};
                SDL_RenderFillRect(renderer,&x);
                SDL_RenderPresent(renderer);
            }
        }
    }
    friend Image find_center(vector<Image>in){

    Image center;
    double size=(double)in.size();
    for(auto mem:in)
    {
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
            {
                center.value[i][j]+= mem.value[i][j]/size;
            }
        }
    }
    return center;
    };

};


























#endif // pre_processing
