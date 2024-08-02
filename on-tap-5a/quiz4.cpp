Node* deleteNode(Node* head, int pos) {
    if (head == NULL) {
        return head;
    }
    
    Node* temp = head;
    
    if (pos == 0) {
        head = temp->next;
    } else {
        int count = 0;
        while(temp != NULL) {
            if (count == pos-1) {

                temp->next = temp->next->next;

                break;
            } else {
                count++;
            }
            
            temp = temp->next;
        
        }
    }
    
    
    return head;
}