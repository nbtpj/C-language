#include<fstream>
#include"kmeans.h"


int main(int argv, char*argc[])
{
    SDL_Renderer*renderer;
    SDL_Window*window;
    SDL_Init(SDL_INIT_EVERYTHING);

    ifstream f("dataset2.txt");
    ofstream F("result.txt");
    ofstream Center("center.txt");
    vector<Image> in;
    Image temp;
    while(f>>temp)
    {
       in.push_back(temp);
       cout<<in.size()<<endl;
    }
    f.close();
    SDL_CreateWindowAndRenderer(800,800,SDL_WINDOW_SHOWN|SDL_WINDOW_MOUSE_FOCUS,&window,&renderer);
    vector<Image>center;
    vector<vector<Image>> result=kmeans(in,center,10,renderer);

    int H=0;
    for(auto mem: center)
    {
        cout<<"cluster:"<<H<<endl;
        Center<<mem<<endl;
        H++;
        mem.show(renderer);
    }
    for(auto mem:result)
    {
        for(auto M:mem)
        {
            F<<M<<endl;
        }
    }

    F.close();
    Center.close();
    SDL_Quit();
    return 0;


}











/*  int pos=0;

    while(in.size()>0)
    {
     //   cout<<"Sorting\n";
     //   in[pos].show(renderer);
        result.push_back(in[pos]);
        F<<in[pos]<<endl;
        in.erase(in.begin()+pos);
        Image x{result[result.size()-1]};
        pos=0;
        if(in.size()>0)
        {
            double dis= distance(x, in[0]);
            for(int i=1;i<in.size();i++)
            {
                double D{distance(x, in[i])};
                if(dis>D)
                {
                    pos=i;
                    dis=D;
                }
            }
        }
    }
    cout<<"sorting :done\n";*/
