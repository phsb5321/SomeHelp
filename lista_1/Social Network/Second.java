import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Second {
    static class Pilha {
        private int storage[];
        private int size, curr;

        Pilha(int value) {
            this.storage = new int[value];
            this.size = value;
            this.curr = 0;
        }

        public void resizeStorage() {
            int copy[] = this.storage;
            this.storage = new int[size * 2];
            for (int a = 0; a < this.size; a++) {
                this.storage[a] = copy[a];
            }
            this.size = this.size * 2;
        }

        public void append(int value) {
            if (this.size == this.curr + 1) {
                this.resizeStorage();
            }
            this.storage[this.curr] = value;
            this.curr++;
        }

        public boolean contain(int value, int screenSize) {
            int helper = Math.min(screenSize, curr);
            for (int b = curr; b >= curr - helper; b--) {
                if (this.storage[b] == value) {
                    return true;
                }

            }
            return false;
        }

        public int[] getValue(int screenSize) {
            int helper = Math.min(screenSize, curr);
            int answer[] = new int[helper];
            for (int b = curr; b > curr - helper; b--) {
                answer[curr - b] = this.storage[b - 1];
            }

            return answer;
        }

    };
}
