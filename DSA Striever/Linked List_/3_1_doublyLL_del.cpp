/*
https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413

https://www.naukri.com/code360/problems/delete-k-th-node-from-doubly-linked-list_9723679

https://www.naukri.com/code360/problems/non-head-node-deletion_9719173

https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469
*/
// doubly linked list

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007 // 1e9

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
    Node(int x, Node *next_, Node *prev_)
    {
        data = x;
        next = next_;
        prev = prev_;
    }
};

void deleteHead(Node *&head, Node *&tail);
void deleteTail(Node *&head, Node *&tail);
void printT(Node *tail);
void printH(Node *head);

void deleteKth(int k, Node *&head, Node *&tail)
{
    int cnt = k;
    Node *temp = head;
    while (cnt--)
    {
        temp = temp->next;
    }
    if (temp->next == NULL && temp->prev == NULL)
    {
        delete temp;
        return;
    }
    if (temp->next == NULL)
    {
        deleteTail(head, tail);
        return;
    }
    if (temp->prev == NULL)
    {
        deleteHead(head, tail);
        return;
    }
    Node *back = temp->prev;
    Node *front = temp->next;
    back->next = front;
    front->prev = back;
    delete (temp);
}

void deleteNode(Node *toDel, Node *&head, Node *&tail)
{
    Node *back = toDel->prev;
    Node *front = toDel->next;
    if (!front && !back)
    {
        delete toDel;
        return;
    }
    if (!front)
    {
        deleteTail(head, tail);
        return;
    }
    if (!back)
    {
        deleteHead(head, tail);
        return;
    }
    back->next = front;
    front->prev = back;
    delete (toDel);
}

void LinkedList(vector<int> arr)
{
    Node *head = nullptr;
    head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    printH(head);
    // printT(tail);

    // deleteHead(head, tail);
    // deleteTail(head, tail);
    // printH(head);
    // printT(tail);

    int k = 3;
    deleteKth(0, head, tail);
    printH(head);
    // printT(tail);

    Node *toDel = head;
    for (int i = 0; i < 3; i++)
    {
        toDel = toDel->next;
    }
    deleteNode(head, head, tail);
    printH(head);
}

int32_t main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    // vector<int> arr = {1};
    LinkedList(arr);

    return 0;
}

void deleteHead(Node *&head, Node *&tail)
{
    // if (head == nullptr)
    //     return;
    // // If head is the only node in the list
    // if (head == tail)
    // {
    //     delete head;
    //     head = nullptr;
    //     tail = nullptr;
    //     return;
    // }
    Node *temp = head;
    head = head->next;
    // if (head != nullptr)
    head->prev = nullptr;
    delete temp;
}

void deleteTail(Node *&head, Node *&tail)
{
    // if (tail == nullptr)
    //     return;
    // // If tail is the only node in the list
    // if (head == tail)
    // {
    //     delete tail;
    //     head = nullptr;
    //     tail = nullptr;
    //     return;
    // }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void printH(Node *head)
{
    if (head == nullptr)
    {
        cout << "{}" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printT(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "{}" << endl;
        return;
    }
    while (tail != nullptr)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}