//written by Nguyen Minh Quang

#ifndef HEADER_H
#define HEADER_H

#include<string>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<SDL.h>
#include<math.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#define WIDTH 1000
#define HEIGHT 700
#define G 7
#define S 30
#define W 170
#define H 20

using namespace std;

double get_positive(double x)
{

  if(x<0) return -x;
  return x;
}

class pos
{
    public:
    double x,y;
    pos(double x_=0,double y_=0):x(x_),y(y_){};
    friend std::ostream& operator<<(std::ostream& os, const pos& p)
    {

         os<<"("<<p.x<<";"<<p.y<<")"<<std::endl;
    };

    friend std::istream& operator>>(std::istream& is, pos& p)
    {

         is>>p.x>>p.y;
    };


};

class line
{
    public:
   pos startp,endp;
   line(double x_=0, double y_=0,double a_=0, double b_=0){startp=(pos(x_,y_)),endp=(pos(a_,b_));};
   static void renderLine(const line& l,SDL_Renderer*renderer)
   {
       SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF, 0xFF);
       SDL_RenderDrawLine(renderer,l.startp.x,l.startp.y,l.endp.x,l.endp.y);

   };
   static void createLinefromRect(const SDL_Rect r[], const int &sr, line l[],const int &sl);

};
class ball
{
public:
    pos P,V;
    ball(double P_x=WIDTH/2,double P_y=HEIGHT/2,double V_x=60,double V_y=-50){P=(pos(P_x,P_y)),V=(pos(V_x,V_y));};
    static bool stop(ball& b ,const double t, const line X);
    static void drawBall(const ball&b, SDL_Renderer*renderer, const int &sz=S);

};


void drawBall(const ball&b, SDL_Renderer*renderer, const int &sz=S)
    {
       for(int i=b.P.x-sz/2;i<=b.P.x+sz/2;i++)
       {
           SDL_RenderDrawPoint(renderer,i,b.P.y+sqrt(S*S/4-(b.P.x-i)*(b.P.x-i)));
           SDL_RenderDrawPoint(renderer,i,b.P.y-sqrt(S*S/4-(b.P.x-i)*(b.P.x-i)));
       }
    }
int stop (ball& b ,const double &t,const line Y[],const int &sizel,const bool&sound)
{
    bool st=false;
    int result=0;
    bool im=false;
    double move_x=b.P.x+b.V.x*t, move_y=b.P.y+b.V.y*t,final_x=move_x,final_y=move_y,final_vx=b.V.x,final_vy=b.V.y;
    double t_;
    for(int i=0;i<sizel;i++)
    {
    //impact x axis
    if((move_y-Y[i].startp.y)*(b.P.y-Y[i].startp.y)<0)
    {
        t_=get_positive((move_y-Y[i].startp.y)/b.V.y);

        if((((t_*b.V.x+b.P.x)-Y[i].startp.x)*((t_*b.V.x+b.P.x)-Y[i].endp.x))<=0){
        final_y=Y[i].startp.y-0.5*(move_y-Y[i].startp.y);final_vy*=-0.5;im=true;
    };
    }


    //impact y axis
    if((move_x-Y[i].startp.x)*(b.P.x-Y[i].startp.x)<0)
    {
        t_=get_positive((move_x-Y[i].startp.x)/b.V.x);
        if((((t_*b.V.y+b.P.y)-Y[i].startp.y)*((t_*b.V.y+b.P.y)-Y[i].endp.y))<=0){
        final_x=Y[i].startp.x-0.5*(move_x-Y[i].startp.x);final_vx*=-0.5;im=true;
    };
    };}

    final_vx*=0.9992;
    final_vy+=G*t;
    final_vy*=0.9999;

    b.P=pos(final_x,final_y);
    bool upper=false;
    b.V=pos(final_vx,final_vy);
    double temp_y=b.P.y,temp_x=b.P.x;
    for(int i=0;i<sizel;i++)
    {
        if(((Y[i].startp.x-temp_x)*(Y[i].endp.x-temp_x)<=0)&&(Y[i].startp.y==Y[i].endp.y))
        {
            if((temp_y-Y[i].endp.y<=0)&&(temp_y-Y[i].endp.y>=-1)) {upper=true; break;};
        };
    };

    if((get_positive(final_vx)<1)&&(get_positive(final_vy)<1)&&upper ) result=1;
    if(b.P.y>HEIGHT) {result=2;};
    if (sound&&im&&(get_positive(final_vx*final_vy)>4)){if(sound) {Mix_Chunk* soundball=Mix_LoadWAV("ball.wav");Mix_PlayChannel(-1,soundball,0);};cout<<"yes"<<endl;};
    return result;


};




#endif
