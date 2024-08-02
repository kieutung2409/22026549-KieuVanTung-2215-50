
Node* sort(Node* head) {  

    if (head == nullptr || head->next == nullptr) {  
        return head;  
    }  

    Node* sorted = nullptr;

    Node* current = head;  
    while (current != nullptr) {  

        Node* newNode = new Node(); 
        newNode->value = current->getValue();
 
        if (sorted == nullptr) {  
            // Nếu danh sách đã sắp xếp rỗng, gán node mới làm đầu danh sách  
            sorted = newNode;  
        } else {  
            Node* temp = sorted;  

            while (temp != nullptr && temp->getValue() < newNode->getValue()) {  
                temp = temp->next;  
            }  
 
            if (temp == sorted) {   
                newNode->next = sorted;  
                sorted->prev = newNode;  
                sorted = newNode;  
            } else {  
                newNode->next = temp;  
                newNode->prev = temp ? temp->prev : nullptr;  

                if (temp != nullptr) {  
                    temp->prev = newNode; 
                }  

                if (newNode->prev != nullptr) {  
                    newNode->prev->next = newNode;
                }  
            }  
        }  
  
        current = current->next;  
    }  

    return sorted; 
}