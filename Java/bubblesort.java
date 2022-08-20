import java.util.*;

class BubbleSort {
  void bubbleSort(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
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
    BubbleSort bs = new BubbleSort();
    int arr[] = { 98, 76, 45, 34, 8, 21, 867, 90, 0 };
    bs.bubbleSort(arr);
    bs.printArr(arr);
  }

}
