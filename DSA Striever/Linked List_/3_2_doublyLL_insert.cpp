/*
https://www.naukri.com/code360/problems/insert-before-the-given-node-of-a-doubly-linked-list_9719100

https://www.naukri.com/code360/problems/insert-at-the-front-of-a-doubly-linked-list_9697366

https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464

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

void insertBeforeHead(int data, Node *&head);
void insertBeforTail(int data, Node *&head);
void insertAfterTail(int data, Node *&tail);
void printH(Node *head);
void printT(Node *head);

void insertBeforeKth(int k, int x, Node *&head)
{
  Node *tail = head;
  if (k == 0)
  {
    insertBeforeHead(x, head);
    return;
  }
  while (k--)
    tail = tail->next;
  Node *temp = new Node(x, tail, tail->prev);

  if (tail->prev != nullptr)
    tail->prev->next = temp;
  tail->prev = temp;
}

void insertBeforeNode(int x, Node *toAdd, Node *&head)
{
  if (!toAdd || !toAdd->prev)
  {
    insertBeforeHead(x, head);
    return;
  }

  Node *temp = new Node(x, toAdd, toAdd->prev);
  toAdd->prev->next = temp;
  toAdd->prev = temp;
}

void LinkedList(vector<int> arr)
{
  Node *head = nullptr;
  Node *tail = head;
  // printH(head);

  insertBeforeHead(11, head);
  insertBeforTail(13, head);
  insertBeforTail(14, head);
  insertBeforeHead(7, head);
  insertBeforeKth(0, 5, head);
  insertBeforeNode(9, head->next, head);

  printH(head);
  printT(head);
}

int32_t main()
{

  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  LinkedList(arr);

  return 0;
}

void insertBeforeHead(int x, Node *&head)
{
  Node *temp = new Node(x);
  temp->next = head;
  temp->prev = nullptr;
  if (head != nullptr)
    head->prev = temp;
  head = temp;
}

void insertBeforTail(int x, Node *&head)
{
  if (!head || !head->next)
  {
    insertBeforeHead(x, head);
    return;
  }
  Node *tail = head;
  while (tail->next)
    tail = tail->next;
  Node *temp = new Node(x, tail, tail->prev);

  if (tail->prev != nullptr)
    tail->prev->next = temp;
  tail->prev = temp;
}

void insertAfterTail(int x, Node *&tail)
{
  // Node *temp = new Node(x);
  // temp->next = nullptr;
  // temp->prev = tail;
  // if (tail != nullptr)
  //   tail->next = temp;
  // tail = temp;
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

void printT(Node *head)
{
  Node *tail = head;
  if (tail == nullptr)
  {
    cout << "{}" << endl;
    return;
  }
  while (tail->next)
    tail = tail->next;
  while (tail != nullptr)
  {
    cout << tail->data << " ";
    tail = tail->prev;
  }
  cout << endl;
}