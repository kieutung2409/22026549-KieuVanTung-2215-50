SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (llist == NULL) {
        return newNode;
    }
    
    SinglyLinkedListNode* temp = llist;
    int count = 0;
    while(temp != NULL) {
        if (count == position-1) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        } else {
            count++;
        }

        temp = temp->next;

    }
    
    return llist;

}