#include <iostream>
using namespace std;
int main() {
	int q;
	cin >> q; // number of questions

	// loop q times
	while (q > 0) {
		int row, col;
		cin >> row >> col;
		char str[row][col]; // 2d array of string of characters

		// accept string of characters for row times
		for(int i = 0, frow = row; frow > 0; frow--, i++) {
			cin >> str[i];
		}

		/*
			cur_border -> current border of the row
			prev_border -> highest number of borders
			prev -> check if prev character is a border
		*/
		int cur_border = 0, prev_border = -1, prev = true;

		// loop through the row of the string
		for(int i = 0, frow = row; frow > 0; frow--, i++) {
			// current row's border
			int border = 0;

			// loop through the column of the current row
			for (int c = 0, fcol = col; fcol > 0; fcol--, c++) {
				// if border
				if (str[i][c] == '#') {
					// increment if previous was also a border
					if (prev == true) {
						border++;
					}
					// reset to 1 if previous was not a border
					else {
						border = 1;
					}

					prev = true;
				}
				// if not border
				else {
					prev = false;
				}

				/*
					if current calculated border of the row is
					greater than the previous calculated border
				*/
				if (border > cur_border) {
					cur_border = border;
				}
			}

			/*
				if the border of the current row is greater than
				the border of the previous rows
			*/
			if (cur_border > prev_border) {
				int temp = prev_border;
				prev_border = cur_border;
				cur_border = temp;
			}
		}

		cout << prev_border << endl;
		q--;
	}
}
