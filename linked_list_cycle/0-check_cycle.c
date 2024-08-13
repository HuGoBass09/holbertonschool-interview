#include "lists.h"

/**
 * check_cycle - check whether linked list has a cycle or not
 * @head: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *head)
{
    int size = print_listint(head);
    for (int i = 0; i < size; ++i)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}