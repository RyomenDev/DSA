// deletion in link

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007 // 1e9

// create linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void insert(Node *&head, int data)
{
    Node *temp = new Node(data);
    head->next = temp;
    // head = head->next;
}

void deleteHead(Node *&head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(Node *&head)
{
    if (!head)
        return;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = nullptr;
    delete temp2;
}

void deleteByValue(Node *&head, int data)
{
    if (!head)
        return;
    Node *temp = head;
    if (temp->data == data)
    {
        deleteHead(head);
        return;
    }
    while (temp->next != nullptr && temp->next->data != data)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
        return;
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    // If the deleted node was the last node in the linked list, update the next pointer of the previous node to nullptr
    if (temp->next == nullptr)
        temp->next = nullptr;
    delete temp2;
}

void deleteByIndex(Node *&head, int index)
{
    if (!head || index < 0)
        return;
    Node *temp = head;
    if (index == 0)
    {
        deleteHead(head);
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (!temp)
            return;
    }
    if (!temp || !temp->next)
        return;
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void deleteByNode(Node *&head, Node *node)
{
    if (!head)
        return;
    Node *temp = head;
    if (temp == node)
    {
        deleteHead(head);
        return;
    }
    while (temp->next != node)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}


void print(Node *head)
{
    Node *temp = head; // saving head
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Vatsh()
{
    // Your logic goes here
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 10; i++)
    {
        insert(temp, i);
        temp = temp->next;
    }
    deleteHead(head);
    deleteEnd(head);

    deleteByValue(head, 5);
    deleteByIndex(head, 5);

    // deleteByNode(head,head);
    // deleteByNode(head,head->next);
    Node *node = head;
    for (int i = 0; i < 4; i++)
    {
        node = node->next;
    }
    deleteByNode(head, node);

    print(head); // print the linked list
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}