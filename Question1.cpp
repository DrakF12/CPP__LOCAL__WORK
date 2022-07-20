#include <iostream>
using namespace std;

#include <algorithm>
#include <map>
#include <vector>

int main()
{
    string s;
    getline(cin, s);
    string N;
    getline(cin, N);
    int numN = stoi(N);
    map<int, int> mp;
    map<int, int> lp;
    vector<string> get;
    vector<int> data;
    for (int i = 0; i < numN; i++)
    {
        string temp;
        cin >> temp;
        get.push_back(temp);
    }
    int p = 0;
    while (p < s.size())
    {
        string tag = s.substr(p, 2);
        int numtag = stoi(tag, 0, 16);
        //cout << numtag << ":";
        p = p + 2;
        string len = s.substr(p, 2);
        p = p + 2;
        int numlen = stoi(len, 0, 16);
        //cout << numlen;
        lp[numtag] = numlen;
        mp[numtag] = p / 2;
        p = p + 2 * numlen;
        cout << endl;
    }
    for (int i = 0; i < get.size(); i++)
    {
        int num = stoi(get[i]);
        cout << lp[num] << " " << mp[num] << "  " << endl;
    }
    return 0;
}