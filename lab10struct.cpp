#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class point{
    double x;
    double y;
    double dist=sqrt(x*x+y*y);
    public:
        point(){
            this->x=0;
            this->y=0;
        }
        point(double _x,double _y){
            this->x=_x;
            this->y=_y;
        }
        void Reset(double _x, double _y){
            x= _x;
            y= _y;
        }
        void setX(double _x){
            x=_x;
        }
        void setY(double _y){
            y=_y;
        }
        double Getx(){
            return x;
        }    
        double Gety(){
            return y;
        }
        double Getdist(){
            return dist;
        }
        void printPar(){
            cout<<"x= "<<x<<" y= "<<y<<endl<<"distance "<<dist<<endl;
        }
};
bool triangle(vector<point> a){
        if(a.size()!=3){
            cout<<"ERROR";
            return false;
        }else{
            double dist1=sqrt(a[0].Getx() * a[0].Getx() + a[0].Gety() * a[0].Gety());
            double dist2=sqrt(a[1].Getx() * a[1].Getx() + a[1].Gety() * a[1].Gety());
            double dist3=sqrt(a[2].Getx() * a[2].Getx() + a[2].Gety() * a[2].Gety());
            if(dist1<dist2+dist3 && dist2<dist1+dist3 && dist3<dist2+dist1 ){
                return true;
            }else{
                return false;
            }
        }
}
int main(){
    vector<point> a;
    point p1,p2,p3;
    p1.Reset(1.0,1.0);
    p2.Reset(3.0,1.0);
    p3.Reset(1.0,4.0);
    a={p1,p2,p3};
    p1.printPar();
    if(triangle(a)==true){
        cout<<"IS TRIANGLE";    
    }else{
        cout<<"NO TRIANGLE";
    }
    return 0;
}