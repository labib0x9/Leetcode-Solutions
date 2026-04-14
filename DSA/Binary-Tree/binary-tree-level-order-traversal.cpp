// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* build_tree() {
	int n;
	cin >> n;

	if (n == 0) return nullptr;

	vector<string> arr(n);
	for (auto &s : arr) {
		cin >> s;
	}
	arr.insert(arr.begin(), " ");

	vector<TreeNode*> nodes(n, nullptr);
	for (int i = 1; i <= n; i++) {
		if (arr[i] == "null") continue;
		if (nodes[i] == nullptr) nodes[i] = new TreeNode(stoi(arr[i]));
		if (2 * i <= n && arr[2 * i] != "null") {
			nodes[2 * i] = new TreeNode(stoi(arr[2 * i]));
			nodes[i]->left = nodes[2 * i];
		}
		if (2 * i + 1 <= n && arr[2 * i + 1] != "null") {
			nodes[2 * i + 1] = new TreeNode(stoi(arr[2 * i + 1]));
			nodes[i]->right = nodes[2 * i + 1];
		}
	}

	return nodes[1];
}

void destroy(TreeNode* root) {
	if (root == nullptr) return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> level;
	queue<pair<TreeNode*, int>> q;
	q.push({root, 1});
	vector<int> temp;
	int cur_level = 1;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		auto node = front.first;
		auto node_level = front.second;
		if (node == nullptr) continue;

		if (cur_level != node_level) {
			cur_level = node_level;
			level.push_back(temp);
			temp.clear();
		}

		temp.push_back(node->val);

		q.push({node->left, node_level + 1});
		q.push({node->right, node_level + 1});
	}

	if (root != nullptr) level.push_back(temp);

	return level;
}

void solution() {
	auto root = build_tree();

	for (auto level : levelOrder(root)) {
		PRINT(level);
	}

	destroy(root);
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