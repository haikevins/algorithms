/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Step 1: Check if cycle exists
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Step 2: Find the start node of cycle
            struct ListNode* ptr = head;

            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }

            return ptr;
        }
    }

    return NULL;
}