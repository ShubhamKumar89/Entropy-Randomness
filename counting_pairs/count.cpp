#include <bits/stdc++.h>
using namespace std;

int count_single(string str, string key, int count)
{
    if (str.empty())
        return count;

    if (str[0] == key[0])
        count++;

    return count_single(str.substr(1), key, count);
}

int count_double(string str, string key, int count)
{
    if (str.size() == 0 || str.size() == 1)
        return count;

    if (str[0] == key[0] && str[1] == key[1])
        count++;

    return count_double(str.substr(2), key, count);
}

int count_triple(string str, string key, int count)
{
    if (str.size() == 0 || str.size() == 1 || str.size() == 2)
        return count;

    if (str[0] == key[0] && str[1] == key[1] && str[2] == key[2])
        count++;

    return count_triple(str.substr(3), key, count);
}

int main()
{
    string str;
    cout << "Take a Binary String : ";
    cin >> str;

    cout << "Press (1)  to get the number of   '0' \n";
    cout << "Press (2)  to get the number of   '1' \n";
    cout << "Press (3)  to get the number of  '00' \n";
    cout << "Press (4)  to get the number of  '01' \n";
    cout << "Press (5)  to get the number of  '10' \n";
    cout << "Press (6)  to get the number of  '11' \n";
    cout << "Press (7)  to get the number of '000' \n";
    cout << "Press (8)  to get the number of '001' \n";
    cout << "Press (9)  to get the number of '010' \n";
    cout << "Press (10) to get the number of '011' \n";
    cout << "Press (11) to get the number of '100' \n";
    cout << "Press (12) to get the number of '101' \n";
    cout << "Press (13) to get the number of '110' \n";
    cout << "Press (14) to get the number of '111' \n";
    cout << "Press (15) to exit. \n";
    int key;
    do
    {
        cout << "\nPress the key : ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << count_single(str, string("0"), 0) << endl;
            break;

        case 2:
            cout << count_single(str, string("1"), 0) << endl;
            break;

        case 3:
            cout << count_double(str, string("00"), 0) << endl;
            break;

        case 4:
            cout << count_double(str, string("01"), 0) << endl;
            break;

        case 5:
            cout << count_double(str, string("10"), 0) << endl;
            break;

        case 6:
            cout << count_double(str, string("11"), 0) << endl;
            break;

        case 7:
            cout << count_triple(str, string("000"), 0) << endl;
            break;

        case 8:
            cout << count_triple(str, string("001"), 0) << endl;
            break;

        case 9:
            cout << count_triple(str, string("010"), 0) << endl;
            break;

        case 10:
            cout << count_triple(str, string("011"), 0) << endl;
            break;

        case 11:
            cout << count_triple(str, string("100"), 0) << endl;
            break;

        case 12:
            cout << count_triple(str, string("101"), 0) << endl;
            break;

        case 13:
            cout << count_triple(str, string("110"), 0) << endl;
            break;

        case 14:
            cout << count_triple(str, string("111"), 0) << endl;
            break;

        case 15:
            cout << "Exit\n\n\n";
            return 0;

        default:
            cout << "Not valid.\n";
            break;
        }
    } while (1);

    return 0;
}