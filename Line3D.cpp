//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include "Line3D.h"

ostream& operator<<(ostream& os, const Line3D& l){
	//displaying on screen as it is in assignment3.pdf
	Point3D pt1 = l.getPt1();
	Point3D pt2 = l.getPt2();
	 
	os << "[" << setw(4) << pt1.getX()
	   << "," << setw(5) << pt1.getY()
	   << "," << setw(5) << pt1.getZ()
	   << "]" << setw(3) << ""
	   << "[" << setw(4) << pt2.getX()
	   << "," << setw(5) << pt2.getY()
	   << "," << setw(5) << pt2.getZ()
	   << "]" << setw(3) << ""
	   << fixed << setprecision(3) << l.getScalarValue()
	   << endl;
	return os;
}

bool operator<(const Line3D& l1, const Line3D& l2){
	//getting every points
	//follow by getting the x value, y value and z value and comparing
	if(l1.sorting == "Pt. 1"){
		if((l1.getPt1().getX() < l2.getPt1().getX()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() && 
		  l1.getPt1().getY() < l2.getPt1().getY()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() &&
		  l1.getPt1().getY() == l2.getPt1().getY() &&
		  l1.getPt1().getZ() < l1.getPt1().getZ()))
		  	return true;
	}
	else if(l1.sorting == "Pt. 2"){
		if((l1.getPt2().getX() < l2.getPt2().getX()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() && 
		  l1.getPt2().getY() < l2.getPt2().getY()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() &&
		  l1.getPt2().getY() == l2.getPt2().getY() &&
		  l1.getPt2().getZ() < l1.getPt2().getZ()))
		  	return true;
	}
	else if(l1.sorting == "Length")
		return l1.getScalarValue() < l2.getScalarValue();
	return false;
}

bool operator==(const Line3D& l1, const Line3D& l2){
	if((l1.getPt1() == l2.getPt1() && l1.getPt2() == l2.getPt2()) ||
	  (l1.getPt1() == l2.getPt2() && l1.getPt2() == l2.getPt1()) ||
	  (l1.getPt1() == l1.getPt2()) || (l2.getPt1() == l2.getPt2()))
	  	return true;
	return false;
}

bool operator>(const Line3D& l1, const Line3D& l2){
	//getting every points
	//follow by getting the x value, y value and z value and comparing
	if(l1.sorting == "Pt. 1"){
		if((l1.getPt1().getX() > l2.getPt1().getX()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() && 
		  l1.getPt1().getY() > l2.getPt1().getY()) ||
		  (l1.getPt1().getX() == l2.getPt1().getX() &&
		  l1.getPt1().getY() == l2.getPt1().getY() &&
		  l1.getPt1().getZ() > l1.getPt1().getZ()))
		  	return true;
	}
	else if(l1.sorting == "Pt. 2"){
		if((l1.getPt2().getX() > l2.getPt2().getX()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() && 
		  l1.getPt2().getY() > l2.getPt2().getY()) ||
		  (l1.getPt2().getX() == l2.getPt2().getX() &&
		  l1.getPt2().getY() == l2.getPt2().getY() &&
		  l1.getPt2().getZ() > l1.getPt2().getZ()))
		  	return true;
	}
	else if(l1.sorting == "Length")
		return l1.getScalarValue() > l2.getScalarValue();
	return false;
}

void Line3D::setLength(){
	int x1 = pt1.getX();
	int y1 = pt1.getY();
	int z1 = pt1.getZ();
	
	int x2 = pt2.getX();
	int y2 = pt2.getY();
	int z2 = pt2.getZ();
	
	x1 = pow((x1 - x2),2);
	y1 = pow((y1 - y2),2);
	z1 = pow((z1 - z2),2);
	
	length = sqrt(x1 + y1 + z1);
}

Line3D::Line3D(){
	
}

Line3D::Line3D(Point3D pt1, Point3D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

Point3D Line3D::getPt1() const{
	return pt1;
}

Point3D Line3D::getPt2() const{
	return pt2;
}

void Line3D::setPt1(Point3D pt1){
	this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2){
	this->pt2 = pt2;
}

