#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> names (1,"");
    int n = 1;
    for (char c : s)
    {
        if (c != ',') names[n-1].push_back(c);
        else {
            names.push_back("");
            ++n;
        }
    }

    cin >> s;
    int sign;
    vector<int> schmoves (1,0);
    for (char c : s)
    {
        switch (c)
        {
        case 'L':
            sign = -1;
            break;
        case 'R':
            sign = 1;
            break;
        case ',':
            schmoves.push_back(0);
            break;
        default:
            schmoves[schmoves.size() - 1] = 10*schmoves[schmoves.size() - 1] + sign*(c -'0');
        }
    }

    for (int schmove : schmoves)
    {
        swap(names[0], names[(schmove%n+n)%n]);
    }

    cout << names[0] << endl;
}