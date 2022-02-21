#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> graph;
    graph.push_back(0.25);
    graph.push_back(0.25);
    graph.push_back(0.70);
    graph.push_back(0.25);
    graph.push_back(0.50);
    graph.push_back(0.70);

    // for (auto i : graph)
    //     cout << i << "   ";
    // cout << endl;

    sort(graph.begin(), graph.end());

    // for (auto i : graph)
    //     cout << i << "   ";
    // cout << endl;

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
        cout << i.first << " ";
        for (int j = 0; j < i.second; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}