/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    example:
    A: a1 → a2 → c1 → c2 → c3
    B: b1 → b2 → b3 → c1 → c2 → c3

    The intersection node is c1.

    pA go: a1 → a2 → c1 → c2 → c3 → b1 → b2 → b3 → c1 → c2 → c3
    pB go: b1 → b2 → b3 → c1 → c2 → c3 → a1 → a2 → c1 → c2 → c3

    After both ponters go lengthA + lengthB, they will meet at the intersection node c1.
*/

 #include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;

    while (pA != pB)
    {
        if (pA == NULL)
        {
            pA = headB;
        }
        else
        {
            pA = pA->next;
        }

        if (pB == NULL)
        {
            pB = headA;
        }
        else
        {
            pB = pB->next;
        }
    }

    return pA;
}