#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007 // 1e9

// LINKED LIST using struct
// struct Node1
class Node1
{
public:
    int data;
    Node1 *next;
    Node1(int x, Node1 *next1)
    {
        data = x;
        next = next1;
    }
};
class Node2
{
public:
    int data;
    Node2 *next;
    Node2(int x)
    {
        data = x;
        next = nullptr;
    }
};

void Vatsh1() // 22:00
{
    // Your logic goes here

    // Node1 x = Node1(2, nullptr); // oject, not memory location
    // Node1 *y = &x; // pointer

    Node1 x = Node1(4, nullptr);
    cout << x.data << " " << x.next << endl;

    Node1 *y = new Node1(2, nullptr); // stores pointer to memory location
    cout << y->data << " " << y->next << endl;

    delete y;    // deletes the memory location
    y = nullptr; // deletes the pointer
    cout << y->data << " " << y->next << endl;
    return;
}

void Vatsh2()
{
    // Your logic goes here

    Node1 *head = new Node1(1, nullptr);
    Node1 *temp = head;
    for (int i = 2; i <= 10; i++)
    {
        // temp->next = new Node1(i, nullptr);
        Node1 *t = new Node1(i, nullptr);
        temp->next = t;
        temp = temp->next;
    }
    temp = head; // saving head
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return;
}

void Vatsh3()
{
    // Your logic goes here

    Node2 *head = new Node2(1);
    Node2 *temp = head;
    for (int i = 2; i <= 10; i++)
    {
        // temp->next = new Node2(i);
        Node2 *t = new Node2(i);
        temp->next = t;
        temp = temp->next;
    }
    temp = head; // saving head
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return;
}

int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        // Vatsh1();
        // Vatsh2();
        Vatsh2();
    }

    return 0;
}