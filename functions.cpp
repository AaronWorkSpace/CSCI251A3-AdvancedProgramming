//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include "functions.h"

//vectors for each classes
vector<Point2D> vector2DP;
vector<Point3D> vector3DP;
vector<Line2D> vector2DL;
vector<Line3D> vector3DL;

//Check if the user input is a valid file
string checkValidFile(){
	bool ok = true;
	string inputFilename;
	do
	{
	    	cout << "Please enter enter filename(-1 to exit): ";
	    	cin >> inputFilename;
		fstream inputFile(inputFilename.c_str(), fstream::in);
		if(inputFilename == "-1")
		{
			ok = false;
		}
		else
		{
			if(!inputFile){
				inputFile.close();
				cout << inputFilename << " cannot be opened, please try again" << endl;
			}
			else{
				ok = false;
				inputFile.close();
			}
		}
	}while(ok == true);
	return inputFilename;
}

//Taken from assignment 1
vector<string> tokenizeString (string input, string delimiter){
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos) 
	{
    		token = input.substr(0, pos);
    		result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back (input);
	return (result);
}

void menu(){
	//initiate start
	string filterCriteria = "Point2D";
	string sortCriteria = "X-ordinate";
	string sortOrder = "ASC";
	
	//once ok = false, it exit the loop and end
	bool ok = true;
	
	//the choice of the user
	string i;
	
	string fileName;
	do{
		cout << endl;
		cout << "Student ID  : 5985171" << endl;
		cout << "Student Name: Aaron Lim Cong Kai" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Welcome to Assn3 program!" << endl;
		cout << endl;
		cout << "1) Read in data" << endl;
		cout << "2) Specify filtering criteria(current: " << filterCriteria << ")" << endl;
		cout << "3) Specify sorting criteria (current: " << sortCriteria << ")" << endl;
		cout << "4) Specify sorting order (current: " << sortOrder << ")" << endl;
		cout << "5) View data" << endl;
		cout << "6) Store data" << endl;
		cout << "7) Quit" << endl;
		cout << endl;
		cout << "Enter your choice: ";
		cin >> i;
		cout << endl;
		
		//depends what the user input
		//1 to 7 for valid input
		//else prompt the user again
		if(i == "1"){
			fileName = checkValidFile();
			option1(fileName);
		}
		else if(i == "2"){
			option2(filterCriteria, sortCriteria);
		}
		else if(i == "3"){
			option3(sortCriteria, filterCriteria);
		}
		else if(i == "4"){
			option4(sortOrder);
		}
		else if(i == "5"){
			option5(filterCriteria, sortCriteria, sortOrder);
		}
		else if(i == "6"){
			option6(filterCriteria, sortCriteria, sortOrder);
		}
		else if(i == "7"){
			cout << "Thank you for using this program." << endl;
			ok = false;
		}
		else{
			cout << "Wrong input, please input 1/2/3/4/5/6/7." << endl;
		}
	}while(ok == true);
	
}

void option1(string filename){
	if(filename == "-1"){
		cout << endl;
		cout << "Going back to main menu..." << endl;
		return;
	}
	//opening the file and double check if it is valid
	fstream inputFile(filename.c_str(), fstream::in);
	if(!inputFile){
		cout << filename << " does not exist" << endl;
		inputFile.close();
		return;
	}
	
	//for rows of line in the file
	string aLine;
	
	//temp Point2D, check for duplication
	int x;
	int y;
	Point2D temp2DP;
	
	//temp Point3D, check for duplication
	int z;
	Point3D temp3DP;
	
	//for line 2D
	Point2D tempP1;
	Point2D tempP2;
	Line2D temp2DL;
	vector<int>x1;
	vector<int>y1;
	
	//for line3D
	Point3D tempP3;
	Point3D tempP4;
	Line3D temp3DL;
	vector<int>z1;
	
	//for line2D and line3D
	vector<string>one;
	vector<string>two;
	vector<string>three;
	
	//variable
	//ok for checking if it is duplicated
	//total for ending printing out
	bool ok;
	int total = 0;
	
	while(getline(inputFile, aLine)){
		if(aLine[0]!= '/'){
			vector<string> line = tokenizeString(aLine, ", ");
			ok = true;
			//line[0] is 100% Point2D/Point3D/Line2D/line3D
			//depending on which it is
			if(line[0] == "Point2D"){
				for(unsigned int i = 1; i < line.size();i++){
					//tokenizing accordingly
					//odd = x
					//even = y
					if(i % 2 == 0){
						two = tokenizeString(line[i], "]");
						y = atoi(two[two.size()-2].c_str());
					}
					else if(i % 2 == 1){
						one = tokenizeString(line[i], "[");
						x = atoi(one[one.size()-1].c_str());
					}
				}
				//Adding to temp
				temp2DP = Point2D(x, y);
				
				//checking for duplication
				for(unsigned int i = 0; i < vector2DP.size(); i++){
					if(equals(temp2DP, vector2DP[i])){
						ok = false;
					}
				}
				if(ok == true){
					vector2DP.push_back(temp2DP);
					total++;
				}
			}
			else if(line[0] == "Point3D"){
				for(unsigned int i = 1; i < line.size(); i++){
					if(i % 3 == 0){
						three = tokenizeString(line[i], "]");
						z = atoi(three[three.size()-2].c_str());	
					}
					else if(i % 3 == 2){
						y = atoi(line[i].c_str());
					}
					else if(i % 3 == 1){
						one = tokenizeString(line[i], "[");
						x = atoi(one[one.size()-1].c_str());
					}
				}
				temp3DP = Point3D(x, y, z);
				for(unsigned int i = 0; i < vector3DP.size(); i++){
					if(equals(temp3DP, vector3DP[i])){
						ok = false;
					}
				}
				if(ok == true){
					vector3DP.push_back(temp3DP);
					total++;
				}
			}
			else if(line[0] == "Line2D"){
				for(unsigned int i = 1; i < line.size();i++){
					if(i % 2 == 0){
						two = tokenizeString(line[i], "]");
						y1.push_back(atoi(two[two.size()-2].c_str()));
					}
					else if(i % 2 == 1){
						one = tokenizeString(line[i], "[");
						x1.push_back(atoi(one[one.size()-1].c_str()));
					}
				}
				tempP1 = Point2D(x1[x1.size()-2], y1[x1.size()-2]);
				tempP2 = Point2D(x1[x1.size()-1], y1[x1.size()-1]);
				temp2DL = Line2D(tempP1, tempP2);
				for(unsigned int i = 0; i < vector2DL.size(); i++){
					if(equals(temp2DL, vector2DL[i])){
						ok = false;
					}
				}
				if(ok == true){
					vector2DL.push_back(temp2DL);
					total++;
				}
			}
			else if(line[0] == "Line3D"){
				for(unsigned int i = 1; i < line.size(); i++){
					if(i % 3 == 0){
						three = tokenizeString(line[i], "]");
						z1.push_back(atoi(three[three.size()-2].c_str()));
					}
					else if(i % 3 == 2){
						y1.push_back(atoi(line[i].c_str()));
					}
					else if(i % 3 == 1){
						one = tokenizeString(line[i], "[");
						x1.push_back(atoi(one[one.size()-1].c_str()));
					}
				}
				tempP3 = Point3D(x1[x1.size()-2], y1[y1.size()-2], z1[z1.size()-2]);
				tempP4 = Point3D(x1[x1.size()-1], y1[y1.size()-1], z1[z1.size()-1]);
				temp3DL = Line3D(tempP3, tempP4);
				for(unsigned int i = 0; i < vector3DL.size(); i++){
					if(equals(temp3DL, vector3DL[i])){
						ok = false;
					}
				}
				if(ok == true){
					vector3DL.push_back(temp3DL);
					total++;
				}
			}
		}
	} 
	//closing of file
	inputFile.close();
	cout << total << " records read in successfully!" << endl;
	cout << "Going back to main menu..." << endl;
}

void option2(string& filterCriteria, string& sortCriteria){
	bool ok = true;
	string choice;
	do{
		cout << "[Specifying filtering criteria (Current: " << filterCriteria << ")]" << endl;
		cout << endl;
		cout << "\ta)\tPoint2D records" << endl;
		cout << "\tb)\tPoint3D records" << endl;
		cout << "\tc)\tLine2D records" << endl;
		cout << "\td)\tLine3D records" << endl;
		cout << "\tq)\tQuit" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria(a-d): ";
		cin >> choice;
		cout << endl;
		
		//setting filterCriteria and sortCriteria accordingly
		if(choice == "a" || choice == "A"){
			filterCriteria = "Point2D";
			sortCriteria = "X-ordinate";
			ok = false;
			cout << "\tFilter criteria successfully set to '" << filterCriteria << "'!" << endl;
		}
		else if(choice == "b" || choice == "B"){
			filterCriteria = "Point3D";
			sortCriteria = "X-ordinate";
			ok = false;
			cout << "\tFilter criteria successfully set to '" << filterCriteria << "'!" << endl;
		}
		else if(choice == "c" || choice == "C"){
			filterCriteria = "Line2D";
			sortCriteria = "Pt. 1";
			ok = false;
			cout << "\tFilter criteria successfully set to '" << filterCriteria << "'!" << endl;
		}
		else if(choice == "d" || choice == "D"){
			filterCriteria = "Line3D";
			sortCriteria = "Pt. 1";
			ok = false;
			cout << "\tFilter criteria successfully set to '" << filterCriteria << "'!" << endl;
		}
		else if(choice == "q" || choice == "Q"){
			ok = false;
		}
		else{
			cout << "\tYou have entered a invalid value, please enter a/b/c/d/q" << endl;
			cout << endl;
		}
	}while(ok == true);
	cout << "\tGoing back to main menu..." << endl;
}

void option3(string& sortCriteria, string filterCriteria){
	string choice;
	bool ok = true;
	//checking if filterCriteria is equal Point2D/Point3D/Line2D/Line3D
	if(filterCriteria == "Point2D"){
		do{
			cout << "[Specifying sorting criteria (current: " << sortCriteria << ")]" << endl;
			cout << endl;
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tDist from origin" << endl;
			cout << "\tq)\tQuit" << endl;
			cout << endl;
			cout << "\tPlease enter your criteria(a-c): ";
			cin >> choice;
			
			//Setting sortCriteria accordingly
			if(choice == "a" || choice == "A"){
				sortCriteria = "X-ordinate";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "b" || choice == "B"){
				sortCriteria = "Y-ordinate";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "c" || choice == "C"){
				sortCriteria = "Dist. Fr Origin";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "q" || choice == "Q"){
				ok = false;
			}
			else{
				cout << "\tYou have entered a invalid value, please enter a/b/c/q" << endl;
				cout << endl;
			}
		}while(ok == true);
	}
	else if(filterCriteria == "Point3D"){
		do{
			cout << "[Specifying sorting criteria (current: " << sortCriteria << ")]" << endl;
			cout << endl;
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tZ-ordinate value" << endl;
			cout << "\td)\tDist from origin" << endl;
			cout << "\tq)\tQuit" << endl;
			cout << endl;
			cout << "\tPlease enter your criteria(a-d): ";
			cin >> choice;
			
			if(choice == "a" || choice == "A"){
				sortCriteria = "X-ordinate";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "b" || choice == "B"){
				sortCriteria = "Y-ordinate";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "c" || choice == "C"){
				sortCriteria = "Z-ordinate";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "d" || choice == "D"){
				sortCriteria = "Dist. Fr Origin";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "q" || choice == "Q"){
				ok = false;
			}
			else{
				cout << "\tYou have entered a invalid value, please enter a/b/c/d/q" << endl;
				cout << endl;
			}
		}while(ok == true);
	}
	else if(filterCriteria == "Line2D"){
		do{
			cout << "[Specifying sorting criteria (current: " << sortCriteria << ")]" << endl;
			cout << "\ta)\tPt. 1's(x, y) values" << endl;
			cout << "\tb)\tPt. 2's(x, y) values" << endl;
			cout << "\tc)\tLength value" << endl;
			cout << "\tq)\tQuit" << endl;
			cout << endl;
			cout << "\tPlease enter your criteria(a-c): ";
			cin >> choice;
			
			if(choice == "a" || choice == "A"){
				sortCriteria = "Pt. 1";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "b" || choice == "B"){
				sortCriteria = "Pt. 2";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "c" || choice == "C"){
				sortCriteria = "Length";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "q" || choice == "Q"){
				ok = false;
			}
			else{
				cout << "\tYou have entered a invalid value, please enter a/b/c/q" << endl;
			}
		}while(ok == true);
	}
	else if(filterCriteria == "Line3D"){
		do{
			cout << "[Specifying sorting criteria (current: " << sortCriteria << ")]" << endl;
			cout << "\ta)\tPt. 1's(x, y) values" << endl;
			cout << "\tb)\tPt. 2's(x, y) values" << endl;
			cout << "\tc)\tLength value" << endl;
			cout << "\tq)\tQuit" << endl;
			cout << endl;
			cout << "\tPlease enter your criteria(a-c): ";
			cin >> choice;
			
			if(choice == "a" || choice == "A"){
				sortCriteria = "Pt. 1";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "b" || choice == "B"){
				sortCriteria = "Pt. 2";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "c" || choice == "C"){
				sortCriteria = "Length";
				ok = false;
				cout << "\tSorting criteria successfully set to '" << sortCriteria << "'!" << endl;
			}
			else if(choice == "q" || choice == "Q"){
				ok = false;
			}
			else{
				cout << "\tYou have entered a invalid value, please enter a/b/c/q" << endl;
			}
		}while(ok == true);
	}
	cout << endl;
	cout << "\tGoing back to main menu..." << endl;
}

void option4(string& sortOrder){
	bool ok = true;
	string choice;
	do{
		cout << "[Specifying sorting order(current: " << sortOrder << ")]" << endl;
		cout << endl;
		cout << "\ta)\tASC(Ascending order)" << endl;
		cout << "\tb)\tDSC(Descending order)" << endl;
		cout << "\tq)\tQuit" << endl;
		cout << endl;
		cout << "\tPlease enter your choice(a-b): ";
		cin >> choice;
		
		//setting sort order accordingly
		if(choice == "a" || choice == "A"){
			sortOrder = "ASC";
			cout << "\tSorting order successfully set to '" << sortOrder << "'!" << endl;
			ok = false;
		}
		else if(choice == "b" || choice == "B"){
			sortOrder = "DSC";
			cout << "\tSorting order successfully set to '" << sortOrder << "'!" << endl;
			ok = false;
		}
		else if(choice == "q" || choice == "Q"){
			ok = false;
		}
		else{
			cout << "\tYou have entered a invalid value, please enter a/b/q" << endl;
		}
	}while(ok == true);
	cout << endl;
	cout << "\tGoing back to main menu..." << endl;
}

void option5(string filterCriteria, string sortCriteria, string sortOrder){
	
	if(filterCriteria == "Point2D"){
		//checking if vector is empty
		if(vector2DP.empty()){
			cout << "Point2D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Point3D"){
		//checking if vector is empty
		if(vector3DP.empty()){
			cout << "Point3D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Line2D"){
		//checking if vector is empty
		if(vector2DL.empty()){
			cout << "Line2D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Line3D"){
		//checking if vector is empty
		if(vector3DL.empty()){
			cout << "Line3D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	
	cout << "[View data ...]" << endl;
	cout << "Filtering criteria: " << filterCriteria << endl;
	cout << "Sorting criteria: " << sortCriteria << endl;
	cout << "Sorting order: " << sortOrder << endl;
	cout << endl;
	
	//checking if filterCriteria is equal Point2D/Point3D/Line2D/Line3D
	if(filterCriteria == "Point2D"){
		//setting sorting variable, which is in the classes
		for(unsigned int i = 0; i < vector2DP.size();i++){
			vector2DP[i].sorting = sortCriteria;
		}
		//using template function to sort
		if(sortOrder == "ASC"){
			sort(vector2DP.begin(), vector2DP.end(), ASC<Point2D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector2DP.begin(), vector2DP.end(), DSC<Point2D>);
		}
		
		//Just displaying
		cout << setw(5) << "X"
		     << setw(6) << "Y"
		     << setw(19) << "Dist. Fr Origin"
		     << endl;
		cout << setfill('-') << setw(30) << "-" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < vector2DP.size(); i++){
			cout << vector2DP[i];
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
	else if(filterCriteria == "Point3D"){
		for(unsigned int i = 0; i < vector3DP.size(); i++){
			vector3DP[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector3DP.begin(), vector3DP.end(), ASC<Point3D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector3DP.begin(), vector3DP.end(), DSC<Point3D>);
		}
		cout << setw(5) << "X"
		     << setw(5) << "Y"
		     << setw(6) << "Z"
		     << setw(19) << "Dist. Fr Origin"
		     << endl;
		cout << setfill('-') << setw(36) << "-" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < vector3DP.size();i++){
			cout << vector3DP[i];
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
	else if(filterCriteria == "Line2D"){
		for(unsigned int i = 0; i < vector2DL.size(); i++){
			vector2DL[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector2DL.begin(), vector2DL.end(), ASC<Line2D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector2DL.begin(), vector2DL.end(), DSC<Line2D>);
		}
		cout << setw(5) << "P1-X"
		     << setw(6) << "P1-Y"
		     << setw(4) << ""
		     << setw(5) << "P2-X"
		     << setw(6) << "P2-Y"
		     << setw(10) << "Length"
		     << endl;
		cout << setfill('-') << setw(40) << "-" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < vector2DL.size(); i++){
			cout << vector2DL[i];
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
	else if(filterCriteria == "Line3D"){
		for(unsigned int i = 0; i < vector3DL.size(); i++){
			vector3DL[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector3DL.begin(), vector3DL.end(), ASC<Line3D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector3DL.begin(), vector3DL.end(), DSC<Line3D>);
		}
		cout << setw(5) << "P1-X"
		     << setw(6) << "P1-Y"
		     << setw(6) << "P1-Z"
		     << setw(4) << ""
		     << setw(5) << "P2-X"
		     << setw(6) << "P2-Y"
		     << setw(6) << "P2-Z"
		     << setw(10) << "Length"
		     << endl;
		cout << setfill('-') << setw(52) << "-" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < vector3DL.size(); i++){
			cout << vector3DL[i];
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
}

void option6(string filterCriteria, string sortCriteria, string sortOrder){
	int total = 0;
	string filename;
	
	if(filterCriteria == "Point2D"){
		//checking if vector is empty
		if(vector2DP.empty()){
			cout << "Point2D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Point3D"){
		//checking if vector is empty
		if(vector3DP.empty()){
			cout << "Point3D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Line2D"){
		//checking if vector is empty
		if(vector2DL.empty()){
			cout << "Line2D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	else if(filterCriteria == "Line3D"){
		//checking if vector is empty
		if(vector3DL.empty()){
			cout << "Line3D vector is empty" << endl;
			cout << "Going back to main menu..." << endl;
			return;
		}
	}
	
	//getting the ideal file name that the user wants
	cout << "Please input file name: ";
	cin >> filename;
	
	fstream outputFile(filename.c_str(), fstream::out);
	if(!outputFile){
		cout << filename << " cannot be created" << endl;
		outputFile.close();
		return;
	}
	
	//checking if filterCriteria is equal Point2D/Point3D/Line2D/Line3D
	if(filterCriteria == "Point2D"){
		//Similar as option 5
		for(unsigned int i = 0; i < vector2DP.size();i++){
			vector2DP[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector2DP.begin(), vector2DP.end(), ASC<Point2D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector2DP.begin(), vector2DP.end(), DSC<Point2D>);
		}
		//Instead of cout, it is store in the file
		outputFile << setw(5) << "X"
			   << setw(6) << "Y"
			   << setw(19) << "Dist. Fr Origin"
			   << endl;
		outputFile << setfill('-') << setw(36) << "-" << endl;
		outputFile << setfill(' ');
		for(unsigned int i = 0; i < vector2DP.size(); i++){
			outputFile << vector2DP[i];
			total++;
		}
	}
	else if(filterCriteria == "Point3D"){
		for(unsigned int i = 0; i < vector3DP.size(); i++){
			vector3DP[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector3DP.begin(), vector3DP.end(), ASC<Point3D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector3DP.begin(), vector3DP.end(), DSC<Point3D>);
		}
		outputFile << setw(5) << "X"
			   << setw(5) << "Y"
			   << setw(6) << "Z"
			   << setw(19) << "Dist. Fr Origin"
			   << endl;
		outputFile << setfill('-') << setw(36) << "-" << endl;
		outputFile << setfill(' ');
		for(unsigned int i = 0; i < vector3DP.size();i++){
			outputFile << vector3DP[i];
			total++;
		}
	}
	else if(filterCriteria == "Line2D"){	
		for(unsigned int i = 0; i < vector2DL.size(); i++){
			vector2DL[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector2DL.begin(), vector2DL.end(), ASC<Line2D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector2DL.begin(), vector2DL.end(), DSC<Line2D>);
		}
		outputFile << setw(5) << "P1-X"
			   << setw(6) << "P1-Y"
			   << setw(4) << ""
			   << setw(5) << "P2-X"
			   << setw(6) << "P2-Y"
			   << setw(10) << "Length"
			   << endl;
		outputFile << setfill('-') << setw(40) << "-" << endl;
		outputFile << setfill(' ');
		for(unsigned int i = 0; i < vector2DL.size(); i++){
			outputFile << vector2DL[i];
			total++;
		}
	}
	else if(filterCriteria == "Line3D"){
		for(unsigned int i = 0; i < vector3DL.size(); i++){
			vector3DL[i].sorting = sortCriteria;
		}
		if(sortOrder == "ASC"){
			sort(vector3DL.begin(), vector3DL.end(), ASC<Line3D>);
		}
		else if(sortOrder == "DSC"){
			sort(vector3DL.begin(), vector3DL.end(), DSC<Line3D>);
		}
		outputFile << setw(5) << "P1-X"
			   << setw(6) << "P1-Y"
		 	   << setw(6) << "P1-Z"
			   << setw(4) << ""
			   << setw(5) << "P2-X"
			   << setw(6) << "P2-Y"
			   << setw(6) << "P2-Z"
			   << setw(10) << "Length"
			   << endl;
		outputFile << setfill('-') << setw(52) << "-" << endl;
		outputFile << setfill(' ');
		for(unsigned int i = 0; i < vector3DL.size(); i++){
			outputFile << vector3DL[i];
			total++;
		}
	}
	//closing of file
	outputFile.close();
	cout << total << " records output successfully!" << endl;
	cout << "Going back to main menu..." << endl;
}

