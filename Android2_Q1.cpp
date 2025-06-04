#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<vector<string>> results;

	void solve(int n, int row, vector<string>& board,
	           vector<bool>& cols,
	           vector<bool>& diag1,   // row - col + n - 1
	           vector<bool>& diag2) { // row + col
		if (row == n) {
			results.push_back(board);
			return;
		}

		for (int col = 0; col < n; ++col) {
			if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
				continue;

			board[row][col] = 'Q';
			cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

			solve(n, row + 1, board, cols, diag1, diag2);

			// backtrack
			board[row][col] = '.';
			cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		vector<bool> cols(n, false);
		vector<bool> diag1(2 * n - 1, false);
		vector<bool> diag2(2 * n - 1, false);

		solve(n, 0, board, cols, diag1, diag2);
		return results;
	}
};

int main() {
	Solution sol;
	int n = 4;
	vector<vector<string>> solutions = sol.solveNQueens(n);

	for (const auto& board : solutions) {
		for (const string& row : board)
			cout << row << endl;
		cout << "------" << endl;
	}

	return 0;
}
