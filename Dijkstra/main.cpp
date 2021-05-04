#include <bits/stdc++.h>
#include <algorithm>
#define V 9
using namespace std;

char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F'};
char helper[] = {'A', 'B', 'C', 'D', 'E', 'F'};
int indexHelper[] = {5, 4, 3, 2, 1, 0};

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (auto x : helper)
        cout << x << " & ";

    cout << "\\\\" << endl;

    for (auto x : helper)
        cout << "I | ";

    cout << endl;

    for (auto x : helper)
        cout << "x | ";

    cout << endl
         << endl;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet);

        cout << "&";
        for (auto x : helper)
            cout << x << " & ";
        cout << "\\\\" << endl
             << "\\hline"
             << endl;

        cout << "Distância & ";
        for (auto x : indexHelper)
        {
            if (dist[x] > 20)
                cout << "$\\infty$"
                     << " & ";
            else
                cout << dist[x] << " & ";
        }
        cout << "\\\\" << endl
             << "\\hline"
             << endl;

        cout << "Visitados & ";
        for (auto x : indexHelper)
        {
            if (sptSet[x] == true)
                cout << "\\checkmark & ";
            else
                cout << "x & ";
        }
        cout << "\\\\" << endl
             << "\\hline\n"
             << endl;

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}

int main()
{
    sort(alpha, alpha + 6, greater<int>());

    /* Let us create the example graph discussed above */
    int graph[V][V] = {
        {0, 0, 0, 14, 13, 4},
        {0, 0, 2, 5, 0, 0},
        {0, 2, 0, 2, 4, 15},
        {14, 5, 2, 0, 1, 0},
        {13, 0, 4, 1, 0, 8},
        {4, 0, 15, 0, 8, 0}};

    dijkstra(graph, 0);

    return 0;
}
