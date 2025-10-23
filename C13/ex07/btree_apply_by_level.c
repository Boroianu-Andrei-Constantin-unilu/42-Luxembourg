#include "ft_btree.h"

typedef struct s_queue
{
	t_btree	*node;
	int		level;
}	t_queue;

static int	max_nodes(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + max_nodes(root->left) + max_nodes(root->right));
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue	*queue;
	int		front;
	int		rear;
	int		size;
	int		last_level;

	if (!root)
		return ;
	size = max_nodes(root);
	queue = (t_queue *)malloc(sizeof(t_queue) * size);
	if (!queue)
		return ;
	front = 0;
	rear = 0;
	last_level = -1;
	queue[rear++] = (t_queue){root, 0};
	while (front < rear)
	{
		t_queue	q = queue[front++];
		if (q.level > last_level)
		{
			last_level = q.level;
			applyf(q.node->item, q.level, 1);
		}
		else
			applyf(q.node->item, q.level, 0);
		if (q.node->left)
			queue[rear++] = (t_queue){q.node->left, q.level + 1};
		if (q.node->right)
			queue[rear++] = (t_queue){q.node->right, q.level + 1};
	}
	free(queue);
}
