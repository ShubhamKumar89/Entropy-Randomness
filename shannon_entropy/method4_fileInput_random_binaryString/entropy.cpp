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
    ifstream f1;
    f1.open("input.csv");
    string str = "";

    f1 >> str;

    int n = str.size();
    int window_size;
    f1 >> window_size;

    f1.close();

    int count_entropy = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + window_size > n)
            break;

        count_entropy++;
    }

    ofstream f2;
    f2.open("output.csv");
    f2.clear();

    vector<double> graph;
    for (int i = 0; i < count_entropy; i++)
    {
        // f2 << "Entropy " << i + 1 << " : " << entropy(str.substr(i, window_size), 0, window_size) << endl;
        graph.push_back(entropy(str.substr(i, window_size), 0, window_size));
    }

    sort(graph.begin(), graph.end());

    vector<pair<double, int>> histogram;
    for (int i = 0; i < graph.size(); i++)
    {
        int k = 0;

        if ((i - 1) < 0 || graph[i] != graph[i - 1])
        {
            histogram.push_back(make_pair(graph[i], k));

            for (auto j : graph)
            {
                if (j == graph[i])
                {
                    k++;
                    histogram.back().second = k;
                }
            }
        }
    }

    for (auto i : histogram)
    {
        f2 << i.first << ",";
        f2 << i.second << endl;
    }

    f2.close();

    return 0;
}