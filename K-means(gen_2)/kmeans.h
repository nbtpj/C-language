/* written by Nguyen Minh Quang */

#include "pre_proccessing.h"
#include "visual.h"
#define STOP 1
#define MAX_LOOP 99999

vector<vector<vector<long double>>> Kmeans(SDL_Renderer*renderer,vector<vector<long double>>in, int k=3, int height=800, int width =800)
{
    cout<<"press any key to stop the program\n";
    vector<vector<vector<long double>>>result;
    result.resize(k);
    vector<vector<long double>>centers;
    srand(time(NULL));
    long double aver= double(height/k);
    do
    {
        while(centers.size()<k)
        {
        int x=rand()%width, y=rand()%height;
        vector<long double> X={double(x), double(y)};
        bool add=true;
        for(auto mem: centers)
        {
            if(Distance(mem,X)<aver)
            {
                add=false; break;
            };
        }
        if (add) centers.push_back(X);
        }
    }  while(!Valid_Center(in,centers));
    vector<vector<int>>colors;
    for(int i=0;i<k;i++)
    {
        colors.push_back({rand()%255,rand()%255,rand()%255});
    }
    int Count=0;
    long double s1=99999999999, s2;
    bool stop=false, rechoose=false;
    do
    {

        Count++;
        for(auto mem: result)
            mem.resize(0);
        for(auto mem: in)
        {
            int index= Closest_Center(mem, centers);
            if(!Draw_Point(renderer,mem,colors[index]))
            {
                stop=true;
            }
            result[index].push_back(mem);
        };
        s2=0;
        for(int i=0;i<k;i++)
        {
            vector<long double> new_center;
            new_center=Find_Center(result[i]);
            s2+=Distance(centers[i],new_center);
            centers[i]=new_center;\
            if(!Draw_Point(renderer,centers[i],colors[i],2))
            {
                stop=true;
            }

        };
        if(s1==s2||Key_Down())
            {
                stop=true;
            }
        s1=s2;
        if(stop) cout<<"stop:yes\n";

    }
    while((!stop)&&(Count<MAX_LOOP));


    return result;
}
