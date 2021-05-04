import java.util.*;

public class Main {

    static class Graph {

        private Map<String, ArrayList<String>> storage = new HashMap<>();

        private List<String> getAdjVertices(String label) {
            return storage.get(label);
        }

        Map<String, String> list_of_nodes = new HashMap<>();

        public void insertNODE(String label) {
            if (!storage.containsKey(label)) {
                storage.put(label, new ArrayList<>());
                list_of_nodes.put(label, label);
            }
        }

        public void insertARESTA(String label1, String label2) {
            String v1 = label1;
            String v2 = label2;

            storage.get(v1).add(v2);
            storage.get(v2).add(v1);
        }

        public String BFS(String root) {

            Queue<String> queue = new LinkedList<String>();
            Map<String, Integer> visited = new HashMap<String, Integer>();
            Map<Integer, ArrayList<String>> rank = new HashMap<Integer, ArrayList<String>>();

            String answer = "";

            queue.add(root);
            visited.put(root, 0);
            list_of_nodes.remove(root);

            ArrayList<String> first_rank = new ArrayList<String>();
            first_rank.add(root);
            rank.put(0, first_rank);

            int number_of_nodes_found = 1;

            while (!queue.isEmpty()) {
                String node = queue.poll();
                for (String value : this.getAdjVertices(node)) {
                    if (!visited.containsKey(value)) {
                        number_of_nodes_found += 1;
                        visited.put(value, visited.get(node) + 1);

                        int index = visited.get(value);
                        if (!rank.containsKey(index)) {
                            ArrayList<String> some_rank = new ArrayList<String>();
                            some_rank.add(value);
                            rank.put(index, some_rank);
                        } else {
                            ArrayList<String> some_rank = rank.get(visited.get(value));
                            some_rank.add(value);
                            rank.put(index, some_rank);
                        }

                        queue.add(value);
                        list_of_nodes.remove(value);
                    }
                }

            }

            for (int index : rank.keySet()) {
                ArrayList<String> some_rank = rank.get(index);
                Collections.sort(some_rank);
                rank.put(index, some_rank);

                for (String name : rank.get(index)) {
                    answer += name + " " + index + "\n";
                }
            }

            ArrayList<String> rest = new ArrayList<String>(list_of_nodes.keySet());
            Collections.sort(rest);
            for (String value : rest) {
                number_of_nodes_found += 1;
                answer += value + " " + "undefined" + "\n";
            }

            return String.valueOf(number_of_nodes_found) + "\n" + answer;
        }

    }

    public static void main(String[] args) throws Exception {

        String first, second, third;
        String str_builder = "";

        Scanner scan = new Scanner(System.in);
        int rounds = Integer.parseInt(scan.nextLine());
        for (int l = 0; l < rounds; l++) {
            Graph graph = new Graph();

            int competitors = Integer.parseInt(scan.nextLine());
            for (int a = 0; a < competitors; a++) {
                String inputs[] = scan.nextLine().split(" ");
                first = inputs[0];
                second = inputs[1];
                third = inputs[2];

                graph.insertNODE(first);
                graph.insertNODE(second);
                graph.insertNODE(third);

                graph.insertARESTA(first, second);
                graph.insertARESTA(first, third);
                graph.insertARESTA(second, third);
            }
            str_builder += graph.BFS("Ahmad");
        }
        System.out.print(str_builder);
        scan.close();
    }
}
