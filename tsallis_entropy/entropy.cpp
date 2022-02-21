#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double probability(string str, int count, int window_size, int q)
{
    if (str.empty())
    {
        return pow(((double)count / window_size), q);
    }

    if (str[0] == '1')
        count++;

    return probability(str.substr(1), count, window_size, q);
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

    int no_of_entropy = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + window_size) <= n)
            no_of_entropy++;
    }

    int q = 2;

    ofstream f2;
    f2.open("output.csv");
    f2.clear();

    while (q <= 4)
    {
        double prob_summation = 0;
        for (int i = 0; i < no_of_entropy; i++)
        {
            prob_summation += probability(str.substr(i, window_size), 0, window_size, q);
        }

        f2 << endl
           << endl
           << "tsallis_entropy for q = " << q << " is " << ((1 - prob_summation) / (q - 1));

        q++;
    }

    f2.close();
    return 0;
}