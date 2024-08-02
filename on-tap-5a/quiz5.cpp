void printLast(Node* head, int k) {
    if (head == NULL) {
        
    }
    
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    temp = head;
    int n = 0;
    while(temp != NULL) {
        if (n >= count - k) {
            cout<< temp->value<< " ";
        }
        n++;
        temp = temp->next;
    }
}