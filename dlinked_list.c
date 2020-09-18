#include "monty.h"

/**
 *add_dnodeint - function that creates a node at the beginning
 *@head: pointer to the first node;
 *@n: int to add to the new node;
 *Return: pointer to the first element of the list;
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *tmp = *head;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		tmp->prev = new;
	*head = new;

	return (*head);

}

/**
 * print_dlistint - print all the elements of a double linked lists
 * @h: pointer to the double linked list to prints
 * Return: The number of nodes printed
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	if (h == NULL)
		return (0);

	printf("%d\n", h->n);
	i++;
	if (h->next == NULL)
		return (i);

	i += (print_dlistint(h->next));

	return (i);
}

/**
 *free_dlistint - function that frees the memory allocation for a linked
 *list.
 *@head: pointer to the linked list.
 *Return: None.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *aux;

	while (head != NULL)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
