import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner ls = new Scanner(System.in);
        int n = ls.nextInt();
        for (int a = 0; a < n; a++) {
            boolean key = false;
            int c = ls.nextInt();
            if (c >= 8) {
                c = c - 5;
                while (c % 3 != 0 && c > 3) {
                    c = c - 5;
                }
                if (c >= 3) {
                    key = true;
                    String k = String.format("Case %d: %d", a + 1, c);
                    System.out.println(k);
                }
            }
            if (c < 8 && !key) {
                String b = String.format("Case %d: -1", a + 1);
                System.out.println(b);
            }
        }

        ls.close();
    }
}
