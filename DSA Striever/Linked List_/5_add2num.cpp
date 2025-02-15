// https://www.naukri.com/code360/problems/add-two-numbers_1170520
// https://leetcode.com/problems/add-two-numbers/description/
// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Node* addTwoNumbers(Node* num1, Node* num2) {
  // Write your code here.
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while (temp1 || temp2) {
        int sum = 0;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;
        sum += carry;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
}