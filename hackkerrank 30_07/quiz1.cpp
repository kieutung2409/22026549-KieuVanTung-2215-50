void printLinkedList(SinglyLinkedListNode* head) {
    
    if (head == NULL) {
        
    }
    
    SinglyLinkedListNode* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    
}