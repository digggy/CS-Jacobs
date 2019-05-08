
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

const int INF_WEIGHT = 100000000;

// A class for Cylinder
class Cylinder
{
public:
    int oxygen;
    int nitrogen;
    int weight;

    Cylinder(int oxygen, int nitrogen, int weight)
    {
        this->oxygen = oxygen;
        this->nitrogen = nitrogen;
        this->weight = weight;
    }
};

// Main function
int main(int argc, char **argv)
{

    int t;                        //test cases
    int min_Oxygen, min_Nitrogen; // Required oxygen and nitrogen
    int Max_Cylinders;
    int oxygen, nitrogen, weight;

    // Vector of cylinder
    vector<Cylinder> list;

    // Table to data for finding the best cylinders
    int dp[1000][22][80];

    cin >> t;
    for (int z = 0; z < t; z++)
    {
        // Asking the users for the input of the required
        cin >> min_Oxygen >> min_Nitrogen >> Max_Cylinders;
        while (
            (min_Oxygen > 21 || min_Oxygen < 1) ||
            (min_Nitrogen > 79 || min_Nitrogen < 1) ||
            (Max_Cylinders > 1000 || Max_Cylinders < 1))
        {
            //Error if the data is not within the range
            cout << "______________________________________________________" << endl;
            cout << "                    ERROR" << endl;
            cout << "   Oxygen    : " << min_Oxygen << endl
                 << "   Nitrogen  : " << min_Nitrogen << endl
                 << "   Cylinders : " << Max_Cylinders << endl;
            cout << "     => Input data not within a valid range" << endl;
            cout << "     => Reinput the datas again" << endl;
            cout << "______________________________________________________" << endl;

            cin >> min_Oxygen >> min_Nitrogen >> Max_Cylinders;
        }

        for (int i = 0; i < Max_Cylinders; i++)
        {
            // Getting the information about the cylinders
            cin >> oxygen >> nitrogen >> weight;
            try
            {
                if (oxygen > 21 || oxygen < 1)
                {
                    throw " Oxygen level should be between 1 and 21";
                }
                else if (nitrogen > 79 || nitrogen < 1)
                {
                    throw " Nitrogen level should be between 1 and 79";
                }
                else if (weight > 800 || weight < 1)
                {
                    throw "Cylinder Weight should be between 1 and 21";
                }
                else
                {
                    list.push_back(Cylinder(oxygen, nitrogen, weight));
                }
            }
            catch (const char *err)
            {
                cout << "---------------------------| ERROR |-------------------------------" << endl;
                cout << " ► " << err << endl;
                cout << " ► Input the valid Oxygen,Nitrogen and Weight followed by a space." << endl;
                cout << "-------------------------------------------------------------------" << endl;
                i--;
            }
        }

        // We have the array dp as [cylinders][oxygen][nitrogen]
        // So filling out the dp array initially with infinity or 0

        for (int i = 0; i < Max_Cylinders; i++)
            for (int j = 0; j <= min_Oxygen; j++)
                for (int k = 0; k <= min_Nitrogen; k++)
                {
                    // Initialization To a infinite
                    dp[i][j][k] = INF_WEIGHT;
                    if (j == 0 && k == 0)
                        dp[i][j][k] = 0;
                }

        //initialization of the dp  with the weights
        for (int j = 0; j <= min_Oxygen; j++)
            for (int k = 0; k <= min_Nitrogen; k++)
                if (j <= list[0].oxygen && k <= list[0].nitrogen && (j > 0 || k > 0))
                {
                    dp[0][j][k] = list[0].weight;
                }

        // The original dynamic programming algorithm
        for (int i = 1; i < Max_Cylinders; i++)
            for (int j = 0; j <= min_Oxygen; j++)
                for (int k = 0; k <= min_Nitrogen; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j <= list[i].oxygen && k <= list[i].nitrogen)
                    {
                        dp[i][j][k] = min(dp[i][j][k], list[i].weight);
                    }
                    else
                    {
                        int ox = max(0, j - list[i].oxygen);
                        int ni = max(0, k - list[i].nitrogen);
                        dp[i][j][k] = min(dp[i][j][k], list[i].weight + dp[i - 1][ox][ni]);
                    }
                }

        // Printing out the total weight
        cout << dp[Max_Cylinders - 1][min_Oxygen][min_Nitrogen] << "\n";

        // Method to get the actuall cylinders used route
        int index = Max_Cylinders - 1;
        int current_Oxygen = min_Oxygen;
        int current_Nitrogen = min_Nitrogen;

        vector<int> min_Cylinders;

        //run only when the current_oxygen or current_Nitrogen is greater than 0
        while (index >= 0 && (current_Oxygen > 0 || current_Nitrogen > 0))
        {
            if (index == 0)
            {
                min_Cylinders.push_back(index + 1);
                break;
            }
            else
            {
                if (dp[index][current_Oxygen][current_Nitrogen] != dp[index - 1][current_Oxygen][current_Nitrogen])
                {
                    current_Oxygen = current_Oxygen - list[index].oxygen;
                    current_Oxygen = max(current_Oxygen, 0);
                    current_Nitrogen = current_Nitrogen - list[index].nitrogen;
                    current_Nitrogen = max(current_Nitrogen, 0);
                    min_Cylinders.push_back(index + 1);
                }
                index = index - 1;
            }
        }

        // Iterating through the output in reverse order
        for (vector<int>::reverse_iterator it = min_Cylinders.rbegin(); it != min_Cylinders.rend(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}
