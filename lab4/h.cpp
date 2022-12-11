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
	void _inorder(Node* cur) {
		if (cur==NULL) return;
		_inorder(cur->right);
		cout << cur->val << " ";
		_inorder(cur->left);
	}
	Node* push(Node*cur, int val){
        if(cur==NULL) return new Node(val);
        if(val<cur->val) cur->left = push(cur->left, val);
        else cur->right = push(cur->right, val);
        return cur;
    }

	
public:
	BST() {
		this->root = nullptr;
	}
	void inorder() {
		_inorder(root);
		cout << endl;
	}
	void push(int x){
        root = push(root, x);
    }
	Node* getRoot() {
		return root;
	}

	void reverseInorder(Node* node, int& sum) {
		if (!node) return;
		reverseInorder(node->right, sum);
		sum += node->val;
		node->val = sum;
		reverseInorder(node->left, sum);
	}
};


int main() {
	BST b;
	int n;
	cin >> n;
	while (n--) {
		int node;
		cin >> node;
		b.push(node);
	}
	int s = 0;
	b.reverseInorder(b.getRoot(), s);
	b.inorder();

}