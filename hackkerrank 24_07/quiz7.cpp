SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (llist == NULL) {
        return llist;
    }
    
    SinglyLinkedListNode* temp = llist;
    
    if (position == 0) {
        temp = temp->next;
    }
    int count = 0;
    while(temp != NULL) {
        if (count == position-1) {
            
            temp->next = temp->next->next;
            break;
        } else {
            count++;
        }
        
        temp = temp->next;

    }
    
    return llist;

}