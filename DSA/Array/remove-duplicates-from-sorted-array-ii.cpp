// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

int removeDuplicates(vector<int>& nums) {
	int prev = 0, cnt = 1;
	int n = nums.size();
	for (int i = 0; i < n - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			cnt++;
		} else {
			nums[prev++] = nums[i];
			if (cnt >= 2) nums[prev++] = nums[i];
			cnt = 1;
		}
	}

	nums[prev++] = nums[n - 1];
	if (cnt >= 2) nums[prev++] = nums[n - 1];

	return prev;
}

void solution() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int &a : arr) {
		cin >> a;
	}

	cout <<	removeDuplicates(arr) << endl;
	PRINT(arr);

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