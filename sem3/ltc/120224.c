//Ltc Delete nth node from the end of a SLL
// Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int cnt = 0;
    struct ListNode *traverse = head, *prev = head;
    while (traverse != NULL)
    {
        cnt++;
        traverse = traverse->next;
    }
    if (head->next == NULL)
    {
        // only node
        return NULL;
    }
    int i=1;
    //1 2 3 4 5 
    //n=2
    //1 2 3 5
    traverse = head;
    while ((traverse != NULL) && (i != (cnt-n)+1))
    {
        prev = traverse;
        i++;
        traverse = traverse->next;
    }
    // reached end or node

    if (traverse == NULL)
    {
        // not found
        return head;
    }
    if(traverse==head)
    {
        head=head->next;        
    }
    prev->next = traverse->next;
    return head;
}
 
    //free(traverse->next);
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        int cnt = 0;
    struct ListNode *traverse = head, *prev = head;
    while (traverse != NULL)
    {
        cnt++;
        traverse = traverse->next;
    }
    traverse = head;
    if (head->next == NULL)
    {
        // only node
        return NULL;
    }
    int i=0;
    while ((traverse != NULL) && (i != cnt-n))
    {
        prev = head;
        i++;
        traverse = traverse->next;
    }
    // reached end or node

    if (traverse == NULL)
    {
        // not found
        return head;
    }
    prev->next = traverse->next;
    return head;
}

}
*/


