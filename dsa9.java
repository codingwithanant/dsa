import java.util.*;

public class dsa9 {

    public static void maxHeapify(int arr[], int n, int i) {
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child
        int largest = i;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            maxHeapify(arr, n, largest);
        }
    }

    public static void heapSort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter how many numbers you want to insert: ");
        int n = sc.nextInt();
        int[] heap = new int[n];
        System.out.println("Enter " + n + " numbers:");
        for (int i = 0; i < n; i++) {
            heap[i] = sc.nextInt();
        }
        heapSort(heap, n);
        System.out.println("Sorted numbers:");
        for (int i = 0; i < n; i++) {
            System.out.println(heap[i]);
        }
    }
}
