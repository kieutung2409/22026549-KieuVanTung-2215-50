void reversePrint(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* temp = llist;

    vector<int> value;
    while (temp != NULL) 
    {
        value.push_back(temp->data);
        temp = temp->next;
    }

    int n = value.size();
    for (int i = n-1; i >= 0; i--) {
        cout<< value[i]<< endl;
    }

}