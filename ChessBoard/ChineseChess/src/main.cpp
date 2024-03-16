/**
*
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "chinesechess.h"

int main(int argc, const char *argv[])
{

	cout << "Chinese Chess" << endl;
	
	// declare Chinese Chess object
	ChineseChess	chess;

	cout << "_________" << endl;
	

	chess.printChessBoard();

	// keep get action command from player and move the pieces on chess board.
	while (1)
	{
		string cmd;

		cout << "Please enter command ('q' to quit; 'r' to start a new game): ";
		std::getline(std::cin, cmd);

		if (cmd == "q" || cmd == "quit") break;
		if (cmd == "Q" || cmd == "QUIT") break;

		if (cmd == "r" || cmd == "reset")
		{
			// reset to start a new game
			chess.reset();
			chess.printChessBoard();
			continue;
		}

		// check if this game is over. 
		if (chess.isGameOver())
		{
			// do not accept moving command
			cout << "This game is over." << endl;
			continue;
		}

		cout << "Command: " << cmd << endl;

		try
		{
			if (chess.move(cmd))
				chess.printChessBoard();
			else
				cout << "Invalid command." << endl;
		}
		catch (exception e)
		{
			chess.printChessBoard();
		}

		if (chess.isGameOver())
		{
			cout << "*** Game over ***" << endl;
		}
	}

	return 1;
}

