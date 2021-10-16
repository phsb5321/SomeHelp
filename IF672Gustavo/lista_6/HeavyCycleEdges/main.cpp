#include <bits/stdc++.h>

using namespace std;

struct Conection {
    int first, weight, second;
};

bool compareConection(Conection someValue, Conection someOtherValue) {
    return someValue.weight < someOtherValue.weight;
}

vector<Conection> storage;
int numOfVertices;
vector<int> answer;
vector<int> parent;

// Find set of vertex i
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST() {
    int mincost = 0; // Cost of min MST.

    for (int i = 0; i < numOfVertices; i++)
        parent[i] = i;

    for (Conection j : storage) { // FOR EVERY CONECTION
        int min = INT_MAX;
        answer.push_back(j.weight);
        if (find(j.first) != find(j.second) && j.weight < min) {
            answer.pop_back();
            min = j.weight;
            union1(j.first, j.second);
//            printf("%d -%d-> %d  \n", j.first, j.second, min);
            mincost += min;
        }
    }
}

int main() {

    int numOfEdges;
    scanf("%d %d", &numOfVertices, &numOfEdges);

    string str_build;

    while (numOfVertices != 0 || numOfEdges != 0) {
        answer.clear();

        storage.resize(numOfEdges);
        parent.resize(numOfVertices);

        int firstNode, weight, secondNode;
        for (int x = 0; x < numOfEdges; x++) {
            scanf("%d %d %d", &firstNode, &secondNode, &weight);
            storage[x] = {firstNode, weight, secondNode};
        }
        sort(storage.begin(), storage.end(), compareConection);
        kruskalMST();
        if (!answer.empty()) {
            int x = 0;
            for (x; x < answer.size() - 1; x++) {
                str_build += to_string(answer[x]) + " ";
            }
            str_build += to_string(answer[x]);
            str_build += "\n";
        } else {
            str_build += "forest\n";
        }
        scanf("%d %d", &numOfVertices, &numOfEdges);
    }
    cout << str_build;
    return 0;
}
