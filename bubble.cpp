#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> &temp);
int main()
{
    vector<vector<int>> data =
        {
            {1, 2, 3, 4, 8, 4, 2, 2, 4, 7, 4, 2, 1, 2, 4, 10},
            {9, 6, 4, 2, 2, 4, 3, 12, 23, 14, 36, 35, 214, 12},
            {2, 3, 1, 4, 24, 2, 8, 5, 4, 33, 5, 6, 2, 11, 46, 3},
            {1, 2, 4, 6, 3, 2, 6, 25, 26, 24, 25, 25, 25}};
    vector<int> temp = data[1];
    for (int i = 0; i < temp.size(); i++)
    //冒泡排序
    {
        for (int j = 0; j < temp.size() - i - 1; j++)
        {
            if (temp[j] < temp[j + 1])
            {
                int a = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = a;
            }
        }
    }
    show(temp);
    getchar();
}

void show(vector<int> &temp)
{
    for (auto i : temp)
    {
        cout << i << ' ';
    }
}
