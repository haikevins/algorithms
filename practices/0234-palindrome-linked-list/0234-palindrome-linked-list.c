#include <stdlib.h>
#include <stdbool.h>

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

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Find the middle of the linked list
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    struct ListNode* secondHalf = reverseList(slow);

    // Compare the first half and the reversed second half
    struct ListNode* firstHalf = head;

    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}