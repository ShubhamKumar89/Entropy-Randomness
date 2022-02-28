#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double probability_sum(string str, double count, int window_size, int q)
{
    if (str.empty())
    {
        double probSum_0_and_1 = pow((count / window_size), q) + pow(((window_size - count) / window_size), q);
        return probSum_0_and_1;
    }

    if (str[0] == '1')
        count++;

    return probability_sum(str.substr(1), count, window_size, q);
}

int main()
{
    ifstream f1;
    f1.open("input.csv");
    string str;
    f1 >> str;

    int n = str.size();
    int window_size;
    f1 >> window_size;

    f1.close();

    int no_of_entropy = n - (window_size - 1);

    int q = 2;

    ofstream f2;
    f2.open("output.csv");
    f2.clear();
    f2 << "Window Size : " << window_size << endl;

    while (q <= 4)
    {
        f2 << "For q = " << q << " : " << endl;
        for (int i = 0; i < no_of_entropy; i++)
        {
            f2 << "Entropy " << i + 1 << " : " << (1 - probability_sum(str.substr(i, window_size), 0, window_size, q) / (q - 1)) << endl;
        }
        f2 << endl;
        q++;
    }

    f2.close();
    return 0;
}