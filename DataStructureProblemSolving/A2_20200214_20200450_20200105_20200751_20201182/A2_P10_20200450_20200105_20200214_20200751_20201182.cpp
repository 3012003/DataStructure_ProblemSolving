#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
};


Node* createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node * insert(Node *root, int val)
{

    if (root == NULL)
        return createNode(val);


    if (root->key > val)
        root->left = insert(root->left, val);

    else if (root->key <val)
        root->right = insert(root->right, val);


    return root;
}

void inorder(struct Node* node,vector<int>& res)
{
    if (node == NULL)
        return;

    inorder(node->left,res);
    res.push_back(node->key);
    inorder(node->right,res);
}
void kSum(struct Node* node,vector<int>& res, int k)

{
int sum=0;
//insertion sort
  for (int i = 1, j; i < res.size(); i++)
       {
       int tmp =  res[i];
		      for (j = i; j > 0 && tmp < res[j-1]; j--)
              {
			   res[j] = res[j-1];
               res[j] = tmp;
               }
       }

for(int i=0;i<k;i++)
{
    sum+=res[i];
}
cout<< sum;
}



int main()
{

    /*  TEST CASE 1
          15
        /    \
       12     18
     /   \
    10    13
         /   \
        11    14
          */
    Node *root = NULL;
    vector<int> res;
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 11);
    root = insert(root, 14);
inorder(root,res);
kSum(root,res,3);
cout<<endl;

 /*  TEST CASE 2
         10
        /  \
       9   11
      /
     8
          */
    Node *n = NULL;
    vector<int> result;
    n = insert(n, 10);
    n = insert(n, 9);
    n = insert(n, 11);
    n = insert(n, 8);

inorder(n,result);
kSum(n,result,2);
cout<<endl;

    /*  TEST CASE 3
          52
        /    \
       50     54
     /   \      \
    49    51     55

          */
    Node *r = NULL;
    vector<int> vec;
    r = insert(r, 52);
    r = insert(r, 50);
    r = insert(r, 54);
    r = insert(r, 49);
    r = insert(r, 51);
    r = insert(r, 55);
inorder(r,vec);
kSum(r,vec,4);
cout<<endl;

    /*  TEST CASE 4
          14
        /    \
       11     15

          */
    Node *s = NULL;
    vector<int> vecs;
    s = insert(s, 14);
    s = insert(s, 11);
    s = insert(s, 15);

inorder(s,vecs);
kSum(s,vecs,2);
cout<<endl;

    /*  TEST CASE 5
          16
        /    \
       12     22
     /   \
    10    14
          /
         13
          */
    Node *m = NULL;
    vector<int> vect;
    m = insert(m, 16);
    m = insert(m, 12);
    m = insert(m, 22);
    m = insert(m, 10);
    m = insert(m, 14);
    m = insert(m, 13);
inorder(m,vect);
kSum(m,vect,5);
cout<<endl;
    return 0;
}
