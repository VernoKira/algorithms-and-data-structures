#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

struct BST {
private:
  Node* push(Node* cur, int val) {
    if (cur==NULL) {
      return new Node(val);
    }
    if (val > cur->val) {
      cur->right = push(cur->right, val);
    } else if (val < cur->val) {
      cur->left = push(cur->left, val);
    }
    return cur;
  }

  int search(Node* cur, int target, int cnt) {
    if (cur==NULL) return 0;
    cnt++;
    if (cur->val == target) return cnt;
    if (cur->val > target) return search(cur->left, target, cnt);
    return search(cur->right, target, cnt);
  }

public:
  Node * root;
  BST() {
    this->root = NULL;
  }

  void push(int val) {
    Node* newNode = push(root, val);
    if (!root) root = newNode;
  }

  int search(int target) {
      int cnt = 0;
    return search(root, target, cnt);
  }


};

int main(){
    BST bst;
    int n, x, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        bst.push(x);
        sum+=(x - bst.search(x) + 1);
    }
    cout << sum;
}