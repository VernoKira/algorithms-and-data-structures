#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;
	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		else {
			Node* found = _search(cur->left, target);
			if (found == nullptr) {
				found = _search(cur->right, target);
			}
			return found;
		}
		return nullptr;
	}

public:
	BST() {
		this->root = nullptr;
	}
	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (root == nullptr) root = newNode;
	}


	Node* search(int target) {
		return _search(root, target);
	}

	Node* getRoot() {
		return root;
	}

	int getHeight(Node* node, int& d) {
		if (!node) return 0;
		int left = getHeight(node->left, d);
		int right = getHeight(node->right, d);
		d = max(d, left + right + 1);
		return max(left, right) + 1;
	}
};

int main() {
	BST bst;
	int n;
	cin >> n;
	while (n--) {
		int node;
		cin >> node;
		bst.insert(node);
	}
	int d = 0;
	bst.getHeight(bst.getRoot(), d);
	cout << d;

	return 0;
}