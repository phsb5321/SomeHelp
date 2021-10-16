#include <cstdio>
#include <iostream>
#include <stack>

#include <fstream>

using namespace std;

int count, i;

string line;
stack<char> pilha;

int main()
{


    ofstream myfile;
    myfile.open("CPP.txt");

    scanf("%d\n", &count);

    while (count--)
    {

        while (pilha.size() > 0)
        {
            pilha.pop();
        }

        getline(cin, line);

        for (i = 0; i < line.size(); i++)
        {

            if (line[i] == '(' || line[i] == '[')
            {
                pilha.push(line[i]);
            }
            else if (pilha.empty())
            {
                pilha.push('E');
                break;
            }
            else if (line[i] == ')' && pilha.top() == '(')
            {
                pilha.pop();
            }
            else if (line[i] == ']' && pilha.top() == '[')
            {
                pilha.pop();
            }
            else
            {
                pilha.push('E');
                break;
            }
        }

        if (pilha.size() == 0)
        {
            myfile << "Yes\n";
        }
        else
        {
            myfile << "No\n";
        }
    }

    myfile.close();

    return 0;
};