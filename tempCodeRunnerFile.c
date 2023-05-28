#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = result;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum / 10;
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = sum % 10;
        curr->next->next = NULL;
        curr = curr->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return result->next;
}

void displayList(struct ListNode* l) {
    while (l) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main() {
    // Input list 1
    int n1;
    scanf("%d", &n1);
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = l1;
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = val;
        curr->next->next = NULL;
        curr = curr->next;
    }

    // Input list 2
    int n2;
    scanf("%d", &n2);
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr = l2;
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = val;
        curr->next->next = NULL;
        curr = curr->next;
    }

    // Compute sum
    struct ListNode* sumList = addTwoNumbers(l1->next, l2->next);

    // Output result
    displayList(sumList);

    return 0;
}
