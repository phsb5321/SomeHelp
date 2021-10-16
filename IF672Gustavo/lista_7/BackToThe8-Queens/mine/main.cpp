#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int positions[8], paths[8];

bool isValid(int queenNum, int index)
{
    for (int k = 0; k < queenNum; k++)
    {
        if (index == paths[k])
            return false;
        if (abs(queenNum - k) == abs(index - paths[k]))
            return false;
    }
    return true;
}

int backTracking(int numOfQueens)
{
    if (numOfQueens == 8)
        return 0;

    int MIN = 100000;

    for (int i = 0; i < 8; i++)
        if (isValid(numOfQueens, i))
        {
            paths[numOfQueens] = i;
            MIN = min(MIN, i == positions[numOfQueens]
                               ? backTracking(numOfQueens + 1)
                               : 1 + backTracking(numOfQueens + 1));
        }

    return MIN;
}

int main()
{
    string str_builder = "";
    int index = 1;
    while (scanf("%d", &positions[0]) == 1)
    {
        positions[0]--;
        for (int i = 1; i < 8; ++i)
        {
            scanf("%d", &positions[i]);
            positions[i]--;
            paths[i] = positions[i];
        }
        str_builder += "Case " + to_string(index) + ": ";
        str_builder += to_string(backTracking(0)) + "\n";
        index++;
    }
    cout << str_builder;
    return 0;
}