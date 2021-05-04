// Here is the top-down approach of 
// dynamic programming
class knapsack {

    // A utility function that returns
    // maximum of two integers
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Returns the value of maximum profit
    static int knapSackRec(int W, int wt[], int val[], int n, int[][] dp) {

        // Base condition
        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] > W)

            // Store the value of function call
            // stack in table before return
            return dp[n][W] = knapSackRec(W, wt, val, n - 1, dp);

        else

            // Return value of table after storing
            return dp[n][W] = max((val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1, dp)),
                    knapSackRec(W, wt, val, n - 1, dp));
    }

    static int knapSack(int W, int wt[], int val[], int N) {

        // Declare the table dynamically
        int dp[][] = new int[N + 1][W + 1];

        // Loop to initially filled the
        // table with -1
        for (int i = 0; i < N + 1; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;

        int answer = knapSackRec(W, wt, val, N, dp);
        outAnswer(dp);

        return answer;
    }

    static void outAnswer(int input[][]) {
        int mainNum = input.length;

        System.out.format("%3s & ", ".");
        for (int i = 0; i < input[0].length; i++) {
            System.out.format("%3s & ", i);
        }
        System.out.println("\\\\ \n \\hline");

        for (int i = 0; i < mainNum; i++) {
            System.out.format("%3s & ", String.valueOf(i));
            for (int j = 0; j < input[i].length; j++) {
                String value = (input[i][j] != -1) ? String.valueOf(input[i][j]) : "-1";
                System.out.format("%3s & ", value);
            }
            System.out.println("\\\\ \n \\hline");
        }

    }

    // Driver Code
    public static void main(String[] args) {
        int val[] = { 10, 40, 30, 50 };
        int wt[] = { 5, 4, 6, 3 };

        int W = 10;
        int N = val.length;
        // knapSack(W, wt, val, N);
        int answer[][] = {
            {0, 0,   0,  0,  0,  0,  0,  0,  0, 0,0 },
            {0, 0,  -1,  0,  0, -1, 10, 10, -1, -1, 10 },
            {0, 0,  -1, -1, 40, -1, -1, 40, -1, -1, 50 },
            {0, -1, -1, -1, -1, -1, -1, 40, -1, -1, 70 },
            {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 90}
        };

        outAnswer(answer);

    }
}
