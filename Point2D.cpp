//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include "Point2D.h"

ostream& operator<<(ostream& os, const Point2D& p){
	//displaying on screen as it is in assignment3.pdf
	os << "[" << setw(4) << p.x << ", " << setw(4) << p.y << "]"
           << setw(3) << "" << fixed << setprecision(3) << p.distFrOrigin
           << endl;
	return os;
}

bool operator==(const Point2D& pt1, const Point2D& pt2){
	//check if duplicate
	//duplicated = true
	//non-duplicated = false
	if(pt1.x == pt2.x && pt1.y == pt2.y){
		return true;
	}
	else{
		return false;
	}
}

bool operator<(const Point2D& pt1, const Point2D& pt2){
	//after sorting is set in in main, it check if it is one of the three
	//it returns true if pt1.x is less than pt2.x or
	//it returns true if pt1.y is less than pt2.y, with pt1.x equal to pt2.x
	//both X-ordinate and Y-ordinate is the same.
	if(pt1.sorting == "X-ordinate"){
		if((pt1.x < pt2.x) || (pt1.x == pt2.x && pt1.y < pt2.y))
			return true;
	}
	else if(pt1.sorting == "Y-ordinate"){
		if((pt1.y < pt2.y) || (pt1.y == pt2.y && pt1.x < pt2.x))
			return true;
	}
	//gets the dist fr origin and compare, if it is lesser than pt2
	//return true
	else if(pt1.sorting == "Dist. Fr Origin"){
		if(pt1.distFrOrigin < pt2.distFrOrigin)
			return true;
	}
	//all else fail, return false
	return false;
}

bool operator>(const Point2D& pt1, const Point2D& pt2){
	//after sorting is set in in main, it check if it is one of the three
	//it returns true if pt1.x is more than pt2.x or
	//it returns true if pt1.y is more than pt2.y, with pt1.x equal to pt2.x
	//both X-ordinate and Y-ordinate is the same.
	if(pt1.sorting == "X-ordinate"){
		if((pt1.x > pt2.x) || (pt1.x == pt2.x && pt1.y > pt2.y))
			return true;
	}
	else if(pt1.sorting == "Y-ordinate"){
		if((pt1.y > pt2.y) || (pt1.y == pt2.y && pt1.x > pt2.x))
			return true;
	}
	//gets the dist fr origin and compare, if it is more than pt2
	//return true
	else if(pt1.sorting == "Dist. Fr Origin"){
		if(pt1.distFrOrigin > pt2.distFrOrigin)
			return true;
	}
	//all else fail, return false
	return false;
}

Point2D::Point2D(){
	x = 0;
	y = 0;
	setDistFrOrigin();
}

Point2D::Point2D(int x, int y){
	this->x = x;
	this->y = y;
	setDistFrOrigin();
}

int Point2D::getX(){
	return x;
}

int Point2D::getY(){
	return y;
}

double Point2D::getScalarValue(){
	return distFrOrigin;
}

void Point2D::setX(int x){
	this->x = x;
}

void Point2D::setY(int y){
	this->y = y;
}

void Point2D::setDistFrOrigin(){
	double length;
	length = sqrt(pow(x, 2) + pow(y, 2));
	distFrOrigin = length;
}

