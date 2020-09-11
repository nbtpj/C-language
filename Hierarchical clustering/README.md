
**HI**

**This small project is about clustering by Hierarchical clustering**

I do not highly  appreciate about this project because I did just reuse the code in the last project (K-means (gen_2)) without changing anything, and my algorithm is not the best one. Sorry about that problem if you feel it not worth at visiting those codes

**On the other hand**, It 's result is **True**. That maybe enough for a project having taken me 15 minutes to complete :(

**let 's start**
what new I added here is the hc function, in "hc.h" file:

 

     vector<vector<vector<long double>>> hc(SDL_Renderer*renderer,vector<vector<long double>>in, int k=1, int height=800, int width =1000)
    {
        int number_of_clusters=in.size();
        vector<vector<vector<long double>>> result;
        vector<vector<long double>>centers;
        result.resize(in.size());
    // initialize something we need
        
        for(int i=0;i<in.size();i++)
        {
            result[i].push_back(in[i]);
        };
    // initialize begining clusters, each cluster held only one data point
        
        while(result.size()>k)
    // while the number of clusters is bigger than we want
        {
            centers.resize(0);
            for(auto mem: result)
            {
                centers.push_back(Find_Center(mem));
            }
            // find the center for each cluster
            
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
    // find 2 nearest clusters (by their centers)
    
            for(auto mem:result[pair_2])
            {
                result[pair_1].push_back(mem);
            }
            result.erase(result.begin()+pair_2);
    // and unify them
    
            for(auto mem:result)
            {
                Draw(renderer,mem,{rand()%255,rand()%255,rand()%255});
            }
    // visualization
    
        }
        return result;
    }

*hopefully you can understand my stupid explain. if you hava any question, please leave me some comments. thank you <3*
