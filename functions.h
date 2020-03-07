//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#ifndef MAINFUNCTION_H_
#define MAINFUNCTION_H_

#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "Point2D.h"
#include "Point3D.h"
#include "Line3D.h"
#include "Line2D.h"
#include "MyTemplates.h"

using namespace std;
string checkValidFile();
vector<string> tokenizeString (string, string);
void menu();
void option1(string);
void option2(string&, string&);
void option3(string&, string);
void option4(string&);
void option5(string, string, string);
void option6(string, string, string);

#endif

