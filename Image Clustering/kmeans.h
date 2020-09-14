// written by Nguyen Minh Quang
#ifndef Kmeans
#define Kmeans
#include "pre_processing.h"
#define Max_iterator 20


vector<vector<Image>> kmeans(const vector<Image> &in,vector<Image>&center, int k=10,SDL_Renderer*renderer=nullptr)
{
    vector<vector<Image>>result;
    int label[in.size()]={0};
    result.resize(k);
    center.resize(0);
    for(int i=0;i<k;i++)
        center.push_back(in[i]);
    int count=0;
    bool updated=true;
    while(count<Max_iterator && updated)
    {
        count++;
        updated=false;
        for(int i=0;i<k;i++) result[i].resize(0);
        int Coe=0;
        for(auto pos: in)
        {
            double Min_dis{distance(pos,center[0])},temp_dis;
            int new_label=0;
            for(int i=1;i<k;i++)
            {
                temp_dis=distance(pos,center[i]);
                if(temp_dis<Min_dis)
                {
                    Min_dis=temp_dis;
                    new_label=i;
                };
            }
            result[new_label].push_back(pos);
            if(new_label!=label[Coe])
            {
                label[Coe]=new_label;
                updated=true;
            };
            Coe++;
        }
        for(int i=0;i<k;i++)
        {
            center[i]=find_center(result[i]);
            cout<<"center: "<<i<<endl;
        if(renderer!=nullptr)    center[i].show(renderer);
        }

    }
    return result;
}

#endif // kmeans
