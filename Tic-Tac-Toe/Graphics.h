//Graphics for displaying the TTT board

#include<iostream>
#include<stdio.h>

using namespace std;

//Class for a grid object
class Grid{

private:

	//Holds current game values
	char values[9];

public:
	
	//Constructor
	Grid() {

		//Set initial game values
		for (int i = 0; i < 9; ++i) {

			values[i] = (char)(49+i);
		}
	}
	
	//Prints an empty grid as of now
	void print_grid() {

		//Still need to print horizontal bars
		cout << " " << values[0] << " " << "|" << " " << values[1] << " " << "|" << " " << values[2] << " " << endl;
		cout << " " << values[3] << " " << "|" << " " << values[4] << " " << "|" << " " << values[5] << " " << endl;
		cout << " " << values[6] << " " << "|" << " " << values[7] << " " << "|" << " " << values[8] << " " << endl;

	}

};