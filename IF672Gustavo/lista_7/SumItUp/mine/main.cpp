#include <bits/stdc++.h>
#include <vector>

using namespace std;
string str_builder = "";

int SUM, NumOfElements, Elements[15];
vector<int> Answer[1000];
int Curr;

void backtraking(int currentSum, int position)
{
    if (currentSum == SUM)
    {
        Answer[Curr + 1] = Answer[Curr];
        Curr++;
        return;
    }

    for (int i = position; i < NumOfElements; i++)
    {
        if (currentSum + Elements[i] <= SUM)
        {
            currentSum += Elements[i];
            Answer[Curr].push_back(Elements[i]);

            backtraking(currentSum, i + 1);
            currentSum -= Elements[i];
            Answer[Curr].pop_back();
        }
    }
}

bool compare(vector<int> someValue, vector<int> anotherValue)
{
    for (int i = 0; i < someValue.size(); i++)
    {
        if (someValue[i] == anotherValue[i])
            continue;
        return someValue[i] > anotherValue[i];
    }
    return someValue.size() > anotherValue.size();
}

void BuildAnswer(vector<int> &V)
{
    str_builder += to_string(V[0]);
    for (int i = 1; i < V.size(); ++i)
        str_builder += "+" + to_string(V[i]);
    str_builder += "\n";
}

int main()
{
    while (scanf("%d %d", &SUM, &NumOfElements) && NumOfElements)
    {
        for (int i = 0; i < NumOfElements; i++)
            scanf("%d", &Elements[i]);

        for (auto &j : Answer)
            j.clear();
        Curr = 0;

        backtraking(0, 0);
        str_builder += "Sums of " + to_string(SUM) + ":\n";

        if (Curr == 0)
            str_builder += "NONE\n";
        else
        {
            // ANSWER + CURR REPRESENTS A LOCATION IN MEMORY
            sort(Answer, Answer + Curr, compare);
            BuildAnswer(Answer[0]);
            for (int i = 1; i < Curr; i++)
                if (Answer[i] != Answer[i - 1])
                    BuildAnswer(Answer[i]);
        }
    }
    str_builder.pop_back();
    cout << str_builder << endl;
    return 0;
}