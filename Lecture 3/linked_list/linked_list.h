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

// LinkedListNode * add_node_to_end(LinkedListNode *head, int val);
// LinkedListNode * add_node_to_end(LinkedListNode *head, int val);
// LinkedListNode * add_node_to_end(LinkedListNode *head, int val);

// LinkedListNode * remove_last_node(LinkedListNode *head, int val);
// LinkedListNode * remove_next_node(LinkedListNode *head, int val);
