#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node *next;
    node()
    {
        next = nullptr;
    }
};
template <class T>
class LinkedList
{
private:
    node<T> *head;

public:
    LinkedList();
    ~LinkedList();
    void insert(T val);
    void deleteNode(T val);
    void display();
};
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    cout << "List is going to be deleted." << endl;
}
template <class T>
void LinkedList<T>::insert(T val)
{
    node<T> *newNode = new node<T>;
    newNode->data = val;
    if (head)
    {
        node<T> *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else
        head = newNode;
}

template <class T>
void LinkedList<T>::display()
{
    if (head)
    {
        node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    else
    {
        cout << "Nothing to display" << endl;
    }
}

template <class T>
void LinkedList<T>::deleteNode(T val)
{
    if (head)
    {
        node<T> *temp = head;
        node<T> *prev = temp;
        if (val == head->data)
        {
            head = head->next;
        }
        else
            while (temp != nullptr)
            {
                if (temp->data == val)
                {
                    prev->next = temp->next;
                }
                prev = temp;
                temp = temp->next;
            }
    }

    else
    {
        cout << "Nothing to delete" << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputl.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LinkedList<char> *list = new LinkedList<char>();
    list->insert('R');
    list->insert('A');
    list->insert('H');
    list->insert('U');
    list->insert('L');

    list->display();
    list->deleteNode('R');
    list->display();
    list->deleteNode('L');
    list->display();
    return 0;
}
