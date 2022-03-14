#include<bits/stdc++.h>
using namespace std;

#define good f1.good()
#define loop(i,a,b) for(int i = a; i < b; i++)

double find_entropy(int prob, int window_size)
{
    double p = (double)prob / window_size;
    double shannon = -(p * log2l(p));
    return shannon;
}

int main()
{
    ifstream f1;
    f1.open("random_numbers_binary_edition.csv");

    vector<string> vec;
    while (good)
    {
        string s;
        f1 >> s;
        vec.push_back(s);
    }
    f1.close();

    int window_size;
    cout << "Window Size : ";
    cin >> window_size;

    ofstream f2;
    f2.open("output.csv");
    f2 << "Window size : " << window_size << endl << endl;

    int n = vec.size();
    int no_of_entropies = n - (window_size - 1);

    loop(i, 0, no_of_entropies) {

        unordered_map<string, int> mp;

        // loop(j, i, window_size + i) {
        //     mp[vec[j]]++;
        // }

        loop(j, i, window_size + i)
        {
            if (mp.find(vec[j]) != mp.end())
            {
                mp[vec[j]]++;
                continue;
            }

            mp[vec[j]] = 1;
        }

        static int l = 1;
        f2 << "For window " << l << " : " << endl;

        // for (auto k : mp)
        // {
        //     f2 << "frequency of " << k.first << " is " << k.second << endl;
        // }

        for (auto k : mp)
        {
            f2 << "Entropy of " << k.first << " is " << find_entropy(k.second, window_size) << endl;
        }

        f2 << endl << endl;
        l++;
    }


    // while (f1.good())
    // {
    //     string str;
    //     f1 >> str;
        // if (mp.find(str) != mp.end())
        // {
        //     mp[str]++;
        //     continue;
        // }

        // mp[str] = 1;
    // }


    return 0;
}