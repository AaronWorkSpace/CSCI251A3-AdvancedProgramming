//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#ifndef POINT2D_H_
#define POINT2D_H_

#include<string>
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

class Point2D{
	//overloading operators
	friend ostream& operator<<(ostream&, const Point2D&);
	friend bool operator==(const Point2D&, const Point2D&);
   	friend bool operator<(const Point2D&, const Point2D&);
    	friend bool operator>(const Point2D&, const Point2D&);
	protected:
		//protected for future and present use
		double distFrOrigin;
		void setDistFrOrigin();
	public:
		//default constructor
		Point2D();
		
		//overloaded constructor
		Point2D(int, int);
		
		//getters
		int getX();
		int getY();
		double getScalarValue();
		
		//setters
		void setX(int);
		void setY(int);
		
		//variables, sorting is set inside int main
		string sorting;
		int x;
		int y;
};
#endif

