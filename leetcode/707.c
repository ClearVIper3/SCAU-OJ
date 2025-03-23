typedef struct MyLinkedList{
    int val;
    struct MyLinkedList*next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head=malloc(sizeof(MyLinkedList));
    head->next=NULL;
    head->val=0;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0||obj->next==NULL){
        return -1;
    }

    MyLinkedList* ptr=obj->next;
    for(int i=0;i<index;i++){
        if(ptr == NULL) {
            return -1;
        }
        ptr=ptr->next;
    }

    if(ptr != NULL)
    {
        return ptr->val;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,0,val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    int i=0;
    MyLinkedList* ptr = obj;
    while(ptr->next != NULL){
        ptr=ptr->next;
        i++;
    }
     myLinkedListAddAtIndex(obj,i,val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<0)
    {
        return;
    }
    MyLinkedList* n=malloc(sizeof(MyLinkedList));
    n->val=val;
    MyLinkedList* ptr = obj;
    int i = 0;
    while(i < index && ptr->next != NULL){
        ptr = ptr->next;
        i++;
    }

    if(i==index){
        n->next=ptr->next;
        ptr->next=n;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || obj->next==NULL){
        return;
    }

    if(index == 0){
        obj->next=obj->next->next;
        return;
    }

    MyLinkedList* ptr=obj->next;
    int i=0;
    while(ptr->next!=NULL){
        if(i == index - 1){
            break;
        }
        i++;
        ptr=ptr->next;
    }
    if(i == index - 1 && ptr->next != NULL){
        ptr->next = ptr->next->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj->next != NULL){
        myLinkedListFree(obj->next);
        obj->next = NULL;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
