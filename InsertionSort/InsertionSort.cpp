#include "iostream"

using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    { // O(n)
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        { // O(i - 1)
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = v;
    }
}

int main(int argc, char const *argv[])
{
    int blau[] = {5, 3, 2, 0, 1, 4, 7, 9, 8, 10};
    int size = sizeof(blau) / sizeof(blau[0]);
    insertionSort(blau, size);
    for (int k = 0; k < size; k++)
    {
        cout << blau[k] << " ";
    }
    cout << endl;
    return 0;
}
