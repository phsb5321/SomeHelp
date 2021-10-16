#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str_builder;

    int numOfCases;
    scanf("%d", &numOfCases);

    while (numOfCases--)
    {
        int numOfProducts;
        scanf("%d", &numOfProducts);

        int priceArr[numOfProducts + 1],
            weightsArr[numOfProducts + 1];

        int product, weight;
        for (int i = 1; i <= numOfProducts; i++)
        {
            scanf("%d %d", &product, &weight);
            priceArr[i] = product;
            weightsArr[i] = weight;
        }

        int numOfPeople;
        scanf("%d", &numOfPeople);
        int carringCapacities[numOfPeople];
        for (int i = 0; i < numOfPeople; i++)
        {
            int carryingCapacity;
            scanf("%d", &carryingCapacity);
            carringCapacities[i] = carryingCapacity;
        }

        sort(carringCapacities, carringCapacities + numOfPeople);

        int maxCapacity = carringCapacities[numOfPeople - 1];

        // int helper[numOfProducts + 1][maxCapacity + 1];
        vector<vector<int>> helper(numOfProducts + 1, vector<int>(maxCapacity + 1, 0));
        for (int i = 1; i <= numOfProducts; i++)
        {
            for (int j = 1; j <= maxCapacity; j++)
            {
                if (weightsArr[i] > j)
                {
                    helper[i][j] = helper[i - 1][j];
                }
                else
                {
                    helper[i][j] = max(helper[i - 1][j], priceArr[i] + helper[i - 1][j - weightsArr[i]]);
                }
            }
        }

        int maxPrice = 0;

        for (auto &x : carringCapacities)
            maxPrice += helper[numOfProducts][x];

        
        cout << maxPrice << endl;

    }

    return 0;
}