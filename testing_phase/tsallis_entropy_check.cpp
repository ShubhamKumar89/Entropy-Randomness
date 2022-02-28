#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double probability_sum(string str, int count, int window_size, int q)
{
    if (str.empty())
    {
        double probSum_0_and_1 = pow(((double)count / window_size), q) + pow(((double)(window_size - count) / window_size), q);
        return probSum_0_and_1;
    }

    if (str[0] == '1')
        count++;

    return probability_sum(str.substr(1), count, window_size, q);
}

int main()
{
    // ifstream f1;
    // f1.open("input.csv");
    // string str;
    // f1 >> str;

    string str = "101101101";

    int n = str.size();
    int window_size = 5;
    // f1 >> window_size;

    // f1.close();

    int no_of_entropy = n - (window_size - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     if ((i + window_size) <= n)
    //         no_of_entropy++;
    // }

    int q = 2;

    // ofstream f2;
    // f2.open("output.csv");
    // f2.clear();

    // while (q <= 4)
    // {
    cout << "window Size : " << window_size << endl;
    for (int i = 0; i < no_of_entropy; i++)
    {
        cout << "tsallis_entropy of window " << i + 1 << " for q = " << q << " is " << ((1 - probability_sum(str.substr(i, window_size), 0, window_size, q)) / (q - 1)) << endl;
    }
    //     q++;
    // }

    // f2.close();
    return 0;
}