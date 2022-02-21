#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

double entropy(string str, double count, int window_size)
{
    if (str.length() == 0)
        return abs(-((count / window_size) * log2f(count / window_size)));

    if (str[0] == '1')
        count++;

    return entropy(str.substr(1), count, window_size);
}

int main()
{
    ifstream f1;
    f1.open("input.csv");
    string str;

    int file_size = 0;
    while (f1.good())
    {
        // str = "";
        f1 >> str;
        file_size++;
    }

    f1.close();

    str.clear();
    f1.open("input.csv");

    while (file_size > 8)
    {
        string s;
        f1 >> s;
        str += s;
        file_size--;
    }

    int n = str.size();

    ofstream f2;
    f2.open("output.csv");
    f2.clear();

    while (!f1.eof())
    {
        int window_size;
        f1 >> window_size;

        f2 << "Window Size : " << window_size << endl;

        int count_entropy = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + window_size > n)
                break;

            count_entropy++;
        }

        for (int i = 0; i < count_entropy; i++)
        {
            f2 << "Entropy " << i + 1 << " : " << entropy(str.substr(i, window_size), 0, window_size) << endl;
        }
        f2 << endl
           << endl;
    }

    f1.close();
    f2.close();

    return 0;
}