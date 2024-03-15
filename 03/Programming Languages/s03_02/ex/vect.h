#include <iostream>
using namespace std;

class vector
{
    int x,y,z;
public:
    vector operator+(vector t);
    vector operator=(vector t);
    void show(void);
    void assign(int, int, int);
};

void vector::assign(int mx, int my, int mz)
{
    x=mx;
    y=my;
    z=mz;
}

void vector::show(void)
{
    cout<<x<<", "<<y<<", "<<z<<"\n";
}

vector vector::operator=(vector t)
{
    x=t.x;
    y=t.y;
    z=t.z;
    return *this;
}

vector vector::operator+(vector t)
{
    vector temp;
    temp.x=x+t.x;
    temp.y=y+t.y;
    temp.z=z+t.z;
    return temp;
}