#include "lists.h"

/**
 * print_dlistint - prints all the elements
 * @h: the main
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int data;
	data = 0;

	if (h == NULL)
		return (data);
	while (h->prev != NULL)
		h = h->prev;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		data++;
		h = h->next;
	}
	return (data);
}
