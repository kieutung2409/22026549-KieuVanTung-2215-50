SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (llist == NULL) {
        return newNode;
    }
    
    newNode->next = llist;
    llist = newNode;
    
    return llist;

}