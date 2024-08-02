Node* deleteDuplicates(Node* head) {  
    if (head == NULL) return NULL; 

    vector<int> v;
    v.push_back(head->value);

    Node *temp = head;

    while (temp->next != NULL) {
        bool check = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (temp->next->value == v[i]) {
                check = 1;
                temp->next = temp->next->next;
            }
        }
        
        if (check == 0) {
            v.push_back(temp->next->value);
            temp = temp->next;
        }

    }
     

    return head; 
}