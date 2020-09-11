//written by Nguyen Minh Quang

#include"pre_proccessing.h"
#include"visual.h"

vector<vector<vector<long double>>> hc(SDL_Renderer*renderer,vector<vector<long double>>in, int k=1, int height=800, int width =1000)
{
    int number_of_clusters=in.size();
    vector<vector<vector<long double>>> result;
    vector<vector<long double>>centers;


    result.resize(in.size());
    for(int i=0;i<in.size();i++)
    {
        result[i].push_back(in[i]);
    };
    cout<<"check\n";
    while(result.size()>k)
    {
        centers.resize(0);
        for(auto mem: result)
        {
            centers.push_back(Find_Center(mem));
        }
        long double min=Distance(centers[0],centers[1]);
        int pair_1=0,pair_2=1;

        for(int i=0;i<centers.size()-1;i++)
        {
            for(int j=i+1;j<centers.size();j++)
            {

                long double x=Distance(centers[i],centers[j]);
                if(min>x)
                {
                    min=x;
                    pair_1=i;
                    pair_2=j;
                }
            }
        }

        for(auto mem:result[pair_2])
        {
            result[pair_1].push_back(mem);
        }
        result.erase(result.begin()+pair_2);
        for(auto mem:result)
        {
            Draw(renderer,mem,{rand()%255,rand()%255,rand()%255});
        }

    }
    return result;
}
