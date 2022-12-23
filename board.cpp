#include "board.h"
#include <iostream>
using namespace std;

vector<vector<char>> createEmptyBoard() {
	vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
	return board;
}

void printBoard(const vector<vector<char>>& board) {
	cout << "  0 1 2" << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i << " ";
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkWin(const vector<vector<char>>& board, char symbol) {
	//Check rows
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
			return true;
		}
	}

	//Check columns
	for (int j = 0; j < BOARD_SIZE; j++) {
		if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
			return true;
		}
	}

	//Check diagonals
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
		return true;
	}

	if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
		return true;
	}

	return false;
}

bool checkDraw(const vector<vector<char>>& board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}