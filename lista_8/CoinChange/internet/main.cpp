#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str_builder;
    //pre-calculating every possible amount of money can be given as input
    int way[7490];
    int coin[5] = {50, 25, 10, 5, 1};
    memset(way, 0, sizeof(way));
    way[0] = 1; //not taking any coins also an option
    for (int j = 0; j < 5; j++)
    {
        for (int i = 1; i < 7490; i++)
        {
            if (i >= coin[j])
            {
                way[i] += way[i - coin[j]]; // using dynamic approach
            }
        }
    }
    int amount;
    while (scanf("%d\n", &amount) >= 1)
    {
        scanf("%d", &amount);
        int answer = way[amount];
        str_builder += to_string(answer);
    }
    cout << str_builder;
}