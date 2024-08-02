void print(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout<< temp->value<< " ";
        temp = temp->next;
    }
}