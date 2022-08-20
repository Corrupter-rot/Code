#include <iostream>
// insertion sorting logic
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++) {
    int current = arr[i]; // 19
    int j = i - 1;        // 51
    while (arr[j] > current && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

// for desencding order flip the condition of current and arr[j] condition
