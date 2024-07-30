SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (llist == NULL) {
        return llist;
    }

    SinglyLinkedListNode* temp = llist;

    vector<int> value;
    while (temp != NULL) 
    {
        value.push_back(temp->data);
        temp = temp->next;
    }

    SinglyLinkedListNode* temp2 = llist;

    int n = value.size();
    for (int i = n-1; i >= 0; i--) {
        temp2->data = value[i];
        temp2 = temp2->next;
    }

    return llist;

}