#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
class Solution {
    TreeNode *root;
public:
     bool isSymmetric(TreeNode* root) {
         if(root==nullptr){
            cout<<"is empty"<<endl;
            return true;
         }
         return checkSym(root->left,root->right);
     }
     bool checkSym(TreeNode *leftt,TreeNode *rightt)
     {
         if(leftt==nullptr&&rightt==nullptr){
            return true;
         }
         else if(leftt!=nullptr&&rightt!=nullptr&&leftt->val==rightt->val){

             return checkSym(leftt->left,rightt->right)&&checkSym(leftt->right,rightt->left);

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
{
    Solution obj;
    vector <int> v;
    cout<<"enter elements of tree if you want stop, enter -5"<<endl;
    cout<<" if you want to enter Null value please enter -1"<<endl;
    int elm=0;
    //to stop enter the number in the vector
    while(elm!=-5){
        cin>>elm;
        if(elm!=-5){
            if(elm==-1)
              v.push_back(NULL);
            else
                v.push_back(elm);
        }
    }
    TreeNode* root = obj.Insert(v, root, 0);
    if(obj.isSymmetric(root))
        cout<<"true the tree is symmetric"<<endl;
    else
        cout<<"false the tree is not Symmetric "<<endl;

    return 0;
}
