#include <cstdio>
#include <iostream>

using namespace std;

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }

    return -1;
}

int confirm_first(int arr[], int index)
{
    int test = arr[index];
    int helper = test;
    while (test == helper)
    {
        if (helper == arr[index - 1]) { index--; }
        else { break; }
    }
    return index;
}

int main()
{
    int inputLength = 0;
    int numOfQueries = 0;
    string str_builder = "";

    scanf("%i %i", &inputLength, &numOfQueries);

    int storage[inputLength];

    int input = 0;
    int size = 0;
    int answer = 0;

    for (int a = 0; a < inputLength; a++)
    {
        scanf(" %d", &storage[a]);
    }

    for (int b = 0; b < numOfQueries; b++)
    {
        scanf("%d", &input);
        answer = binary_search(storage, 0, inputLength - 1, input);
        if (answer != -1)
        {
            answer = confirm_first(storage, answer);
        }
        str_builder += to_string(answer) + "\n";
    }

    cout << str_builder << endl;
    return 0;
}
