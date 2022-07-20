#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<int> get;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] >= '1' && s[i] <= '9')
            get.push_back(s[i] - '0');
        else if (s[i] == 'n')
            get.push_back(0);
    }
    map<string, int> mp;
    for (int i = 1; i < get.size(); i++)
    {
        string s;
        queue<int> lq;
        lq.push(i);
        while (lq.empty() == 0)
        {
            int t = lq.front();
            if (t < get.size())
                s += to_string(get[t]);
            lq.pop();
            if (get[t] == 0)
                continue;
            if (2 * t + 1 < get.size())
                lq.push(2 * t + 1);
            if (2 * t + 2 < get.size())
                lq.push(2 * t + 2);
        }
        int end = s.size() - 1;
        while (s[end] == '0')
        {
            s.erase(end);
            end--;
        }
        // cout << s << endl;
        mp[s]++;
    }
    int ans = 0;
    string out;
    for (auto i : mp)
    {
        if (i.second > 1)
        {
            if (ans < (i.first).size())
            {
                ans = (i.first).size();
                out = i.first;
            }
        }
    }
    int layer = 0;
    int need = 0;
    if (ans == 1)
    {
        layer = 1;
        need = 1;
    }
    else if (ans >= 2 && ans <= 3)
    {
        layer = 2;
        need = 3;
    }
    else if (ans >= 4 && ans <= 7)
    {
        layer = 3;
        need = 7;
    }
    else
    {
        layer = 4;
        need = 15;
    }
    string key;
    key += "[";
    for (int i = 0; i < out.size() || i < need; i++)
    {
        if (i >= out.size())
        {
            key += "null,";
            continue;
        }
        if (i < out.size() && out[i] > '0')
            key += to_string(out[i] - '0') + ",";
        else
            key += "null,";
    }
    key.erase(key.size() - 1);
    key += "]";
    cout << key << " " << layer << endl;
    getchar();
    getchar();
}