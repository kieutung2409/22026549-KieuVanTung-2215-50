Node* insert(Node* head, int value) {
    Node *x = new Node;
    x->value = value;
    
    if (head == NULL || head->next == NULL) {
        if (head == NULL) {
            return x;
        }
        
        if (x->value < head->value) {
            x->next = head;
            return x;
        }
        head->next = x;
        return head;
    }
    
    Node *temp = head;

    if (temp->value < temp->next->value) {
        //them vao dau
        if (x->value < temp->value) {
            x->next = temp;
            return x;
        }
        while (temp->next != NULL) {
            if (x->value < temp->next->value) {
                x->next = temp->next;
                temp->next = x;
                break;
            }

            temp = temp->next;
        }
        //them vao cuoi
        if (x->value > temp->value) {
            temp->next = x;
        }

    } else {
        if (x->value > temp->value) {
            x->next = temp;
            return x;
        }
        while (temp->next != NULL) {
            if (x->value > temp->next->value) {
                x->next = temp->next;
                temp->next = x;
                break;
            }

            temp = temp->next;
        }
        if (x->value < temp->value) {
            temp->next = x;
        }

    }

    return head;

}