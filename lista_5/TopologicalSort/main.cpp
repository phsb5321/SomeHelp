#include <iostream>
#include <vector>
#include <list>

using namespace std;
const int MAX = 100000;

class Graph
{
private:
public:
    vector<int> G[MAX];
    list<int> out;
    bool vis[MAX];

    Graph(int N)
    {
        for (int i = 0; i < N; ++i)
            vis[i] = false;
    }
    void dfs(int u)
    {
        vis[u] = true;
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (!vis[v])
                dfs(v);
        }
        out.push_front(u);
    }

    void push_back(int root, int newNode)
    {
        G[root].push_back(newNode);
    }
};

int N;

int main()
{
    int s, t, M;
    cin >> N >> M;

    Graph G = Graph(N);

    for (int i = 0; i < M; ++i)
    {
        cin >> s >> t;
        G.push_back(s, t);
    }
    for (int i = 0; i < N; ++i)
    {
        if (!G.vis[i])
            G.dfs(i);
    }
    for (list<int>::iterator it = G.out.begin(); it != G.out.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}