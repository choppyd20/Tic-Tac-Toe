#pragma once
#include <vector>
using namespace std;

const int BOARD_SIZE = 3;

vector<vector<char>> createEmptyBoard();
void printBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>> & board, char symbol);
bool checkDraw(const vector<vector<char>>& board);