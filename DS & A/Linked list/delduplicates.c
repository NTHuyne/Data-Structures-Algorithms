#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *makeNode (int v){
    struct ListNode *p = (struct ListNode*) malloc(sizeof (struct ListNode));
    p -> val = v; p->next = NULL; 
    return p;
}

void push(struct ListNode **head_ref, int x){
    struct ListNode *new_node = makeNode(x);
    if(*head_ref == NULL)
        *head_ref = new_node;
    else{
        struct ListNode *last = *head_ref;
        while (last ->next!=NULL){
            last = last ->next;
        }
        last ->next = new_node;
    }
}

// struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
//     if(head ->next == NULL)
//         return NULL;
//     struct ListNode *temp=head;
//     struct ListNode *prevTemp;
//     int length=0;
//     while(temp!=NULL){
//         length++;
//         temp=temp->next;
//     }
//     int nodesToSkip=length-n;
//     temp = head;
//     if (nodesToSkip == 0){
//         head = temp ->next;
//         free(temp);
//     }
//     else{
//         while(nodesToSkip != 0){
//             prevTemp = temp;
//             temp = temp -> next; 
//             nodesToSkip --;
//         }
//         prevTemp ->next = temp ->next;
//         free(temp);
//     }
//     return head;
// }

struct ListNode *deleteDuplicate(struct ListNode *head){
    if(head == NULL)
        return NULL;
    if(head -> next == NULL)
        return head;
    if(head->val == head ->next -> val){
        struct ListNode *temp = head->next;
        head ->next = head ->next->next;
        free(temp);
        return deleteDuplicate(head);
    }
    else{
        head->next = deleteDuplicate(head->next);
        return head;
    }
}

void display(struct ListNode *node){
    while (node != NULL){
        printf("%d ", node -> val);
        node = node ->next;
    }
}

int main(){
    struct ListNode *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 5);
    printf("Linked List before removal: \n");
    display(head);
    head = deleteDuplicate(head);
    printf("\nLinked List after removal: \n");
    display(head);    
    return 0;
}