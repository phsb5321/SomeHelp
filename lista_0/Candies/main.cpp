#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int test_cases = 0;
    int input_case = 0;
    int answer = 0;

    cin >> test_cases;

    for (int a = 0; a < test_cases; a++)
    {
        cin >> input_case;
        switch (input_case >= 8)
        {
        case true:
            input_case = input_case - 5;
            while (input_case % 3 != 0 && input_case > 3)
            {
                input_case = input_case - 5;
            }
            if (input_case >= 3)
            {
                printf("Case %d: %d\n", a + 1, input_case);
                break;
            }

        default:
            printf("Case %d: -1\n", a + 1);
            break;
        }
    }

    return 0;
}
