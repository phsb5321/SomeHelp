import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static class simpleList {
        private int storage[];
        private int size, curr;

        simpleList(int value) {
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

    public static void main(String[] args) throws IOException {

        StringBuilder result = new StringBuilder();

        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        String first_line = scan.readLine();
        String second_line = scan.readLine();

        String inputs[] = first_line.split(" ");
        String entryList[] = second_line.split(" ");

        simpleList storage = new simpleList(2);

        int minTerm = Integer.parseInt(inputs[0]);
        if (inputs.length > 1) {
            int chats = Integer.parseInt(inputs[1]);
            minTerm = Math.min(minTerm, chats);
        }

        for (int i = 0; i < entryList.length; i++) {
            int id = Integer.parseInt(entryList[i]);
            if (!storage.contain(id, minTerm)) {
                storage.append(id);
            }
        }

        int screenChat[] = storage.getValue(minTerm);
        result.append(screenChat.length + "\n");

        for (int d = 0; d < screenChat.length; d++) {
            String helper = String.valueOf(screenChat[d]);
            result.append(helper + " ");
        }
        System.out.println(result);
    }
}
