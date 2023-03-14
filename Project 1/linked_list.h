#pragma once

struct LinkedListNode
{
    LinkedListNode *next;
    int val;
};

LinkedListNode* merge(LinkedListNode* head1, LinkedListNode* head2);

bool check_sorted(LinkedListNode *head);
int get_size(LinkedListNode *head);
void print_list(LinkedListNode *head);
