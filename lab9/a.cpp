#include <bits/stdc++.h>
using namespace std;
int prefix_function(string s, string t) {
  int a = s.size();
  int n = t.size();
  int cnt = 0;
  bool pass = false;
  for (int i = 0; i < a; i++) {
    int j = i, k = 0, count = 1;
    while (k < n && s[j] == t[k]) {
      if (k == n - 1) {
        pass = true;
        break;
      }
      j = (j + 1) % a;
      if (j == 0) count++;
      k++;
    } 
    if (pass){
        return count;
    }
  }
  return -1;
}
int main(){
    string s, t;
    cin >> s >> t;

    cout << prefix_function(s, t);
    return 0;
}