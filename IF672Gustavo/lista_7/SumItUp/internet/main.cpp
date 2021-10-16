#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, List[20];
vector<int> ans[10000];
int nOfans;

void backtracking(int pos, int sum)
{
    if (sum == T) {
        ans[nOfans+1] = ans[nOfans];
        ++nOfans;
        return;
    }
    for (int i = pos; i < N; ++i) {
        if (sum + List[i] <= T) {
            sum += List[i];
            ans[nOfans].push_back(List[i]);

            backtracking(i + 1, sum);

            sum -= List[i];
            ans[nOfans].pop_back();
        }
    }
}
bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) continue;
        return a[i] > b[i];
    }
    return a.size() > b.size();
}
void PrintOut(vector<int> &V)
{
    printf("%d", V[0]);
    for (int i = 1; i < V.size(); ++i)
        printf("+%d", V[i]);
    printf("\n");
}
int main()
{
    while (scanf("%d %d", &T, &N) && N) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &List[i]);
        }
        for (auto  &v : ans) v.clear();
        nOfans = 0;

        backtracking(0, 0);

        printf("Sums of %d:\n", T);
        if (nOfans == 0)
            puts("NONE");
        else {
            sort(ans, ans + nOfans, cmp);
            PrintOut(ans[0]);
            for (int i = 1;i < nOfans; ++i)
                if (ans[i] != ans[i-1]) // 確認答案是否已經存在
                    PrintOut(ans[i]);
        }
    }
}