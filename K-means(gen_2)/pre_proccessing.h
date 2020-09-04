/* written by Nguyen Minh Quang */

#include<vector>
#include<math.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;


// modify it according to your using, this function below is an example of euclidean distance in 2D space, return the distance
long double Distance(vector<long double> a, vector<long double> b)
{
    long double result=0;
    for(int i=0;i<a.size(); i++)
    {
        result+=pow(a[i]-b[i],2);
    }
    return pow(result,0.5);
};

//find the center of a cluster in K means (and only K means), return the center
vector<long double> Find_Center(vector<vector<long double>> in)
{
    if(in.size()==0) throw string{"invalid center"};
    vector<long double>result(in[0].size(),0);
    for(auto mem: in)
    {
        for(int i=0;i<mem.size();i++)
        {
            result[i]+=mem[i]/double(in.size());
        }
    };
    return result;
};

//find the best matching center with the point, return the position of this center in the vector of centers
int Closest_Center(vector<long double> point, vector<vector<long double>>centers)
{
    long double min=Distance(point,centers[0]),temp;
    int result=0;
    for(int i=1;i<centers.size();i++)
    {
        temp=Distance(centers[i], point);
        if(min>temp)
        {
            min=temp;
            result=i;
        };
    }
    return result;
}

// read file
vector<vector<long double>> Load(istream & in, int D=2)
    {

        vector<vector<long double>>result;
        vector<long double> a;
        double x;

        while(in>>x)
        {
            if(a.size()==D)
            {
                result.push_back(a);
                a.resize(0);
            };
            a.push_back(x);
        };
        return result;
    };

// check the center
bool Valid_Center(vector<vector<long double>>in, vector<vector<long double>>centers)
{
    vector<vector<vector<long double>>> result;
    result.resize(centers.size());
    for(auto mem: in)
        {
            int index= Closest_Center(mem, centers);
            result[index].push_back(mem);
        };
    for(auto x: result)
    {
        if(x.size()==0) return false;
    }
    return true;

}



