#include <iostream>
using namespace std;

struct TreeNode
{
    char value;
    TreeNode *right , *left;
};

struct LLNode{
    TreeNode *data;
    LLNode *next;
};
class stack{
private:
    LLNode *first;
public:
    stack(): first{nullptr}{}
    void push(TreeNode *x);
    TreeNode* pop();
    TreeNode *GetTop();
    void display();

};
void stack::push(TreeNode *x){
    LLNode *t = new LLNode;
    if(t == nullptr)
        cout<<"stack is full\n";
    else
    {
        t->data = x ;
        t->next = first;
        first =t;
    }
}
TreeNode* stack::GetTop(){
    return first->data;
}
TreeNode* stack::pop()
{
    TreeNode *x = 0;
    if(first == nullptr)
        cout<<"stack is empty\n";
    else
    {
        LLNode *t =first;
        x = t->data;
        first = first->next;
        delete t;
    }
    return x;
}
void stack::display() {
    LLNode *p = first;
    while( p != nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout << endl;
}

class Tree{
private:
    stack s;
public:
    bool IfOperator(char input);
    int IntoDigit(char input);
    void input(char in);
    void create(string expression);
    double calculate(TreeNode *root);
    stack GetStack(){return s;}

};
bool Tree::IfOperator(char input) {
    if(input == '+' || input == '-' || input == '*' || input == '/')
        return 1;
    else
        return 0;
}

int Tree::IntoDigit(char input) {
    return input - '0';
}

void Tree::input(char in)
{
    if(!IfOperator(in))
    {
        TreeNode *t = new TreeNode;
        t->value = in;
        t->left = NULL;
        t->right =NULL;
        s.push(t);
    }
    else if(IfOperator(in))
    {
        TreeNode *t = new TreeNode;
        t->value = in;
        t->left = s.pop();
        t->right = s.pop();
        s.push(t);
    }
}

void Tree::create(string expression)
{
    int len = expression.length();
    for (int i = len - 1; i >= 0; i--)
        input(expression[i]);
}



double Tree::calculate(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return IntoDigit(root->value);
    else
    {
        double answer = 0.0;
        double right = calculate(root->right);
        double left = calculate(root->left);
        char r = root->value;
        if(r=='+')
            answer = left + right;
        else if(r=='-')
            answer = left - right;

        else if(r=='*')
            answer = left * right;

         else if(r=='/')
            answer = left / right;

        return answer;
    }
}



int main() {
    string s;
    Tree t;
    t.create("+3*4/82");
    cout<<"test case1: \nEvaluation : "<<t.calculate(t.GetStack().GetTop())<<endl;
    t.create("+6*8/66");
    cout<<"test case2: \nEvaluation : "<<t.calculate(t.GetStack().GetTop())<<endl;
    t.create("+2*5*82");
    cout<<"test case3: \nEvaluation : "<<t.calculate(t.GetStack().GetTop())<<endl;
    t.create("*8+3/84");
    cout<<"test case4: \nEvaluation : "<<t.calculate(t.GetStack().GetTop())<<endl;
    t.create("+2*6-65");
    cout<<"test case5: \nEvaluation : "<<t.calculate(t.GetStack().GetTop())<<endl;
    return 0;
}
