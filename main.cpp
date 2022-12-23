#include <iostream>
#include "board.h"
using namespace std;

int main() {
	vector<vector<char>> board = createEmptyBoard();
	char currentPlayer = 'X';

	while (true) {
		//Print the current state of the board
		printBoard(board);

		//Get the player's move
		int row, col;
		cout << "Player " << currentPlayer << ", enter your move (row col): ";
		cin >> row >> col;

		//Make sure the move is valid
		if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
			cout << "Invalid move. Try again." << endl;
			continue;
		}

		//Make the move
		board[row][col] = currentPlayer;

		//Check if the player has won
		if (checkWin(board, currentPlayer)) {
			cout << "Player " << currentPlayer << " has won!" << endl;
			break;
		}

		//Check if the game is a draw
		if (checkDraw(board)) {
			cout << "It's a draw!" << endl;
			break;
		}

		//Switch to the other player
		if (currentPlayer == 'X') {
			currentPlayer = 'O';
		}
		else {
			currentPlayer = 'X';
		}
	}

	return 0;
}