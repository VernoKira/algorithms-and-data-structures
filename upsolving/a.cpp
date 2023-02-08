#include <bits/stdc++.h>
using namespace std;
vector<int> v(1000);

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
    this->left = this->right = NULL;
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
  
  void cnt_tr(Node *cur, int depth) {
      if(cur==NULL) return;
        Node *left = cur->left;
        Node *right = cur->right;
        while(left && right) {
            v[depth]++;
            depth++;
            left = left->left;
            right = right->right;
        }
        depth = 0;
        cnt_tr(cur->left, depth);
        cnt_tr(cur->right, depth);
    }

public:
  Node * root;
  BST() {
    this->root = NULL;
  }

  void insert(int val) {
    Node* newNode = push(root, val);
    if (!root) root = newNode;
  }

  void cnt_t(){
      int depth = 0;
        cnt_tr(root, depth);
  }
  
    

};

int main(){
    BST b;
    int n, x; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        b.insert(x);
    }
    b.cnt_t();
    for(int i = 0; i < n - 1; i++){
        cout << v[i] << " ";
    }
    
}