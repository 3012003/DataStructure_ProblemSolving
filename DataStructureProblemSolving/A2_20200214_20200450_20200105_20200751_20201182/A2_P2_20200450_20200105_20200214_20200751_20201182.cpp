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
int main()
{
    // valid test cases
    /*
     * first case: There's no one wants to buy a ticket
     * n = 3
     * k = 0
     * all ticket array values equal zero
     * ========================================
     * second test cases:
     * n = 3
     * ticket = [2,3,1]
     * k =2
     * 1st second : 3 1 2
     * 2nd second : 1 2 2
     * 3rd second : 2 2 0
     * So result = 3
     *
     * */

    int n;
    cout << "Enter number of people in queue: ";
    cin >> n;

    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }

    int ticket[n];
    for (int i = 0; i < n; i++)
        cin >> ticket[i];

    int k;
    cout << "Enter the index of person who you want to trace: ";
    cin >> k;
    int res = 0;

    while (ticket[k] > 0)
    {
        int top_indx = q.top();
        if (ticket[top_indx] > 0)
        {
            ticket[top_indx] --;
            q.pop();
            q.push(top_indx);
            res++;
        }
        else if (ticket[top_indx] == 0)
        {
            q.pop();
        }
    }
    cout << res << "\n";
    return 0;
}