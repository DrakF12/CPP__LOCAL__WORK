#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
bool func(string &a, string &b)
{
    int len = 0;
    if (a.size() > b.size())
        len = b.size();
    else if (a.size() < b.size())
        len = a.size();
    for (int i = 0; i < len; i++)
    {

    }
}
*/
struct node
{
    string s;
    int val;
};
struct cmp
{
    bool operator()(node &a, node &b)
    {
        if (a.val > b.val)
            return true;
        else if (a.val < b.val)
            return false;
        else
        {
            if (a.s < b.s)
                return true;
            else
                return false;
        }
    }
};
int main()
{
    map<string, int> mp;
    vector<string> dt{"123", "123", "231", "32"};
    for (auto i : dt)
    {
        if (mp.find(i) == mp.end())
            mp[i] = 1;
        else
            mp[i]++;
    }
    vector<node> buff;
    for (auto i : mp)
    {
        node temp;
        temp.s = i.first;
        temp.val = i.second;
        buff.push_back(temp);
    }
    sort(buff.begin(), buff.end(), cmp());
    for (int i = 0; i < buff.size(); i++)
    {
        cout << buff[i].s << " " << buff[i].val << endl;
    }
    getchar();
    return 0;
}