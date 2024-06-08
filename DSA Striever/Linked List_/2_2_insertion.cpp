// insertion

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
}

void insertAtBegin(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = temp;
}

void insertAtIndex(Node *&head, int data, int index)
{
    Node *temp = new Node(data);
    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
        if (current == nullptr)
        {
            // cout << "Invalid index" << endl;
            return;
        }
    }
    temp->next = current->next;
    current->next = temp;
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
    for (int i = 2; i <= 5; i++)
    {
        insert(temp, i);
        temp = temp->next;
    }
    insertAtBegin(head, 7);
    insertAtEnd(head, 8);
    insertAtIndex(head, 9, 3);

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