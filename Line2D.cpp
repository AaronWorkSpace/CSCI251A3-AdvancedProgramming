//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include "Line2D.h"

ostream& operator<<(ostream& os, const Line2D& l){
	//displaying on screen as it is in assignment3.pdf
	Point2D pt1 = l.getPt1();
	Point2D pt2 = l.getPt2();
	
	os << "[" << setw(4) << pt1.getX() << ", "
           << setw(4) << pt1.getY() << "]"
           << setw(3) << ""
           << "[" << setw(4) << pt2.getX() << ", "
           << setw(4) << pt2.getY() << "]"
           << setw(3) << ""
           << fixed << setprecision(3) << l.getScalarValue()
           << endl;
	return os;
}

bool operator<(const Line2D& l1, const Line2D& l2){
	//getting every points
	//follow by getting the x value and y value and comparing
	if(l1.sorting == "Pt. 1"){
		if((l1.getPt1().getX() < l2.getPt1().getX()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() && 
		   l1.getPt1().getY() < l2.getPt1().getY()))
		   	return true;
	}
	else if(l1.sorting == "Pt. 2"){
		if((l1.getPt2().getX() < l2.getPt2().getX()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() && 
		   l1.getPt2().getY() < l2.getPt2().getY()))
		   	return true;
	}
	else if(l1.sorting == "Length"){
		if(l1.getScalarValue() < l2.getScalarValue())
			return true;
	}
	return false;
}

bool operator==(const Line2D& l1, const Line2D& l2){
	if((l1.getPt1() == l2.getPt1() && l1.getPt2() == l2.getPt2()) ||
	  (l1.getPt1() == l2.getPt2() && l1.getPt2() == l2.getPt1()) ||
	  (l1.getPt1() == l1.getPt2()) || (l2.getPt1() == l2.getPt2()))
	  	return true;
	return false;
}

bool operator>(const Line2D& l1, const Line2D& l2){
	//getting every points
	//follow by getting the x value and y value and comparing
	if(l1.sorting == "Pt. 1"){
		if((l1.getPt1().getX() > l2.getPt1().getX()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() && 
		   l1.getPt1().getY() > l2.getPt1().getY()))
		   	return true;
	}
	else if(l1.sorting == "Pt. 2"){
		if((l1.getPt2().getX() > l2.getPt2().getX()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() && 
		   l1.getPt2().getY() > l2.getPt2().getY()))
		   	return true;
	}
	else if(l1.sorting == "Length"){
		if(l1.getScalarValue() > l2.getScalarValue())
			return true;
	}
	return false;
}

void Line2D::setLength(){
	int x = pt1.getX();
	int y = pt1.getY();
	int xx = pt2.getX();
	int yy = pt2.getY();
	
	x = x - xx;
	x = pow(x, 2);
	
	y = y - yy;
	y = pow(y, 2);
	
	length = sqrt(x + y);
}

Line2D::Line2D(){
	
}

Line2D::Line2D(Point2D pt1, Point2D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

Point2D Line2D::getPt1() const{
	return pt1;
}

Point2D Line2D::getPt2() const{
	return pt2;
}

void Line2D::setPt1(Point2D pt1){
	this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2){
	this->pt2 = pt2;
}

double Line2D::getScalarValue() const{
	return length;
}

