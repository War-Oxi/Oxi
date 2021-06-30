#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& PointAdder(const Point &p1, const Point &p2);
Point& PointDistance(const Point &p1, const Point &p2);


int main(void)
{
    Point *A = new Point;
    A->xpos = 2;
    A->ypos = 2;
    Point *B = new Point;
    B->xpos = 4;
    B->ypos = 4;

    Point &Result = PointAdder(*A, *B);
    Point &Distance = PointDistance(*A, *B);

    
    cout<<"두 점 값의 합 = "<<Result.xpos<<", "<<Result.ypos<<endl;
    cout<<"두 점 사이의 거리 = "<<Distance.xpos * Distance.ypos / 2<<endl;

    delete A;
    delete B;
    delete &Result;
    delete &Distance;

    return 0;
}



Point& PointAdder(const Point &p1, const Point &p2)
{
    Point * pptr=new Point;
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return * pptr;
}

Point& PointDistance(const Point &p1, const Point &p2)
{
    Point * Result_Distance = new Point;
    
    Result_Distance->xpos = p1.xpos - p2.xpos;
    if (Result_Distance->xpos < 0)
        Result_Distance->xpos *= -1;

    Result_Distance->ypos = p1.ypos - p2.ypos;
    if (Result_Distance->ypos < 0)
        Result_Distance->ypos *= -1;

    return * Result_Distance;
}