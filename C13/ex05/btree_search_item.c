/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/23 17:36:42 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
	void *found = btree_search_item(root->left, data_ref, cmpf);

	if (!root) {
		return 0;
	}
	
	if (found) {
		return found;
	}
	if (cmpf(root->item, data_ref) == 0) {
		return (root->item);
	}
	return btree_search_item(root->right, data_ref, cmpf);
}