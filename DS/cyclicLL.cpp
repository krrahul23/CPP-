#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node()
    {
        next = nullptr;
    }
};

class cLinkedList
{
private:
    node *head;

public:
    cLinkedList();
    void insert(int key);
    void display();
};

cLinkedList::cLinkedList()
{
    head = nullptr;
}
void cLinkedList::insert(int key)
{
    if (head)
    {
        node *newNode = new node;
        newNode->data = key;
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    else
    {
        node *newNode = new node;
        newNode->data = key;
        head = newNode;
        newNode->next = newNode;
    }
}

void cLinkedList::display()
{
    if (!head)
        cout << "Nothing to display." << endl;
    else
    {
        node *temp = head->next;
        cout << head->data << " ";
        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cLinkedList *list = new cLinkedList();
    list->insert(5);
    list->display();
    list->insert(234);
    list->display();
    return 0;
}
