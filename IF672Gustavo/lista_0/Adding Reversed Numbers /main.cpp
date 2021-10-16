#include <iostream>
using namespace std;

string reverter(string input)
{
    int helper = input.length();
    string inverted_input = "";

    for (int c = 0; c < helper; c++)
        inverted_input += input[helper - c - 1];

    return inverted_input;
}

string removeLeadingZeros(string input)
{
    int helper = input.length();
    bool leadinZero = true;
    string answer = "";
    for (int d = 0; d < helper; d++)
    {
        if (leadinZero && input[d] != '0')
        {
            answer += input[d];
            leadinZero = false;
        }

        else if (!leadinZero)
            answer += input[d];
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int test_cases = 0;
    int first_input = 0;
    int second_input = 0;
    int inverted_sum = 0;

    cin >> test_cases;
    for (int a = 0; a < test_cases; a++)
    {
        cin >> first_input >> second_input;
        string fisrt_string = to_string(first_input);
        string second_string = to_string(second_input);

        string inverted_first_input = reverter(fisrt_string);
        string inverted_second_input = reverter(second_string);

        inverted_sum = stoi(inverted_first_input) + stoi(inverted_second_input);

        string string_not_inverted_sum = reverter(to_string(inverted_sum));
        string_not_inverted_sum = removeLeadingZeros(string_not_inverted_sum);

        cout << string_not_inverted_sum << endl;
    }

    return 0;
}
