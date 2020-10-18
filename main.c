#include<stdio.h>
#include<stdlib.h>

typedef struct elem {
    int val;
    struct elem *nxt;
} elem;

elem *head;

struct elem* createList(){
    head = (elem *)malloc(sizeof(elem));
    head->nxt = NULL;
    return head;
}

struct  elem* creatNode(int value) {
    elem *temp = (elem *)malloc(sizeof(elem));
    temp->val = value;
    temp->nxt = NULL;
    return temp;
}

void listPrint(elem *temp){
    temp = temp->nxt;
    while (temp != NULL) {
        printf(" %d ", temp->val);
        temp = temp->nxt;
    }
}

void insertq(elem *qhead, int value){
    elem *temp = creatNode(value);
    if (qhead->nxt== NULL) {
        qhead->nxt = temp;
    } else {
        while (1) {
            if (qhead->nxt == NULL) {
               qhead->nxt = temp;
                break;
            }
            qhead = qhead->nxt;
        }
    }
}

void removeq(elem * qhead){
        while (qhead!= NULL) {
            if (qhead->nxt->nxt == NULL) {
                qhead->nxt = NULL;
                break;
            }
            qhead = qhead->nxt;
        }
    return;
}

int sizeq(elem *qhead){
    int i = 0;
    qhead = qhead->nxt;
    while(qhead) {
        qhead = qhead->nxt;
        i++;
    }
    return i;
}

elem* searchq(elem *qhead, int value){
    qhead = qhead->nxt;
    while (qhead) {
        if (qhead->val == value) {
            return qhead;
        }
        qhead = qhead->nxt;
    }
    return NULL;
}

int main() {
    struct elem* list = createList();
    insertq(list,1);
    insertq(list,2);
//    insertq(list,3);
//    insertq(list,1);
//    insertq(list,2);
    //insertq(list,2);
    removeq(list);
//   removeq(list);
//    removeq(list);
//    removeq(list);
    listPrint(list);
    //struct elem* abc = searchq(list, 1);
    //printf("\n The value is %d \n", abc->val);
    printf("\nThe size of linkedlist is: %d\n",sizeq(list));

}
