#include "linked_list.h"

#include <iostream>

LinkedListNode* merge(LinkedListNode* head1, LinkedListNode* head2)
{
    return nullptr;
}





















bool check_sorted(LinkedListNode *head)
{
    if (!head || !head->next)
        return true;

    int last;
    while (head->next)
    {
        last = head->val;
        if (head->next->val < last)
            return false;

        head = head->next;
    }

    return true;
}

int get_size(LinkedListNode *head)
{
    int size = 0;
    while (head)
    {
        ++size;
        head = head->next;
    }

    return size;
}

void print_list(LinkedListNode *head)
{
    std::cout << "{ ";
    while (head)
    {
        std::cout << head->val << " ";
    }
    std::cout << "}" << std::endl;
}
