Hi
this small project took me nearly a day to finish, so I think, personally, the algorithm I did use is not the best one. All I did is translating algorithm from google into C++ language.

You can reuse these codes, I don't have any problem with this. hopefully they can help you

Because I am so lazy :(((, there is  still no update :(

I will explain my code below ( just 2 function I think important) :

> note: please download the SDL2.dll to run the code

**visual.h**: to draw point using SDL2 library

    void draw_point(SDL_Renderer*renderer, vector<double> in, vector<int>color, int type=1)
    // vector include the data of the point, it can be seen as point
    // type : 1 for normal point, and 2 for the center
    // vector color: index of red, green, blue 
**K_means.h**: the algorithm to  split data set into k cluster
 

    vector<vector <vector<double>>> K_mean(SDL_Renderer*renderer,vector<vector<double>> in,int k=3, int n=2)
    // return K clusters, each cluster helds points
    // and in this function, it will visualize its steps
