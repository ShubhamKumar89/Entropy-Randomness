#include <bits/stdc++.h>
using namespace std;

double entropy(string str, double count, int window_size)
{
    if (str.length() == 0)
        return abs(-((count / window_size) * log2f(count / window_size))); // use log base 2

    if (str[0] == '1')
        count++;

    return entropy(str.substr(1), count, window_size);
}

int main()
{
    string str;
    cout << "Take a binary string : ";
    cin >> str;
    int n = str.size();

    int window_size;
    cout << "What will be the size of window : ";
    cin >> window_size;

    int count_entropy = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + window_size > n)
            break;

        count_entropy++;
    }

    for (int i = 0; i < count_entropy; i++)
    {
        cout << "Entropy " << i + 1 << " : " << entropy(str.substr(i, window_size), 0, window_size) << endl;
    }

    return 0;
}