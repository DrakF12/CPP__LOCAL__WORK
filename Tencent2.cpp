#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <iostream>
using namespace std;

//字典树
class Trie
{
public:
    Trie()
    {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }

    bool insert(const string &word)
    {
        Trie *node = this;
        for (const auto &ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string &word)
    {
        Trie *node = this;
        for (const auto &ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        if (node->isEnd)
            return true;
        return false;
    }

    bool erase(const string &word)
    {
        Trie *node = this;
        for (const auto &ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        if (node->isEnd != 1) //没有该元素，直接报错
            return false;
        else
            node->isEnd = 0;
        return true;
    }

private:
    vector<Trie *> children;
    bool isEnd;
};

//自定义节点类型
struct node
{
    int a;
    int b;
};
//自定义比较函数
struct cmp1
{
    bool operator()(const node &one, const node &two)
    {
        return one.a < two.a;
    }
};
struct cmp2
{
    bool operator()(const node &one, const node &two)
    {
        return one.a > two.a;
    }
};
long long str2longlong(string s) //字符串转int、long型数据
{
    long long res;
    for (int i = 0; i < s.size(); i++)
    {
        if (9223372036854775807 - res < 10)
            return -1;
        res = 10 * res + (s[i] - '0');
    }
    return res;
}

priority_queue<node, vector<node>, cmp1> max_heap; // top为最大值
priority_queue<node, vector<node>, cmp2> min_heap; // top为最小值

int Line2int(string get, vector<int> &tempdata) //将每一行的数据转换为int型的数组
{
    int temp = 0;
    int f = 0;
    for (int i = 0; i < get.length(); i++)
    {
        if (get[i] != ' ')
        {
            temp = temp * 10 + get[i] - '0';
            f = 1;
        }
        else if (get[i] == ' ' && f == 0)
            continue;
        else
        {
            tempdata.push_back(temp);
            f = 0;
            temp = 0;
        }
    }
    //若该行以' '结尾则可以删除下一行数据
    if (get.back() != ' ')
        tempdata.push_back(temp);
    return 1;
}

int main()
{
    /*
    vector<int> a;
    list<int> b;
    deque<int> c;
    queue<int> d;
    map<int, int> mp;
    set<int> s;
    cout << a.size() << endl;
    cout << b.size() << endl;
    cout << c.size() << endl;
    cout << d.size() << endl;
    cout << mp.size() << endl;
    cout << s.size() << endl;
    */
    /*获取输入信息*/
    // vector<int> tempdata;
    // int temp = 0;
    // string get;
    // getline(cin, get);
    // Line2int(get, tempdata);
    // for (int i = 0; i < tempdata.size(); i++)
    // {
    //     cout << tempdata[i] << "    ";
    // }
    // getchar();
    // return 0;
}
