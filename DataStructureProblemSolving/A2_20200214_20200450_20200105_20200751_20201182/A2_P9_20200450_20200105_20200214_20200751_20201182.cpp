#include <iostream>
using namespace std;
class Node{
public:
int key;
Node* left;
Node* right;
};

Node* createNode(int key)
{
    Node *node= new Node();
   node->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;

}
struct Node * insert(Node *root, int val)
{

    if (root == NULL)
        return createNode(val);


    if (root->key > val)
        root->left = insert(root->left, val);

    else if (root->key <val)
        root->right = insert(root->right, val);


    return root;
}

bool Foldable(Node* root)
{
    if (root == NULL)
        return true;
else
{


    for(int i=0;i<100;i++)
{
    if(root->left==NULL&& root->right==NULL)
    return true;
 else if(root->left!=NULL&& root->right!=NULL && root->left->left==NULL && root->right->right==NULL
           && root->left->right==NULL && root->right->left==NULL)
    return true;
 else if(root->left==NULL|| root->right==NULL)
    return false;
else
    return root->left->left, root->right->right
           && root->left->right, root->right->left;
}
}
}


int main()
{
/*test case 1
         5
        /
       4

*/
Node *ra = NULL;
    ra = insert(ra,5);
    ra = insert(ra,4);
if(Foldable(ra)==true)
    cout<< "tree is foldable" << endl;
    else
        cout<< "tree is not foldable" << endl;
/*test case 2
         9
       /   \
      4     5

*/

Node *rt = NULL;
    rt = insert(rt,9);
    rt = insert(rt,4);
    rt=insert(rt,12);
if(Foldable(rt)==true)
    cout<< "tree is foldable" << endl;
    else
        cout<< "tree is not foldable" << endl;

/*test case 3
        9
*/
Node *rm = NULL;
    rm = insert(rm,9);

if(Foldable(rm)==true)
    cout<< "tree is foldable" << endl;
    else
        cout<< "tree is not foldable" << endl;
/*test case 4
         12
       /   \
      11    14
    /  \     \
   10  9     15
*/
Node *rn = NULL;
    rn = insert(rn,12);
    rn = insert(rn,11);
    rn = insert(rn,14);
    rn = insert(rn,10);
    rn = insert(rn,9);
    rn = insert(rn,15);
if(Foldable(rn)==true)
    cout<< "tree is foldable" << endl;
    else
        cout<< "tree is not foldable" << endl;

/*test case 5
         13
       /     \
      11      15
    /  \     /  \
   9   12   14  16
*/
Node *rs = NULL;
    rs = insert(rs,13);
    rs = insert(rs,11);
    rs = insert(rs,15);
    rs = insert(rs,9);
    rs = insert(rs,12);
    rs = insert(rs,14);
    rs = insert(rs,16);

if(Foldable(rs)==true)
    cout<< "tree is foldable" << endl;
    else
        cout<< "tree is not foldable" << endl;

    return 0;
}