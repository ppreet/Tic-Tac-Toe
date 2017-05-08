//Driver program for Tic-Tac-Toe

#include"Graphics.h"
using namespace std;

char first = 'x';

char playgame(Grid* curr, string x, string o);
char game_result(Grid* curr);


int main() {

	//Variables
	bool game_run = true;
	int opt = 1;
	unordered_map<string, int> player_tracker;

	//Switch variables
	Grid curr = Grid();
	Grid *temp = &curr;
	string playerx, playero;
	char result = 'd';

	//Run the game
	while (game_run) {

		//Show Menu
		cout << "MENU" << endl;
		cout << "1: Play New Game!" << endl;
		cout << "2. Display scores" << endl;
		cout << "3. Help" << endl;
		cout << "4. Exit Game" << endl;
		cout << "Enter option: ";
		cin >> opt;

		//Switch
		switch (opt) {

		//Start New Game
		case 1:

			//Get player info
			cout << "Starting New Game..." << endl;
			cout << "Enter Player X: ";
			cin >> playerx;
			cout << "Enter Player O: ";
			cin >> playero;

			//Play game and get the result
			temp = &curr;
			temp->print_grid();
			result = playgame(temp, playerx, playero);

			//Process the result and update the score
			if (result == 'o') {

				player_tracker[playero] += 1;
				cout << playero + " won!" << endl;
			}
			else if (result == 'x') {

				player_tracker[playerx] += 1;
				cout << playerx + " won!" << endl;
			}
			else {

				//Draw
				cout << "The game is tied!" << endl;
			}

			//Reset the board
			curr.reset();

			break;

		//Display scores
		case 2:
			
			cout << "Current scores:" << endl;
			for (auto i = player_tracker.begin(); i != player_tracker.end(); ++i) {

				cout << i->first << ": " << i->second << endl;
			}
			break;

		//Display help message
		case 3:
			cout << "This is a help message" << endl;
			break;
			
		//Exit Game
		case 4:

			game_run = false;
			continue;

		//Bad option
		default:
			cout << "Option not recognized. Please try again" << endl;
			break;

		} //End switch

	} //End while



	//End main
	return 0;
}


//Function to simulate game play
//Returns x or o if there is a winner, or d is there is a draw
char playgame(Grid* game, string x, string o) {

	char curr = first;

	//Run the game
	while (true) {

		//Ask correct player for move
		if (curr == 'x') {

			int move = 0;
			cout << x + "\'s move: ";
			cin >> move;
			move -= 1; //0-indexing
			
			//Check for invalid move
			string currgrid = game->get_value();
			if (currgrid[move] == 'X' || currgrid[move] == 'O') {

				cout << "Invalid move! Try again" << endl;
				continue;
			}

			//Execute valid move
			game->set_value(move, 'X');
		}
		else if(curr == 'o') {

			int move = 0;
			cout << o + "\'s move: ";
			cin >> move;
			move -= 1; //0-indexing

			//Check for invalid move
			string currgrid = game->get_value();
			if (currgrid[move] == 'X' || currgrid[move] == 'O') {

				cout << "Invalid move! Try again" << endl;
				continue;
			}

			//Execute valid move
			game->set_value(move, 'O');
		}

		//Print grid
		game->print_grid();

		//Change curr
		if (curr == 'x') {

			curr = 'o';
		}
		else {

			curr = 'x';
		}

		//Check if the game has ended
		char result = game_result(game);

		//Continue game if no result
		if (result == 'c') {
			continue;
		}

		//Otherwise, change first and return result
		if (first == 'x') {
			first = 'o';
		}
		else {
			first = 'x';
		}

		return result;
	}

	return 'x';
}

//Function to see if game has ended
//Returns x, o, d or c (continue)
char game_result(Grid * curr){

	string check = curr->get_value();
	
	//Insert gamechecking algo here
	//Also check if all the squares are filled and it is a tie

	return 'c';
}

//Comparator to sort the scores in order
