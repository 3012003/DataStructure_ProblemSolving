#include <iostream>

using namespace std;

class Node
{
public:
    int item;
    Node*left;
    Node*right;
    Node(int data)
    {
        item = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
 public:
    Node* root;
    BST()
    {
        root = NULL;
    }

    Node* Insert(Node*r, int item)
    {
        if(r == NULL)
        {
            Node* newnode = new Node(item);
            r = newnode;
        }
        else if(item < r->item)
            r->left = Insert(r->left, item);
        else
            r->right =  Insert(r->right, item);
        return r;
    }
    void Insert( int item)
    {
        root = Insert(root, item);
    }

    //Flipping the tree
    Node* flip( Node*newnode )
    {
        if(newnode == NULL)
            return NULL;

        Node*tmp;
        //Swapping the children
        tmp = newnode->left;
        newnode->left = newnode->right;
        newnode->right = tmp;

        newnode->left = flip(newnode->left);
        newnode->right = flip(newnode->right);

        return newnode;
    }



void Inorder(Node*r)
{
    if(r == NULL)
        return ;
    Inorder(r->left);
    cout<<r->item<<" ";
    Inorder(r->right);
}
};



int main()
{

 BST n, m, l, o, p;

 //first test case
 //we sent the root and the function return the mirror
 cout<<"You Entered: 45 15 79 90 10 55 12 20 50"<<endl;
 cout<<"You should get: 10 12 15 20 45 50 55 79 90 for the in order binary tree"<<endl;
  cout<<"You should get: 90 79 55 50 45 20 15 12 10 for the in order Mirror binary tree"<<endl;
  cout<<"------------------------------------------------------------------------------------"<<endl;
 n.Insert(45);
 n.Insert(15);  //45, 15 79, 90, 10, 55, 12, 20, 50
 n.Insert(79);
 n.Insert(90);

 n.Insert(10);
 n.Insert(55);
 n.Insert(12);
 n.Insert(20);
 n.Insert(50);


cout<<"The Original In order tree: ";
 n.Inorder(n.root);
cout<<endl;
cout<<endl;
 n.flip(n.root);
 cout<<"The tree in the Mirror:     ";

 n.Inorder(n.root);


cout<<endl;
cout<<endl;
//second test case
//like the first test case but with different numbers
//to check if there is a problem in taking object and send different values
 m.Insert(8); m.Insert(3); m.Insert(10); m.Insert(1); m.Insert(6); m.Insert(14); m.Insert(4); m.Insert(7); m.Insert(13);

cout<<"You Entered: 8 3 10 1 6 14 4 7 13"<<endl;
cout<<"You should get: 1 3 4 6 7 8 10 13 14  for the in order binary tree"<<endl;
cout<<"You should get: 14 13 10 8 7 6 4 3 1 for the in order Mirror binary tree"<<endl;
cout<<"------------------------------------------------------------------------------------"<<endl;

cout<<"The Original In order tree: ";

 m.Inorder(m.root);

cout<<endl;
cout<<endl;

 m.flip(m.root);
  cout<<"The tree in the Mirror:     ";

 m.Inorder(m.root);

cout<<endl;
cout<<endl;
 //Third test case
 //we sent the left node of the root and the function mirror only the childrens of this node.;
  cout<<"You Entered: 7 2 9 1 5 14 "<<endl;
  cout<<"You should get: 1 2 5 7 9 14 for the in order binary tree"<<endl;
  cout<<"You should get:5 2 1 7 9 14 for the in order Mirror binary tree"<<endl;
  cout<<"------------------------------------------------------------------------------------"<<endl;
 l.Insert(7);
 l.Insert(2);
 l.Insert(9);
 l.Insert(1);

 l.Insert(5);
 l.Insert(14);

cout<<"The Original In order tree: ";
 l.Inorder(l.root);
cout<<endl;
cout<<endl;
 l.flip(l.root->left);
 cout<<"The tree in the Mirror:     ";
 l.Inorder(l.root);


cout<<endl;
cout<<endl;

 //Fourth test case
 //The output will not change as we send node has no child
 //so the mirror should not work
  cout<<"You Entered: 5 2 18 -4 3 "<<endl;
 cout<<"You should get: -4 2 3 5 18 for the in order binary tree"<<endl;
  cout<<"You should get:-4 2 3 5 18 for the in order Mirror binary tree"<<endl;
  cout<<"------------------------------------------------------------------------------------"<<endl;
 o.Insert(5);
 o.Insert(2);
 o.Insert(18);
 o.Insert(-4);
 o.Insert(3);

cout<<"The Original In order tree: ";
 o.Inorder(o.root);
cout<<endl;
cout<<endl;
 o.flip(o.root->right);
cout<<"The tree in the Mirror:     ";

 o.Inorder(o.root);


cout<<endl;
cout<<endl;

//Fifth test case
//we sent root->left->left that has childs and grandsons احفاد
// the function will mirror this node and all of its childs and grandsons
  cout<<"You Entered: 10 8 11 2 14 1 6 13 16 4 3 5 "<<endl;
 cout<<"You should get: 1 2 3 4 5 6 8 10 11 13 14 16  for the in order binary tree"<<endl;
  cout<<"You should get: 6 5 4 3 2 1 8 10 11 13 14 16 for the in order Mirror binary tree"<<endl;
  cout<<"-----------------------------------------------------------------------------------"<<endl;
 p.Insert(10);
 p.Insert(8);
 p.Insert(11);
 p.Insert(2);
 p.Insert(14);
 p.Insert(1);
 p.Insert(6);
 p.Insert(13);
 p.Insert(16);
 p.Insert(4);
 p.Insert(3);
 p.Insert(5);


cout<<"The Original In order tree: ";

 p.Inorder(p.root);
cout<<endl;
cout<<endl;
 p.flip(p.root->left->left);
  cout<<"The tree in the Mirror:     ";
 p.Inorder(p.root);
 return 0;
}
