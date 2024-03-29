#include "hash_tables.h"

/**
 * hash_table_set - adds item in a hash table
 * @ht: the table
 * @key: key of the item
 * @value: value of the item
 * Return: 1 for success 0 for failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{	unsigned long int q;
	hash_node_t *new, *tmp;

	if (!ht || !key || !(*key))
		return (0);
	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->key = strdup((char *)key);
	new->value = strdup(value);
	new->next = NULL;
	q = key_index((unsigned char *)key, ht->size);
	if (!(ht->array[q]))
	{
		ht->array[q] = new;
	}
	else
	{	/* check for update */
		tmp = ht->array[q];
		while (tmp && strcmp(tmp->key, new->key) != 0)
			tmp = tmp->next;
		if (tmp) /* its update */
		{
			free(tmp->value);
			tmp->value = new->value;
			free(new->key);
			free(new);
			return (1);
		}
		/* its a collision */
		tmp = ht->array[q];
		new->next = tmp;
		ht->array[q] = new;
	}
	return (1);
}
