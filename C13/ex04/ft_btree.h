/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/23 17:39:05 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

/* ex00 */
t_btree	*btree_create_node(void *item);

/* ex01 */
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

/* ex02 */
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));

/* ex03 */
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

/* ex04 */
void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *));

/* ex05 */
void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *));

/* ex06 */
int		btree_level_count(t_btree *root);

/* ex07 */
void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem));

#endif