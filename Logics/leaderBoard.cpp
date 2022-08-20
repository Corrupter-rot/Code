#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  stack<int> rank;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (rank.empty() || rank.top() != temp) {
      rank.push(temp);
    }
  }
  int m;
  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    while (!rank.empty() && temp >= rank.top())
      rank.pop();
    cout << (rank.size() + 1) << endl;
  }
  return 0;
}
