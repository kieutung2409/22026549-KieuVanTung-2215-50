Node* insertHead(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head = newNode;
    
    return head;
}