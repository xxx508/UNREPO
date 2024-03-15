#include <utility>
#include <stdio.h>
#include <cmath>
struct point
{
    double x;
    double y;
    std::pair len(point b)
    {
        return {abs(this->x - b.x), abs(this->y - b.y)};
    }
    point operator+(point b)
    {
        point t;
        t.x = this->x+b.x;
        t.y=this->y+b.y;
        return t;
    }
    point operator=(point b)
    {
        point t;
        t.x=b.x;
        t.y=b.y;
        return t;
    }
    point(double a, double b)
    {
        point p;
        p.x = a;
        p.y = b;
        return p;
    }
};

class triangle {
private:
    point A;
    point B;
    point C;
    point adj;
public:
    triangle()
    {
        point o;
        o.x = 0;
        o.y = 0;
        this->A=o;
        this->B=o;
        this->C=o;
        this->adj = o;
    }
    void move (int pt, point xy)
    {
        switch(pt)
        {
            case 0:
            {
                this->adj+=xy;
                break;
            }
            case 1:
            {
                this->A+=xy;
                break;
            }
            case 2:
            {
                this->B+=xy;
                break;
            }
            case 3:
            {
                this->C+=xy;
                break;
            }
            default:
            {
                this->A+=xy;
                this->B+=xy;
                this->C+=xy;
                this->adj+=xy;
                break;
            }
        }
    }
    long double space()
    {
        long double sp, tr[4];
        tr[0] = sqrt(
            pow(this->A.x - this->B.x, 2)
            +
            pow(this->A.y - this->B.y, 2)
        );
        tr[1] = sqrt(
            pow(this->B.x - this->C.x, 2)
            +
            pow(this->B.y - this->C.y, 2)
        );
        tr[2] = sqrt(
            pow(this->A.x - this->C.x, 2)
            +
            pow(this->A.y - this->C.y, 2)
        );
        tr[3] = (tr[0]+tr[1]+tr[2]);
        sp = sqrt(
            tr[3]/2 * (tr[3]/2 - tr[0])*(tr[3]/2 - tr[1])*(tr[3]/2-tr[2]);
        )
        return sp;
    }
    triangle operator=(triangle t)
    {
        triangle tmp;
        tmp.A = t.A;
        tmp.B = t.B;
        tmp.C = t.C;
        tmp.adj = t.adj;
        return tmp;
    }
    bool operator<(triangle t)
    {
        if((this->space() - t.space()) < 0)
            return 1;
        return 0;
    }
    bool operator>(triangle t)
    {
        if((t.space() - this->space()) < 0)
            return 1;
        return 0;
    }
    void operator*(double size_to)
    {
        point l[3];
        l[0] = this->A.len(adj);
        l[1] = this->B.len(adj);
        l[2] = this->C.len(adj);
        for(int i=0;i<3;i++)
        {
            l[i]*=size_to;
        }
        this->A=l[0]+adj;
        this->B=l[1]+adj;
        this->C=l[2]+adj;
    }
    void operator<<()
    {
        printf("\nA: (%d3:3, %d3:3);\tB: (%d3:3, %d3:3);\tC: (%d3:3, %d3:3)\n");
    }
    void operator>>()
    {
        point a[3];
        scanf("%d%d%d%d%d%d", &a[0].x, &a[0].y, &a[1].x, &a[1].y, &a[2].x, &a[2].y);
        this->move(1, a[0]);
        this->move(2, a[1]);
        this->move(3, a[2]);
    }
};