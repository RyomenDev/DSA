// https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098

Node* reverseDLL(Node* head) {
  // Write your code here
    if (!head)
        return nullptr;
    Node* current = head;
    Node* ans = head;
    int i = 1;
    while (current) {
        Node* last = current->prev;
        current->prev = current->next;
        current->next = last;
        i++;
        ans = current;
        current = current->prev; // next
    }
    return ans;
}