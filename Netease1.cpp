#include <iostream>
#include <map>
#include <vector>

using namespace std;

// struct node
// {
//     int val;
//     node* left;
//     node* right;
// };

// node* create(const string& post,const string& mid,int postL,int postR,int midL,int midR)
// {
//     if(postL > postR)
//         return nullptr;
//     node* root = new node;
//     root->val = post[postR];
//     int index = 0;
//     for(index = midL;index <= midR;index++)
//     {
//         if(mid[index] == post[postR])
//             break;
//     }
//     int numLeft;
//     numLeft = index - midL;
//     root->left = create(post,mid,postL,postL+numLeft-1,midL,index-1);
//     root->right = create(post,mid,postL+numLeft, postR-1,index+1,midR);
//     return root;
// }

// int sub(node* root)
// {
//     int left = 0;
//     int right = 0;
//     if(root == nullptr)
//         return 0;
//     else
//     {
//         if(root->left != nullptr)
//         {
//             left = 1 + sub(root->left);
//         }
//         if(root->right != nullptr)
//         {
//             right = 1 + sub(root->right);
//         }
//         mpL[root] = left;
//         mpR[root] = right;
//     }
//     return max(left,right);
// }

int sub(const string &post, const string &mid, int postL, int postR, int midL, int midR, map<int, int> &mpL, map<int, int> &mpR)
{
    if (postL > postR)
        return 0;
    int root = post[postR];
    int index = 0;
    for (index = midL; index <= midR; index++)
    {
        if (mid[index] == post[postR])
            break;
    }
    int numLeft = index - midL;
    int left = 1 + sub(post, mid, postL, postL + numLeft - 1, midL, index - 1, mpL, mpR);
    int right = 1 + sub(post, mid, postL + numLeft, postR - 1, index + 1, midR, mpL, mpR);
    mpL[root] = left;
    mpR[root] = right;
    return max(left, right);
}

int main()
{
    map<int, int> mpL;
    map<int, int> mpR;
    int n = 0;
    cin >> n;
    string inorder;
    string postorder;
    cin >> inorder;
    cin >> postorder;
    sub(postorder, inorder, 0, n - 1, 0, n - 1, mpL, mpR);
    int ans = 0;
    for (auto i : mpL)
    {
        auto p = i.first;
        int right = mpR[p];
        ans = max(ans, 1 + right + i.second);
    }
    cout << ans;
    return 0;
}