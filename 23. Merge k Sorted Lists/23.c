#include <stdlib.h> 

/**
 * @brief FUNÇÃO AUXILIAR: 
 *
 * @param l1 
 * @param l2
 * @return
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    
    struct ListNode dummy;
    dummy.val = 0; 
    dummy.next = NULL;
    
    
    struct ListNode* tail = &dummy;

    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
           
            tail->next = l1;
            l1 = l1->next;
        } else {
           
            tail->next = l2;
            l2 = l2->next;
        }
       
        tail = tail->next;
    }

    
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}


/**
 * @brief FUNÇÃO PRINCIPAL: 
 * @param lists 
 * @param listsSize 
 * @return 
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
    if (listsSize == 0) {
        return NULL;
    }
    
    if (listsSize == 1) {
        return lists[0];
    }

   
    int mid = listsSize / 2;
    
    struct ListNode* leftHalf = mergeKLists(lists, mid);
    
    struct ListNode* rightHalf = mergeKLists(lists + mid, listsSize - mid);

    return mergeTwoLists(leftHalf, rightHalf);
}