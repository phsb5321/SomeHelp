#include <iostream>
#include <cstring>
using namespace std;

int search(char arr[], char x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPostOrder(char in[], char pre[], int n)
{

    int root = search(in, pre[0], n);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    cout << pre[0] << "";
}

int main()
{
    string inOrder,preOrder;
    while (cin >> preOrder >> inOrder)
    {
        char inOrderChar[inOrder.length()];
        strcpy(inOrderChar, inOrder.c_str());

        char preOrderChar[preOrder.length()];
        strcpy(preOrderChar, preOrder.c_str());

        printPostOrder(inOrderChar, preOrderChar, inOrder.length());
        cout << endl;
    }

    return 0;
}