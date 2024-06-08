// https://www.naukri.com/code360/problems/search-in-a-linked-list_975381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007
template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T *next)
    {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k)
{
    Node<int> *temp = head;
    while (temp)
    {
        if (temp->data == k)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node<int> *head = new Node<int>(10);
    head->next = new Node<int>(20);
    head->next->next = new Node<int>(30);
    head->next->next->next = new Node<int>(40);
    head->next->next->next->next = new Node<int>(50);
    cout << searchInLinkedList(head, 30);

    return 0;
}