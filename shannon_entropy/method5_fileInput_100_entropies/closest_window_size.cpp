#include <bits/stdc++.h>
using namespace std;

double entropy(string str, double count, int window_size)
{
    if (str.length() == 0)
        return abs(-((count / window_size) * log2f(count / window_size)));

    if (str[0] == '1')
        count++;

    return entropy(str.substr(1), count, window_size);
}

int find_window_size(int no_of_entropies, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (no_of_entropies == (n - (i - 1)))
            break;
    }
    return i;
}

int main()
{
    string str;
    ifstream f1;
    f1.open("input.csv");
    f1 >> str;
    int n = str.size();

    int no_of_entropies;
    f1 >> no_of_entropies;
    f1.close();

    if (no_of_entropies > n || no_of_entropies <= 0)
        return -1;

    int window_size = find_window_size(no_of_entropies, n);

    ofstream f2;
    f2.open("output.csv");

    f2 << "Window_size : " << window_size << endl;

    for (int i = 0; i < no_of_entropies; i++)
    {
        f2 << "Entropy " << i + 1 << " : " << entropy(str.substr(i, window_size), 0, window_size) << endl;
    }

    return 0;
}