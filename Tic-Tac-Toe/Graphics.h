//Graphics for displaying the TTT board

#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<string>

using namespace std;

//Class for a grid object
class Grid{

private:

	//Variables
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
		cout << endl;
		cout << "_" << values[0] << "_" << "|" << "_" << values[1] << "_" << "|" << "_" << values[2] << "_" << endl;
		cout << "_" << values[3] << "_" << "|" << "_" << values[4] << "_" << "|" << "_" << values[5] << "_" << endl;
		cout << " " << values[6] << " " << "|" << " " << values[7] << " " << "|" << " " << values[8] << " " << endl;
	}

	//Reset the Grid values
	void reset() {

		//Reset
		for (int i = 0; i < 9; ++i) {

			values[i] = (char)(49 + i);
		}
	}

	//Set grid value
	void set_value(int pos, char c) {

		//Sanity check for bounds
		if (pos > 8) {

			return;
		}

		values[pos] = c;
	}

	//Get grid value as a string
	string get_value() {

		string s = "";
		for (int i = 0; i < 9; ++i) {

			s += values[i];
		}

		return s;
	}
};