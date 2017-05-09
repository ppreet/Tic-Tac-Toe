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
			if (result == 'O') {

				player_tracker[playero] += 1;
				cout << playero + " won!" << endl;
				cout << endl;
			}
			else if (result == 'X') {

				player_tracker[playerx] += 1;
				cout << playerx + " won!" << endl;
				cout << endl;
			}
			else {

				//Draw
				cout << "The game is tied!" << endl;
				cout << endl;
			}

			//Reset the board
			curr.reset();

			break;

		//Display scores
		case 2:

			if (player_tracker.size() == 0) {

				cout << "No scores to show" << endl;
				cout << endl;
				break;
			}
			
			cout << "Current scores:" << endl;
			for (auto i = player_tracker.begin(); i != player_tracker.end(); ++i) {

				cout << i->first << ": " << i->second << endl;
			}

			cout << endl;

			break;

		//Display help message
		case 3:
			cout << "This is a help message" << endl;
			cout << endl;
			break;
			
		//Exit Game
		case 4:

			game_run = false;
			cout << "BYE!" << endl;
			cout << endl;
			continue;

		//Bad option
		default:
			cout << "Option not recognized. Please try again." << endl;
			cout << endl;
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

	//Control should never reach here
	return 'x';
}

//Function to see if game has ended
//Returns x, o, d or c (continue)
char game_result(Grid * curr){

	string check = curr->get_value();
	
	//Insert gamechecking algo here
	//Also check if all the squares are filled and it is a tie

	//The state of the game can be determined by checking 5 values
	//Value 0
	if (check[0] != '0') {

		char val = check[0];

		//Check row
		if (check[1] == val && check[2] == val) return val;

		//Check diagonal
		if (check[4] == val && check[8] == val) return val;

		//Check col
		if (check[3] == val && check[6] == val) return val;
	}

	//Value 1
	if (check[1] != '1') {

		char val = check[1];

		//Check col
		if (check[4] == val && check[7] == val) return val;
	}

	//Value 2
	if (check[2] != '2') {

		char val = check[2];

		//Check col
		if (check[5] == val && check[8] == val) return val;

		//Check diag
		if (check[4] == val && check[6] == val) return val;

	}

	//Value 3
	if (check[3] != '3') {

		char val = check[3];

		//Check row
		if (check[4] == val && check[5] == val) return val;
	}

	//Value 6
	if (check[6] != '6') {

		char val = check[6];

		//Check row
		if (check[7] == val && check[8] == val) return val;
	}

	//At this point, it is either a draw or the game hasn't ended
	for (int i = 0; i < check.length(); ++i) {

		//Game hasn't ended
		if (check[i] != 'X' && check[i] != 'O') {

			return 'c';
		}
	}

	//Game is a tie
	return 'd';
}

//Comparator to sort the scores in order
