#include "linked_list.h"

#include <iostream>

LinkedListNode* merge(LinkedListNode* head1, LinkedListNode* head2)
{
    LinkedListNode* result;
    LinkedListNode** current = &result;

    while (1)
    {
        if (!head1)
        {
            *current = head2;
            break;
        }

        if (!head2)
        {
            *current = head1;
            break;
        }

        LinkedListNode* new_node;
        if (head1->val < head2->val)
        {
            new_node = head1;
            head1 = head1->next;
            new_node->next = *current;
            *current = new_node;
        }
        else
        {
            new_node = head2;
            head2 = head2->next;
            new_node->next = *current;
            *current = new_node;
        }

        current = &((*current)->next);
    }

    return result;
}

bool check_sorted(LinkedListNode* head)
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

int get_size(LinkedListNode* head)
{
    int size = 0;
    while (head)
    {
        ++size;
        head = head->next;
    }

    return size;
}

void print_list(LinkedListNode* head)
{
    std::cout << "{ ";
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "}" << std::endl;
}
