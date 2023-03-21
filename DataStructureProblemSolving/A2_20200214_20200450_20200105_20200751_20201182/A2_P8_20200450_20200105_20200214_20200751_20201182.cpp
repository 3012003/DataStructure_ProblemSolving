#//This program to get the post order traverse using in order and pre order.

#include <iostream>
using namespace std;

class Node
{
public:
    int item;
    Node*left;
    Node*right;
    Node(char data)
    {
        item = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{

 public:
     Node*root;
     BST()
     {
        root = NULL;
     }
     //To search char in the string and return its position
     //this fun. help me to divide the tree into two sub trees
    int Search(string inOrder ,int strt, int endd, char curr)
    {
        for(int i =strt ; i<=endd; i++)
        {
            if(inOrder[i] == curr)
                return i;

        }
        return -1;
    }

// fun to get the binary tree from the in order and pre order
  Node* printPostOrder(string preOrder, string inOrder, int strt, int endd)
  {

      if(strt > endd)
      {
          return NULL;
      }

      //curr store the chars of the pre order to search in the in order
      static int i = 0;
      char curr = preOrder[i];
      i++;

    Node*node = new Node(curr);
      if(strt == endd)
      {
          return node;
      }
       //position of the  (node in the pre order tree) in (the in order tree).
      int pos = Search(inOrder, strt, endd, curr);

      //we get to position to divide the string into two strings (left and right)
      node->left = printPostOrder(preOrder, inOrder,strt, pos-1);
      node->right = printPostOrder(preOrder, inOrder, pos+1, endd);

    if(i == inOrder.size())
         i = 0;
      return node;

  }
//fun to print the postOrder
void printPostOrder(string inOrder, string postOrder)
{
    root = printPostOrder( inOrder,  postOrder, 0, inOrder.size()-1);

    //print postOrder by calling its function
    PostOrder(root);

}
     // The main function to print the post order tree
     void PostOrder(Node *root)
      {
        if(root == NULL)
            return;

        PostOrder(root->left);
        PostOrder(root->right);
        cout<< static_cast<char>(root->item) <<" ";
     }
};



int main()
{

 cout<<endl;
 cout<<"The first test case"<<endl;
 cout<<"------------------------------"<<endl;

//The first test case from the Assignment file.
 string pre_one = "ABFGC";//the first pre order
 string in_one = "FBGAC";//the first in order
 BST obj1;



 cout<<"The Preorder of the tree is: "<<pre_one<<endl;
 cout<<"The Inorder of the tree is: "<<in_one<<endl;
 cout<<"The postOrder of new tree should be: F G B C A"<<endl;
 obj1.printPostOrder(pre_one ,in_one);
 cout<<endl;
 cout<<endl;

 cout<<"The second test case"<<endl;
 cout<<"------------------------------"<<endl;
 //The second test case from the Assignment file.
 string pre_two = "ABDHIECFGJ";//the second pre order
 string in_two = "HDIBEAFCJG";//the second in order

 BST obj2;
 cout<<"The Preorder of the tree is: "<<pre_two<<endl;
 cout<<"The Inorder of the tree is: "<<in_two<<endl;
 cout<<"The postOrder of new tree should be: H I D E B F J G C A"<<endl;
 obj2.printPostOrder(pre_two, in_two);


  cout<<endl;
  cout<<endl;
 //The third test case.
 cout<<"The third test case"<<endl;
 cout<<"------------------------------"<<endl;
 string pre_three = "ABDCEGFHI";//the third pre order
 string in_three = "DBAEGCHFI";//the third in order


  cout<<"The Preorder of the tree is: "<<pre_three<<endl;
 cout<<"The Inorder of the tree is: "<<in_three<<endl;
 cout<<"The postOrder of new tree should be: D B G E H I F C A"<<endl;
BST obj3;
 obj3.printPostOrder(pre_three, in_three);

 cout<<endl;
 cout<<endl;
 //The fourth test case.
 cout<<"The fourth test case"<<endl;
 cout<<"------------------------------"<<endl;
 string pre_four = "HMCYBASOLK";//the fourth pre order
 string in_four = "YCBMSAHLOK";//the fourth in order


  cout<<"The Preorder of the tree is: "<<pre_four<<endl;
 cout<<"The Inorder of the tree is: "<<in_four<<endl;
 cout<<"The postOrder of new tree should be: Y B C S A M L K O H"<<endl;
 BST obj4;
 obj4.printPostOrder(pre_four, in_four);

 cout<<endl;
 cout<<endl;
 //The fifth test case from the Assignment file.
 cout<<"The fifth test case"<<endl;
 cout<<"------------------------------"<<endl;
 string pre_five = "GECDAHKFM";//the fifth pre order
 string in_five = "CEADGHFKM";//the fifth in order


  cout<<"The Preorder of the tree is: "<<pre_five<<endl;
 cout<<"The Inorder of the tree is: "<<in_five<<endl;
 cout<<"The postOrder of new tree should be: C A D E F M K H G"<<endl;
 BST obj5;
 obj5.printPostOrder(pre_five, in_five);

 return 0;
}
