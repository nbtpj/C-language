#ifndef k_means.h
// K means
#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include"visual.h"
#define STOP 5
using namespace std;

// this function below returns the Chebyshev distance between two data points
    long double Distance(vector<double> a, vector<double>b, int n=2)
    {
        long double s=0;
        for(int i=0;i<a.size();i++)
        {
            s+= pow(a[i]-b[i],double(n));
        }
        return pow(s,1/double(n));
    }
// this function below returns the minimum value in a vector
    template <typename T>
    T MIN( vector<T> x)
    {
        sort(x.begin(), x.end());
        return x[0];
    }
// this function below returns the maximum value in a vector
    template <typename T>
    T MAX( vector<T> x)
    {
        sort(x.begin(), x.end());
        return x[x.size()-1];
    }
// find the new center
    vector<double> Center(vector<vector<double>> in)
    {
        double x= double(in.size());
        vector<double> result, Sum(in[0].size(), 0);
        for( auto mem: in)
        {
            for(int i=0;i<mem.size();i++) Sum[i]+=mem[i];

        }
        for(int i=0;i<Sum.size();i++) result.push_back(Sum[i]/x);
        return result;
    }
// k means
    vector<vector <vector<double>>> K_mean(SDL_Renderer*renderer,vector<vector<double>> in,int k=3, int n=2)
    {
        long double sum1=20000000,sum2;
        int N(int(in.size()));
        srand(time(NULL));
        int M =0;
        vector<vector<vector<double>>> result;
        result.resize(k);
        vector<int> cluster(N, -1);
        for (int i=0;i<in.size();i++)
        {
            double X=MAX<double>(in[i]);
            if(M<X) M=X;
        };
        vector<vector<double>> centers;
        for (int i=0;i<k;i++)
        {
            vector<double>X;
            for(int i=0;i<in[0].size();i++) X.push_back(rand()% M);
            centers.push_back(X);
        };
        //centers={{202,458},{410,217},{159,210},{408,391},{282,132}};





        vector<vector<int>> colors;
        for(int i=0;i<k;i++)
        {
            vector <int> X;
            for(int i=0;i<3;i++) X.push_back(rand()%255);
            colors.push_back(X);
        };
        //cout<<"initializing done!"<<endl;
        bool updated= true;
        SDL_Event e;
        while(updated)
        {
            sum2=0;
            while(SDL_PollEvent(&e)!=0)
            {
                if(e.type==SDL_QUIT){return result;}
            };

            // update cluster
            for (auto mem: result)
            {
                mem.resize(0);
            };
            // cout<<"update result: done!\n";
            // update point
            for(int i=0;i<in.size();i++)
            {
                int temp=0;
                long double Min{Distance( in[i], centers[0])};

                for (int j=1;j<centers.size();j++)
                {
                    double D=Distance(in[i], centers[j]);
                    if (D< Min)
                    {
                        Min=D;
                        temp=j;
                    };
                };
                sum2+=Min;
                result[temp].push_back(in[i]);
                draw_point(renderer, in[i],colors[temp]);
                if (temp!=cluster[i])
                {
                    updated=true;
                    cluster[i]=temp;
                };

            };
            if(sum1-sum2<=STOP)
            {
                return result;
            }
            else
                { sum1=sum2;};
            // cout<<"update center for each point: done!\n";
            // update center
            //SDL_RenderClear(renderer);

            for(int i=0;i<centers.size();i++)
            {
                centers[i]=Center(result[i]);
                draw_point(renderer, centers[i],colors[i],2);
                for (auto x : centers[i]) cout<<x<<';';
                cout<<endl;
            };

             cout<<"update center: done!\n";

        };

    return result;
    };
    //load data
    vector<vector<double>> load(istream & in, int n=2)
    {

        vector<vector<double>>result;
        vector<double> a;
        double x;

        while(in>>x)
        {
            if(a.size()==n)
            {
                result.push_back(a);
                a.resize(0);
            };
            a.push_back(x);
        };
        return result;
    }







#endif // k_means
