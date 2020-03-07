//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include "Point3D.h"

ostream& operator<<(ostream& os, const Point3D& p){
	//displaying on screen as it is in assignment3.pdf
	os << "[" << setw(4) << p.x << ", "
           << setw(4) << p.y << ", " << setw(4) << p.z << "]"
           << setw(3) << "" << fixed << setprecision(3) << p.distFrOrigin
           << endl;
	return os;
}

bool operator==(const Point3D& pt1, const Point3D& pt2){
	//check for duplicate
	if (pt1.x == pt2.x && pt1.y == pt2.y && pt1.z == pt2.z)
		return true;
	return false;
}

bool operator<(const Point3D& pt1, const Point3D& pt2){
	//similar explaination as Point2D
	//pt.z is considered only when pt1.x == pt2.x and pt1.y == pt2.y
	if(pt1.sorting == "X-ordinate"){
		if((pt1.x < pt2.x) || 
		(pt1.x == pt2.x && pt1.y < pt2.y) || 
		(pt1.x == pt2.x && pt1.y == pt2.y && pt1.z < pt2.z))
			return true;
	}
	else if(pt1.sorting == "Y-ordinate"){
		if((pt1.y < pt2.y) || 
		(pt1.y == pt2.y && pt1.x < pt2.x) || 
		(pt1.y == pt2.y && pt1.x == pt2.x && pt1.z < pt2.z))
			return true;
	}
	else if(pt1.sorting == "Z-ordinate"){
		if((pt1.z < pt2.z) ||
		(pt1.z == pt2.z && pt1.x < pt2.x) ||
		(pt1.z == pt2.z && pt1.x == pt2.x && pt1.y < pt2.y))
			return true;
	}
	else if(pt1.sorting == "Dist. Fr Origin"){
		if(pt1.distFrOrigin < pt2.distFrOrigin)
			return true;
	}
	return false;
}

bool operator>(const Point3D& pt1, const Point3D& pt2){
	if(pt1.sorting == "X-ordinate"){
		if((pt1.x > pt2.x) || 
		(pt1.x == pt2.x && pt1.y > pt2.y) || 
		(pt1.x == pt2.x && pt1.y == pt2.y && pt1.z > pt2.z))
			return true;
	}
	else if(pt1.sorting == "Y-ordinate"){
		if((pt1.y > pt2.y) || 
		(pt1.y == pt2.y && pt1.x > pt2.x) || 
		(pt1.y == pt2.y && pt1.x == pt2.x && pt1.z > pt2.z))
			return true;
	}
	else if(pt1.sorting == "Z-ordinate"){
		if((pt1.z > pt2.z) ||
		(pt1.z == pt2.z && pt1.x > pt2.x) ||
		(pt1.z == pt2.z && pt1.x == pt2.x && pt1.y > pt2.y))
			return true;
	}
	else if(pt1.sorting == "Dist. Fr Origin"){
		if(pt1.distFrOrigin > pt2.distFrOrigin)
			return true;
	}
	return false;
}

Point3D::Point3D(): Point2D(){
	z = 0;
	setDistFrOrigin();
}

Point3D::Point3D(int x, int y, int z): Point2D(x, y){
	this->z = z;
	setDistFrOrigin();
}

int Point3D::getZ(){
	return z;
}

void Point3D::setZ(int z){
	this->z = z;
}

void Point3D::setDistFrOrigin(){
	double length;
	length = sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
	distFrOrigin = length;
}

