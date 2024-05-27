
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

void deleteHead(Node *&head, Node *&tail)
{
    if (head == nullptr)
        return;
    // If head is the only node in the list
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *temp = head;
    head = head->next;
    // if (head != nullptr)
    head->prev = nullptr;
    delete temp;
}

void deleteTail(Node *&head, Node *&tail)
{
    if (tail == nullptr)
        return;
    // If tail is the only node in the list
    if (head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
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
    deleteHead(head, tail);
    deleteTail(head, tail);
    printH(head);
    printT(tail);
}

void Vatsh()
{
    // Your logic goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    // vector<int> arr = {1};
    LinkedList(arr);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    // cin>>tt;
    while (tt--)
        Vatsh();

    return 0;
}