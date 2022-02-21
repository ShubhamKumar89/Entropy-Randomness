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
    cout << "Take a binary string : ";
    cin >> str;
    int n = str.size();

    int no_of_entropies;
    cout << "No. of Entropies u want : ";
    cin >> no_of_entropies;

    if (no_of_entropies > str.size() || no_of_entropies <= 0)
        return -1;

    int window_size = find_window_size(no_of_entropies, str.size());

    cout << "Window_size : " << window_size << endl;

    for (int i = 0; i < no_of_entropies; i++)
    {
        cout << "Entropy " << i + 1 << " : " << entropy(str.substr(i, window_size), 0, window_size) << endl;
    }

    return 0;
}