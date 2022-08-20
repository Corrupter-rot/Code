import java.util.*;

class SelectionSort {
  void selectionSort(int arr[]) {
    int n = arr.length;

    for (int i = 0; i < n - 1; i++) {
      int min = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min]) {
          min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
      }
    }
  }

  void printArr(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String args[]) {
    SelectionSort ss = new SelectionSort();
    int arr[] = { 78, 56, 77, 90, 45, 23, 4, 23, 2, 1 };
    ss.selectionSort(arr);
    ss.printArr(arr);
  }
}
