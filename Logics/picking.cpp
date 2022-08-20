#include <algorithm>
#include <iostream>
using namespace std;

int main() {

  int len;
  cin >> len;
  int freqArr[100] = {0}, arr[len];
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }
  for (auto i : arr) {
    freqArr[i]++;
  }
  cout << endl;
  int result = -1;
  for (int i = 1; i < 100; i++) {
    result = max(result, freqArr[i] + freqArr[i - 1]);
  }
  cout << result << endl;
  return 0;
}
