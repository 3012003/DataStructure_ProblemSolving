#include <iostream>
using namespace  std;
template<class t>
class queue
{
private:
    struct queueNode
    {
        t val;
        queueNode* next;
    };

    queueNode* fron;
    queueNode* end;
    int length;
public:
    // Constructor
    queue()
    {
        fron = NULL;
        end = NULL;
        length = 0;
    }

    // Destructor


    // size of the queue
    int size()
    {
        return length;

    }

    // check if queue is empty
    bool empty() const
    {
        return (length == 0);
    }

    // push an element to queue
    void push(t num)
    {
        queueNode* newNode;
        newNode = new queueNode;
        newNode->val = num;
        newNode->next = NULL;
        // check if queue is empty
        if (empty())
        {
            fron = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
        length++;
    }

    // remove first element from queue
    t pop()
    {
        queueNode* tmp;
        if (empty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            t value = fron->val;
            tmp = fron;
            fron = fron->next;
            delete tmp;
            length--;
        }

    }

    t top()
    {
        return fron->val;
    }

    t back()
    {
        return end->val;
    }
    t front()
    {
        return fron->val;
    }
};

class stack
{
public:
    queue <int>q;
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        while (size--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int top()
    {
        if (q.empty() == 1)
            return -1;
        else
            return q.front();
    }

    void pop()
    {
        q.pop();
    }

    bool empty() const
    {
        return (q.empty());

    }


};
int main()
{
    stack stk;
    int n;
    cout << "How many items do you want to enter to stack: ";
    cin >> n;

    while (n--)
    {
        int val;
        cout << "Enter: ";
        cin >> val;

        stk.push(val);
    }

    cout << "Our stack: ";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";


    return 0;
}