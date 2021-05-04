#include "vector"
#include "cstdio"
#include "queue"
#include "list"
#include "bitset"

using namespace std;
typedef pair<int, int> conection;

const long long int INF = 1e11 + 100;
const int MAXN = 1e5 + 3;
vector<vector<conection>> storage;
int numOfVertices;
vector<int> path;
bitset<MAXN> isDone;

bool smallestPath() {
    priority_queue<conection, vector<conection>, greater<conection> > queue;
    vector<long long int> dist(numOfVertices + 1, INF);
    int src = 1;
    queue.push(make_pair(0, src));
    dist[src] = 0;
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (conection conect : storage[u]) {
            int node = conect.second, weight = conect.first;
            if (!isDone[u] && dist[u] + weight < dist[node]) {
                dist[node] = dist[u] + weight;
                queue.push(conection(dist[node], node));
                path[node] = u;
            }
        }
        isDone[u] = true;
    }
    if (dist[numOfVertices] != INF)
        return true;
    return false;
}

int main() {

    int numOfEdges;
    scanf("%d %d", &numOfVertices, &numOfEdges);
    storage.resize(numOfVertices + 1);
    path.resize(numOfVertices + 1, -1);

    int firstNode, weight, secondNode;
    for (int x = numOfEdges; x >= 1; x--) {
        scanf("%d %d %d", &firstNode, &secondNode, &weight);
        storage[firstNode].push_back(conection(weight, secondNode));
        storage[secondNode].push_back(conection(weight, firstNode));
    }
    if (smallestPath()) {
        vector<int> smalletsPath;
        for (int i = numOfVertices; i != path[1]; i = path[i])
            smalletsPath.push_back(i);

        for (int i = smalletsPath.size() - 1; i >= 0; --i)
            printf("%d ", smalletsPath[i]);

    } else printf("-1\n");

    return 0;
}
