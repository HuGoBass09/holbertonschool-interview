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
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}