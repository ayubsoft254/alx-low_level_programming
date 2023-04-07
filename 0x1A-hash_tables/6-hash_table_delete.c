#include "hash_tables.h"

void free_node(hash_node_t *);

/**
 * hash_table_delete - delete a hash table
 * @ht: the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int p = 0;

	if (!ht)
		return;
	while (p < ht->size)
	{
		free_node(ht->array[p]);
		p++;
	}
	free(ht->array);
	free(ht);
}

/**
 * free_node - frees a node
 * @n: node pointer
 */
void free_node(hash_node_t *n)
{
	hash_node_t *tmp;

	while (n)
	{
		tmp = n->next;
		free(n->value);
		free(n->key);
		free(n);
		n = tmp;
	}
}
