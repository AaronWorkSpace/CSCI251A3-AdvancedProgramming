//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#ifndef LINE2D_H_
#define LINE2D_H_

#include "Point2D.h"

using namespace std;

class Line2D{
	//overloaded operator
	friend ostream& operator<<(ostream&, const Line2D&);
	friend bool operator<(const Line2D&, const Line2D&);
	friend bool operator==(const Line2D&, const Line2D&);
	friend bool operator>(const Line2D&, const Line2D&);
	
	private:
		//accessable only by this class
		Point2D pt1;
		Point2D pt2;
	protected:
		//protected for present and future use
		double length;
		void setLength();
	public:
		//default constructor
		Line2D();
		
		//overloaded constructor
		Line2D(Point2D, Point2D);
		
		//getters
		Point2D getPt1() const;
		Point2D getPt2() const;
		double getScalarValue() const;
		
		//setters
		void setPt1(Point2D pt1);
		void setPt2(Point2D pt2);
		
		//variable
		string sorting;
};
#endif

