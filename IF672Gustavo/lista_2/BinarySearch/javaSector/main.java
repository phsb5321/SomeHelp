import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    static int binarySearch(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        String[] input = in.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);
        int[] myIntArray = new int[N];

        String[] bob = in.readLine().split(" ");
        for (int p = 0; p < N; p++) {
            myIntArray[p] = Integer.parseInt(bob[p]);
        }
        for (int i = 0; i < Q; i++) {
            int match = Integer.parseInt(in.readLine());
            int carlinhos = binarySearch(myIntArray, 0, N - 1, match);
            while (carlinhos > 1 && myIntArray[carlinhos - 1] == match) {
                carlinhos--;
            }
            result.append(carlinhos + "\n");
        }
        System.out.println(result);
    }
}