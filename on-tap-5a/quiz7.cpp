Node* deleteSingle(Node* head) {  
    if (head == NULL || head->next == NULL || head->next->next == NULL) {  
        return head;
    }  

    Node* temp = head;  
    Node* previous = NULL;  

    while (temp != NULL) {  
 
        if ((previous == NULL || previous->value != temp->value) && (temp->next == NULL || temp->next->value != temp->value)) {  
 
            if (previous == NULL) {  
                // Nếu node cô đơn là head  
                Node* newHead = temp->next;  
                return newHead; 
            } else {  
                // Nếu node cô đơn không phải là head  
                previous->next = temp->next;   
                return head; 
            }  
        }  
   
        previous = temp;  
        temp = temp->next;  
    }  

    return head;
}