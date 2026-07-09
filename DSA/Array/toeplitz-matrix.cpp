// https://leetcode.com/problems/toeplitz-matrix/description/


#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

bool isValid(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
	bool isToeplitz = true;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0; i < n; i++) {
		int I = 0, J = i;
		int cur = matrix[I][J];
		while (isValid(I, J, m, n)) {
			isToeplitz &= (cur == matrix[I][J]);
			I++, J++;
		}
	}

	for (int i = 0; i < m; i++) {
		int I = i, J = 0;
		int cur = matrix[I][J];
		while (isValid(I, J, m, n)) {
			isToeplitz &= (cur == matrix[I][J]);
			I++, J++;
		}
	}

	return isToeplitz;
}


void solution() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	cout << isToeplitzMatrix(arr) << endl;

}

int32_t main() {

	// Test Case
	bool TEST_CASE = !true;

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	// cin.ignore(); // In Case getline(cin, s)

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}