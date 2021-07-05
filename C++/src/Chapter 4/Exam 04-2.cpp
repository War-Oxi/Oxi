#include <iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;
public:
	void Init_Point(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
};

class Circle
{
private:
	int Radius;
	Point Center;
public:
	void Init_Circle(int x, int y, int radi)
	{
		Radius = radi;
		Center.Init_Point(x, y);
	}

	void ShowCircleInfo() const
	{
		cout<<"radius = "<<Radius<<endl;
		Center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;
public:
	void Init_Ring(int inX, int inY, int inR, int outX, int outY, int outR)
	{
		inCircle.Init_Circle(inX, inY, inR);
		outCircle.Init_Circle(outX, outY, outR);
	}
	void ShowRingInfo() const
	{
		cout<<"Inner Circle Info..."<<endl;
		inCircle.ShowCircleInfo();
		cout<<"Outter Circle Info..."<<endl;
		outCircle.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init_Ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

//! 원위 중심좌표, 반지름의 길이정보를 저장, 출력