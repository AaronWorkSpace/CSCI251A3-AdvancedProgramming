//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#ifndef LINE3D_H_
#define LINE3D_H_

#include "Point3D.h"
#include "Line2D.h"

using namespace std;

class Line3D:public Line2D{
	//overloaded operators
	friend ostream& operator<<(ostream& os, const Line3D&);
	friend bool operator<(const Line3D&, const Line3D&);
	friend bool operator==(const Line3D&, const Line3D&);
	friend bool operator>(const Line3D&, const Line3D&);
	private:
		//accessable by this class only
		Point3D pt1;
		Point3D pt2;
	protected:
		void setLength();
	public:
		//default constructor
		Line3D();
		
		//overloaded constructor
		Line3D(Point3D, Point3D);
		
		//getters
		Point3D getPt1() const;
		Point3D getPt2() const;
		
		//setters
		void setPt1(Point3D pt1);
		void setPt2(Point3D pt2);
};
#endif

