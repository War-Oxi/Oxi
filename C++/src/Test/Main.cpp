#include <iostream>
using namespace std;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point *pt = new Point;
    pt->xpos = p1.xpos + p2.xpos;
    pt->ypos = p1.ypos + p2.ypos;
    return *pt;
}

int main(void){
    Point *p1 = new Point;
    Point *p2 = new Point;
    p1->xpos = 2;
    p1->ypos = 4;

    p2->xpos = 12;
    p2->ypos = 14;

    Point *p3 = &PntAdder(*p1, *p2);
    cout<<p3->xpos<<','<<p3->ypos;
    
    delete p1;
    delete p2;
    delete p3;

    return 0;
}