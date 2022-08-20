#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  int rank[n];
  for (int i = 0; i < n; i++) {
    cin >> rank[i];
  }
  cin >> m;
  int player[m];
  for (int i = 0; i < m; i++) {
    cin >> player[m];
  }

  int k = 1;
  for (auto j : player) {
    for (int i = 0; i < n; i++) {
      cout << i << " : " << k << endl;
      if (j >= rank[i]) {
        cout << k << endl;
        break;
      }
      if (i < n && rank[i] != rank[i + 1]) {
        ++k;
      }
    }
  }

  return 0;
}
