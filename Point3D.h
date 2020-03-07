//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#ifndef POINT3D_H_
#define POINT3D_H_

#include "Point2D.h"

using namespace std;

class Point3D:public Point2D{
	//overloaded operators
	friend ostream& operator<<(ostream&, const Point3D&);
	friend bool operator==(const Point3D&, const Point3D&);
    	friend bool operator<(const Point3D&, const Point3D&);
    	friend bool operator>(const Point3D&, const Point3D&);
	protected:
		//protected for future and present use
		void setDistFrOrigin();
	public:
		//default constructor
		Point3D();
		
		//overloaded constructor
		Point3D(int, int, int);
		
		//getters
		int getZ();
		
		//setters
		void setZ(int z);
		
		//variable
		int z;
};
#endif

