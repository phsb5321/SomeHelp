import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main_ {

    public static String isWellFormed(String[] value) {
        int index = 0;
        int helper = 0;
        while (index >= 0 && helper < value.length) {
            switch (value[helper]) {
                case "(":
                    index += 1;
                    break;
                case ")":
                    index -= 1;
                    break;
                case "[":
                    index += 2;
                    break;
                case "]":
                    index -= 2;
                    break;
                default:
                    break;
            }
            helper++;
        }

        if (index == 0)
            return "Yes";
        else
            return "No";

    }

    public static void main(String[] args) throws IOException {

        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        int iterations = Integer.parseInt(scan.readLine());
        for (int i = 0; i < iterations; i++) {
            String[] input = scan.readLine().split("");
            result.append(isWellFormed(input) + "\n");
        }
        System.out.println(result);
    }
}