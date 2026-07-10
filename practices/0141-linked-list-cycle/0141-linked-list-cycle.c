#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode 
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        /*
            If there is a cycle, the fast pointer will meet the slow pointer.
        */
        slow = slow->next;
        fast = fast->next->next;

        /*
            If the slow pointer and fast pointer meet, it indicates that there is a cycle in the linked list.
        */
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}