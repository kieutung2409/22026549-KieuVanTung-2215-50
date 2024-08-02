void printReverse(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return;
    }

    printReverse(head->next, k - 1);

    if (k > 0) {
        cout << head->value <<" ";  
    }
}