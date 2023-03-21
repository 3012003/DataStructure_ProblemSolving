#include <iostream>
using namespace std;

template<class T>
class BSTNode
{
public:
    T item;
    BSTNode *right;
    BSTNode *left;

    BSTNode()
    {
        right = NULL;
        left = NULL;
    }
};

template <class T>
class BSTFCI
{
public:
    BSTNode<T> *root;
public:
    BSTFCI()
    {
        root = NULL;
    }

    BSTNode<T>* Insert(BSTNode<T>* R, T value)
    {
        if(R == NULL)
        {
            BSTNode<T>* newnode = new BSTNode<T>();
            newnode->item = value;
            R = newnode;

        }
        else if(value < R->item)
            R->left = Insert(R->left, value);
        else if(value > R->item)
            R->right = Insert(R->right, value);

        return R;
    }

    void Insert(T value)
    {
        root = Insert(root, value);
    }

    //TO print the tree in order left->root->right
    void PrintInorder(BSTNode<T> *r)
    {
        if(r == NULL)
            return;

        PrintInorder(r->left);
        cout<<r->item<<" ";
        PrintInorder(r->right);
    }
    int calcHight(BSTNode<T> *root)
    {
        int hight;
        if(root==nullptr)
            return 0;
        //check the max and calculate the hight
        if(calcHight(root->right) >= calcHight(root->left))
            hight=calcHight(root->right)+1;
        else if(calcHight(root->right) <= calcHight(root->left))
            hight=calcHight(root->left)+1;
        return hight;
    }
    bool isBalanced(BSTNode<T> *root)
    {
        int leftH,rightH;

        if(root==nullptr){
            return true;
        }
        else{
            leftH=calcHight(root->left);
            rightH=calcHight(root->right);
        }

        if((leftH-rightH==1||leftH-rightH==-1||leftH-rightH==0)&&isBalanced(root->left)&&isBalanced(root->right))
            return true;


        return false;


    }

    bool compare( BSTNode<T>  *T1 , BSTNode<T>  *T2 )
    {
        if((T1 == nullptr) && (T2 == nullptr)) return true;
        else if(T1 == nullptr || T2 == nullptr)return false;

        if ((T1->item == T2->item) && (compare(T1->left, T2->left)) && (compare(T1->right, T2->right)) ) return true;
        else return false;



    }

    bool ISubtree(BSTNode<T>  *T1 , BSTNode<T>  *T2 )
    {
        if(T2 == nullptr) return true;
        if(T1 == nullptr) return false;
        if(compare(T1 , T2)) return true;
        return (ISubtree(T1->left, T2) || ISubtree(T1->right, T2));
    }

    bool isSubtree(BSTFCI <T> &Tree, BSTFCI<T> &Sub) {
        return (ISubtree(Tree.root, Sub.root));
    }

    void FindRange(BSTNode<T>* root, int lower, int Upper) {
        if (root == 0) return;
        if (lower < root->item) FindRange(root->left, lower, Upper);
        if (lower <= root->item && Upper >= root->item) cout << root->item << endl;
        if (Upper > root->item) FindRange(root->right, lower, Upper);


    }

    void PrintRange(int lower, int Upper) {
        FindRange(root, lower, Upper);
    }



};





int main()
{
    //45, 15 79, 90, 10, 55, 12, 20, 50
    BSTFCI<int> obj;
    obj.Insert(45);  obj.Insert(15);  obj.Insert(79);  obj.Insert(90);
    obj.Insert(10);  obj.Insert(55);  obj.Insert(12);  obj.Insert(20); obj.Insert(50);

    cout<<"The in order traverse of the binary tree is: "<<endl;
    obj.PrintInorder(obj.root);
    cout<<endl;
//----------------------------------------------------------------------------------------
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    BSTFCI<int> test1;
    test1.Insert(30);test1.Insert(40);test1.Insert(10);test1.Insert(50);test1.Insert(20);test1.Insert(5);test1.Insert(35);
    cout<<"test case 1: ";
    if(test1.isBalanced(test1.root))
        cout<<"balanced"<<endl;
    else
        cout<<"non balanced"<<endl;

    BSTFCI<int> test2;
    test2.Insert(10);test2.Insert(30);test2.Insert(20);
    cout<<"test case 2: ";
    if(test2.isBalanced(test2.root))
        cout<<"balanced"<<endl;
    else
        cout<<"non balanced"<<endl;
    BSTFCI<int> test3;
    test3.Insert(5);test3.Insert(7);test3.Insert(12);test3.Insert(15);test3.Insert(25);
    test3.Insert(27);test3.Insert(42);test3.Insert(47); test3.Insert(50);
    cout<<"test case 3: ";
    if(test3.isBalanced(test3.root))
        cout<<"balanced"<<endl;
    else
        cout<<"non balanced"<<endl;

    BSTFCI<int> test4;
    test4.Insert(50); test4.Insert(30);test4.Insert(20);test4.Insert(40);
    test4.Insert(70);test4.Insert(60);test4.Insert(80);
    cout<<"test case 4: ";
    if(test4.isBalanced(test4.root))
        cout<<"balanced"<<endl;
    else
        cout<<"non balanced"<<endl;
    BSTFCI<int> test5;
    test5.Insert(7);test5.Insert(20);test5.Insert(5);test5.Insert(15);test5.Insert(10);
    test5.Insert(4);test5.Insert(33);test5.Insert(2);test5.Insert(25);test5.Insert(6);
    cout<<"test case 5: ";
    if(test5.isBalanced(test5.root))
        cout<<"balanced"<<endl;
    else
        cout<<"non balanced"<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;

/////////////////////////////////////////////
// is subtree

    BSTFCI<int> t1;

    t1.Insert(5);t1.Insert(3);t1.Insert(2);t1.Insert(4);t1.Insert(1);t1.Insert(7);t1.Insert(9);t1.Insert(8);t1.Insert(10);
    BSTFCI<int> t2;
    t2.Insert(9);t2.Insert(8);t2.Insert(10);
    BSTFCI<int> t3;
    t3.Insert(3); t3.Insert(2); t3.Insert(1); t3.Insert(4);
    BSTFCI<int> t4;
    t4.Insert(3); t4.Insert(2); t4.Insert(1); t4.Insert(5);
    BSTFCI<int> t5;
    t5.Insert(7);t5.Insert(9);t5.Insert(8);
    BSTFCI<int> t6;
    t6.Insert(7);t6.Insert(9);t6.Insert(8);t6.Insert(10);
    cout<<"test case1: ";
    if (t2.isSubtree(t1, t2)) cout << "True\n";
    else cout << "false\n";
    cout<<"test case2: ";
    if (t2.isSubtree(t1, t2)) cout << "True\n";
    else cout << "false\n";
    cout<<"test case 3: ";
    if (t2.isSubtree(t1, t4)) cout << "True\n";
    else cout << "false\n";
    cout<<"test case 4: ";
    if (t2.isSubtree(t1, t5)) cout << "True\n";
    else cout << "false\n";
    cout<<"test case 5: ";
    if (t2.isSubtree(t1, t6)) cout << "True\n";
    else cout << "false\n";
    ////////////////////////////////////////////
    /////// Range
    cout<<"test case1: ";
    t1.PrintRange(3,6);
    cout<<"test case2: ";
    t1.PrintRange(8,15);
    cout<<"test case3: ";
    t1.PrintRange(6,6);
    cout<<"test case4: ";
    t1.PrintRange(8,10);
    cout<<"test case5: ";
    t1.PrintRange(4,7);
    return 0;
}
