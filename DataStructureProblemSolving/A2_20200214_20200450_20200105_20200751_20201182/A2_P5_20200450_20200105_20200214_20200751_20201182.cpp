#include <iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
class Solution
{
public:
    bool isSameTree(TreeNode *p,TreeNode *q)
    {
        if(p==nullptr&&q==nullptr){
            return true;
        }
        if(p!=nullptr&&q!=nullptr&&p->val==q->val){

             return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
       }
       return false;
    }
    TreeNode* Insert(vector<int> v, TreeNode* root,
                       int i)
      {
         if (i < v.size())
         {
              TreeNode* temp = new TreeNode(v[i]);
              root = temp;

             root->left = Insert(v,
                    root->left, 2 * i + 1);
             root->right = Insert(v,
                  root->right, 2 * i + 2);
         }
         return root;
      }


};
int main()
{   Solution obj;
    vector <int> v1;
    cout<<"enter elements of the first tree if you want stop, enter -5"<<endl;
    cout<<" if you want to enter Null value please enter -1"<<endl;
    int elm1=0;
    //to stop enter the number in the vector
    while(elm1!=-5){
        cin>>elm1;
        if(elm1!=-5){
            if(elm1==-1)
              v1.push_back(NULL);
            else
                v1.push_back(elm1);
        }
    }

    TreeNode* root1 = obj.Insert(v1, root1, 0);
    vector <int> v2;
    cout<<"enter elements of the second tree if you want stop, enter -5"<<endl;
    cout<<" if you want to enter Null value please enter -1"<<endl;
    int elm2=0;
    //to stop enter the number in the vector
    while(elm2!=-5){
        cin>>elm2;
        if(elm2!=-5){
            if(elm2==-1)
              v2.push_back(NULL);
            else
                v2.push_back(elm2);
        }
    }
    TreeNode* root2 = obj.Insert(v2, root2, 0);
    if(obj.isSameTree(root1,root2))
        cout<<" True the trees are the same"<<endl;
    else
        cout<<"False the trees are different"<<endl;
    return 0;
}
