#include <iostream>

using namespace std;
template <typename T>

class node
{
public:
    T value;
    node<T> *next;
    node(T x)
    {
        value = x;
        next = NULL;
    }
};

template <typename T>

class Queue
{
    node<T> *start;
    node<T> *end;
    size_t sz;

public:
    Queue()
    {
        start = NULL;
        end = NULL;
        sz = 0;
    }

    bool empty()
    {
        return start == NULL;
    }

    void push(T value)
    {
        node<T> *temp = new node<T>(value);
        if (empty())
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        sz++;
    }

    T front()
    {
        if (empty())
            return NULL;
        else
            return start->value;
    }

    size_t size()
    {
        return sz;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (start == end)
        {
            delete start;
            start = end = NULL;
            sz--;
        }
        else
        {
            node<T> *temp = start;
            start = start->next;
            delete temp;
            sz--;
        }
    }
};

int main()
{
    Queue<string> test;
    test.push("Club");
    test.push("Algoritmia");
    test.push("Escom");
    cout<<test.front()<<endl;

    while (!test.empty())
    {
        cout<<test.front()<<" ";
        test.pop();
    }
    cout<<endl;

    return 0;
}