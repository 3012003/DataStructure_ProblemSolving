#include <iostream>
#include<string>
using namespace std;
struct node{
    string data;
    node *next;
};
class stack{
private:
    node *top;
public:
    stack():top{nullptr}{}
    void push(string x);
    string pop();
    void display();
    bool IsEmpty();
    string Top();
    int count();

};

void stack::push(string x){
    node *t = new node;
    if(t == nullptr)
        cout<<"stack is full\n";
    else
    {
        t->data = x ;
        t->next = top;
        top =t;
    }
}
string stack::pop()
{
    string x = "-1";
    if(top == nullptr)
        cout<<"stack is empty\n";
    else
    {
        node *t =top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

void stack::display() {
    node *p = top;
    while( p != nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout << endl;
}

bool stack::IsEmpty() {
    return top == NULL;
}

string stack::Top()
{
    string x = top->data;
    return x;
}

int stack::count(){
    int c = 0;
    node *p = top;
    while(p!= NULL){
        c++;
        p = p->next;
    }
    return c;
}

string ToCan(string path)
{
    stack s;
    string result , temp1;
    result+="/";
    for(int i =0 ; i<path.length() ; i++)
    {
        temp1 ="";
        while(path[i] == '/')
            i++;
        while(path[i] != '/' && i<path.length())
        {
            temp1.push_back(path[i]);
            i++;
        }

        if(temp1 == "..")
        {
            if(!s.IsEmpty())
                s.pop();
        }
        else if( temp1 == ".")
            continue;
        else if(temp1.length() !=0)
            s.push(temp1);
    }

    stack TempStack;
    while(! s.IsEmpty())
    {
        TempStack.push(s.pop());
    }

    while (!TempStack.IsEmpty()) {
        string temp2 = TempStack.Top();
        if (TempStack.count() != 1)
            result.append(temp2 + "/");
        else
            result.append(temp2);
        TempStack.pop();
    }
    //result.pop_back();
    return result;
}


int main()
{
    cout<<"First test case: \n";
    string output1 = ToCan("/home//foo/");
    cout << output1<<endl;
    cout<<"Second test case: \n";
    string output2 = ToCan("/home/");
    cout << output2<<endl;
    cout<<"Third test case: \n";
    string output3 = ToCan("/../");
    cout << output3<<endl;
    cout<<"Fourth test case: \n";
    string output4 = ToCan("/root/./real/");
    cout << output4<<endl;
    cout<<"Fifth test case: \n";
    string output5 = ToCan("/root/../here/");
    cout << output5<<endl;


    return 0;

}

