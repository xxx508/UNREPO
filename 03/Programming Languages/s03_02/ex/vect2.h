#include <iostream>
using namespace std;

class vector
{
    int x,y,z;
public:
    vector operator+(vector t);
    vector operator=(vector t);
    void show(void);
    vector(int, int, int);
    ~vector();
};

vector::vector(int mx=0, int my=0, int mz=0)
{
    x=mx;
    y=my;
    z=mz;
    //cout<< "Вектор с координатами ("<<x<<","<<y<<","<<z<< ") создан.\n";
}

vector::~vector()
{
    //cout<< "Вектор с координатами ("<<x<<","<<y<<","<<z<< ") разрушен.\n";
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