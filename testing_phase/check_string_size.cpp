#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f1;
    f1.open("check_string_size_input.csv");
    string str;
    f1 >> str;

    int n = str.length();
    cout << n << endl;
}