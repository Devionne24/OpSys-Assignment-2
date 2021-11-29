#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//Creation of variables and arrays
	int k, j, m, i, n;
	ifstream file;
	int alloc[5][3], maximum[5][3];
	int avail[3];

	//Necessary to open input file
	file.open("input.txt");
	if (!file.is_open()) {
		return -1;
	}

	file >> n;
	file >> m;
	
	//Recieving file information 
	//for loop for different scenarios 
	
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			file >> alloc[i][j];
			
		}
	}

	for (i = 0; i < 5; ++i) {
		for (j = 0; j < 3; ++j) {
			file >> maximum[i][j];
		}
	}

	for (i = 0; i < m; ++i) {
		file >> avail[i];
	}
	int f[5], answer[5], ind = 0; 
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}

	int need[5][3];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = maximum[i][j] - alloc[i][j];
	}

	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					answer[ind++] = i;
					for (y = 0; y < m; y++) {
						avail[y] = avail[y] + alloc[i][y];
					}
					f[i] = 1;
				}
			}
		}
	}
	cout << "System is currently in a safe state." << endl;
	cout << "This is the Safe Sequence: " << endl;
	for (i = 0; i < n - 1; i++) {
		cout << " P" << answer[i] << " ->";
	}

	cout << " P" << answer[n - 1] << endl;
	return 0;
}


