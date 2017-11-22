#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int value; //value of element of linked list
    struct item *next; //pointer to next item of linked list
} item;

item * get(item *l, int i);
void addItem(int i, item *l);
void addItemByIndex(int i, item *l, int i2);
void removeItem(item *i, item *l);
void removeItemByIndex(int i, item *l);
item * reverseList(item *i);
void printList(item *i);

int main(int argc, char** argv){
    int choice=1;
    item *list = malloc(sizeof(item));
    list->next = NULL;
    list->value = NULL;
    while(choice != -1){
        printf("Select desired option:\n");
        printf("0. Add element to linked list\n");
        printf("1. Remove element from linked list\n");
        printf("2. Reverse linked list\n");
        printf("3. Print linked list\n");
        printf("4. Get value at index\n");
        printf("-1. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        int val;
        int index;
        switch(choice){
            case 0:
                printf("Enter value to add: ");
                scanf("%d", &val);
                printf("Enter desired index (put negative number for adding element at end): ");
                scanf("%d", &index);
                if(index < 0){
                    addItem(val, list);
                }else{
                    addItemByIndex(val, list, index);
                }
                break;
            case 1:
                printf("Enter index of element to remove (if index larger than number of elements last element is removed): ");
                scanf("%d", &index);
                removeItemByIndex(index, list);
                break;
            case 2:
                list = reverseList(list);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                printf("Enter index of desired element: ");
                scanf("%d", &index);
                printf("%d\n", get(list, index)->value);
                break;
        }
    }
    free(list);
    return 0;
}

item * get(item *l, int i){
    if(i < 0)return;
    int a = -1;
    while(l->next != NULL && a<i){
        l = l->next;
        a++;
    }
    return l;
}
void addItem(int i, item *l){//i is item to add, l is pointer to element of list to add too
    while(l->next != NULL){
        l = l->next;
    }
    item *ni = malloc(sizeof(item));
    ni->value = i;
    ni->next = NULL;
    l->next = ni;
}
void addItemByIndex(int i, item *l, int i2){//i is item to add, a is where to add it, l is pointer to element of list to add too
    if(i2 < 0)return;
    int a = 0;
    while(l->next != NULL && a<i2){
        l = l->next;
        a++;
    }
    item *ni = malloc(sizeof(item));
    ni->value = i;
    ni->next = l->next;
    l->next = ni;
}
void removeItem(item *i, item *l){//i is pointer to item to remove, l is pointer to element of list to remove from
    while(l->next != i){
        l = l->next;
    }
    l->next = i->next;
    free(i);
}
void removeItemByIndex(int i, item *l){//i is index of item to remove, l is pointer to element of list to remove from
    if(i < 0)return;
    int a = 0;
    while(l->next != NULL && a<i){
        l = l->next;
        a++;
    }
    if(l->next == NULL)return;
    item *temp = l->next;
    l->next = temp->next;
    free(temp);
}
item * reverseList(item *i){//i is first item in list to reverse
    if(i->next == NULL)return;
    item *first = i;
    i = i->next;
    item *temp = i->next;
    i->next = NULL;
    while(temp != NULL){
        item *temp2 = temp->next;
        temp->next = i;
        i = temp;
        temp = temp2;
    }
    first->next = i;
    return first;
}
void printList(item *i){
    while(i->next != NULL){
        i = i->next;
        printf("%d ", i->value);
    }
    printf("\n");
}