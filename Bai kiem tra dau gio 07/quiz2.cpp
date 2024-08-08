Node* sort(Node* head) {  
    if (!head) return nullptr;
    Node* sorted = nullptr;  

    Node* current = head; 

    while (current) {  
        Node* next = current->next;  
        current->next = nullptr;
        current->prev = nullptr;  

        if (!sorted || sorted->getValue() >= current->getValue()) {  
            current->next = sorted;  
            if (sorted) {  
                sorted->prev = current;  
            }  
            sorted = current;  
        } else {  
            Node* temp = sorted;  
            while (temp->next && temp->next->getValue() < current->getValue()) {  
                temp = temp->next;  
            }  
            current->next = temp->next;  
            if (temp->next) {  
                temp->next->prev = current;  
            }  
            temp->next = current;  
            current->prev = temp;  
        }  

        current = next;
    }  

    return sorted;  
}  
