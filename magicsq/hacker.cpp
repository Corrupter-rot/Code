#include <iostream>

using namespace std;

// all possible pairs;
/* 1 and 9 */
/* 2 and 8 */
/* 3 and 7 */
/* 4 and 6 */

int main() {
  int predefineMatrix[][3][3] = {
      {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
      {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
      {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
      {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
  };
  int userMatrix[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> userMatrix[i][j];
    }
  }

  int min = 82;

  for (int k = 0; k < 8; k++) {
    int currentMin = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        currentMin += abs(predefineMatrix[k][i][j] - userMatrix[i][j]);
      }
    }
    if (currentMin < min)
      min = currentMin;
  }
  cout << min << endl;
  return 0;
}
