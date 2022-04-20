// Program: Singly nexted List
// Coder  : Khalid Saifullah Fuad
// Date   : 03-Apr-2022

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS_VALUE 1
#define NULL_VALUE 0

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL_VALUE;
int length = 0;


// Insert item at the beginning of the list
int insertHead(int item)
{
    struct node *newNode = (struct listNode*) malloc(sizeof(struct node)) ;
    newNode->data = item ;
    newNode->next = head ;

    head = newNode ;

    length++;
    return SUCCESS_VALUE ;
}


// Insert item at the end of the list
int insertTail(int item) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = item;
    node->next = NULL_VALUE;

    if (length == 0) {
        head = node;
    } else {
        struct node *tailNode = head;
        while (tailNode->next != NULL_VALUE) {
            tailNode = tailNode->next;
        }
        tailNode->next = node;
    }

    length++;

    return SUCCESS_VALUE;
}

// Insert item at the given position of the list
int insertItemAt(int position, int item) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = item;

    if (position < 0 || length < position) {
        return NULL_VALUE;
    } else {
        int index = 0;
        struct node *prevNode = head, *nextNode;
        while (index < position - 1) {
            prevNode = prevNode->next;
            index++;
        }

        if(position == 0){
            node->next = head;
            head = node;
        } else {
            nextNode = prevNode->next;
            prevNode->next = node;
            node->next = nextNode;
        }
    }

    length++;

    return SUCCESS_VALUE;
}

// Number of the occurrence of the given item
int countItem(int item) {
    int count = 0;
    struct node *tempNode = head;
    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item) {
            count++;
        }
        tempNode = tempNode->next;
    }
    free(tempNode);
    return count;
}

// Search an item in the linked list
struct node *searchItem(int item) {
    struct node *tempNode = head;
    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item)
            return tempNode;

        tempNode = tempNode->next;
    }
    free(tempNode);
    return NULL_VALUE;
}

// Deletes the first item of the list
int deleteHead() {
    if (length == 0) return NULL_VALUE;

    struct node *headNode = head;
    head = headNode->next;

    free(headNode);
    length--;

    return SUCCESS_VALUE;
}

// Deletes the first item of the list
int deleteTail() {
    if (length == 0) return NULL_VALUE;

    struct node *tailNode = head, *prevNode;

    while (tailNode->next != NULL_VALUE) {
        prevNode = tailNode;
        tailNode = tailNode->next;
    }

    prevNode->next = NULL_VALUE;
    free(tailNode);
    length--;

    return SUCCESS_VALUE;
}

// Delete the last occurrence of the given item in the list
int deleteLast(int item) {
    int itemCount = countItem(item), count = 0;
    if (length == 0 || itemCount == 0) return NULL_VALUE;

    struct node *nextNode = head, *prevNode;

    while (nextNode != NULL_VALUE) {
        if (nextNode->data == item)
            count++;

        if (itemCount == count) {
            if (nextNode == head)
                head = head->next;
            else
                prevNode->next = nextNode->next;
            break;
        }

        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    return SUCCESS_VALUE;
}

// Deletes all the occurrence of the given item in the list
int deleteAll(int item) {
    int itemCount = countItem(item);
    if (length == 0 || itemCount == 0) return NULL_VALUE;

    struct node *nextNode = head, *prevNode;

    while (nextNode != NULL_VALUE) {
        if (nextNode->data == item && nextNode == head) {
            prevNode = head;
            head = prevNode->next;
        } else if (nextNode->data == item) {
            prevNode->next = nextNode->next;
        } else {
            prevNode = nextNode;
        }
        nextNode = prevNode->next;
    }

    return SUCCESS_VALUE;
}

// Delete an item from list
int deleteItem(int item) {
    struct node *tempNode, *prevNode;
    tempNode = head;

    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item)
            break;
        prevNode = tempNode;
        tempNode = tempNode->next;
    }

    if (tempNode == NULL_VALUE)
        return NULL_VALUE;

    if (tempNode == head) {
        head = head->next;
    } else {
        prevNode->next = tempNode->next;
    }
    length--;

    return SUCCESS_VALUE;
}

// Print the nexted list
void printList() {
    printf("--------------------\n");
    printf("[");

    struct node *tempNode = head;

    while (tempNode != NULL_VALUE) {
        printf("%d", tempNode->data);
        tempNode = tempNode->next;

        if (tempNode != NULL_VALUE) printf(", ");
    }

    printf("]\n");
    free(tempNode);
}

int main() {

    int choice, number;

    printf("--------------------\n");
    printf(" Singly nexted List\n");
    printf("--------------------\n");
    printf("1. Insert Item Last\n");
    printf("2. Insert Item At\n");
    printf("3. Count Items\n");
    printf("4. Delete First Item\n");
    printf("5. Delete Last Item\n");
    printf("6. Delete All Match\n");
    printf("7. Delete Last Match\n");
    printf("0. Exit\n");

    do {
        printf("--------------------\n");
        printf(">>> ");

        scanf("%d", &choice);

        printf("--------------------\n");
        if (choice == 1) {
            printf("    INSERT LAST  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);

            insertTail(number);
            printList();

        } else if (choice == 2) {
            int position;
            printf("    INSERT POSITION  \n");
            printf("--------------------\n");
            printf("Enter position : ");
            scanf("%d", &position);
            printf("Enter a Number : ");
            scanf("%d", &number);

            int value = insertItemAt(position, number);
            if (value == NULL_VALUE){
                printf("--------------------\n");
                printf("Invalid Position !!\n");
            }
            printList();

        } else if (choice == 3) {
            printf("  COUNT OPERATION  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            printf("Found %d times!!\n", countItem(number));

            printList();
        } else if (choice == 4) {
            printf(" DELETE FIRST ITEM  \n");
            printf("--------------------\n");

            int value = deleteHead(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 5) {
            printf("  DELETE LAST ITEM  \n");
            printf("--------------------\n");

            int value = deleteTail(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 6) {
            printf("  DELETE ALL MATCH\n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            int value = deleteAll(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 7) {
            printf("  DELETE LAST MATCH  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            int value = deleteLast(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();
        } else if (choice != 0) {
            printf("  INVALID OPTION!!  \n");
        }
    } while (choice != 0);

    printf("")

    return 0;
}
