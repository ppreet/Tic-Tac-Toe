//Driver program for Tic-Tac-Toe

#include"Graphics.h"
using namespace std;

int main() {

	//Variables
	bool game_run = true;
	int opt = 1;
	unordered_map<string, int> player_tracker;

	//Switch variables
	Grid curr = Grid();
	string player1, player2;

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
			cout << "Enter Player 1: ";
			cin >> player1;
			cout << "Enter Player 2: ";
			cin >> player2;

			//Initialize Grid
			curr.print_grid();
			curr.set_value(1, 'x');
			curr.print_grid();
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