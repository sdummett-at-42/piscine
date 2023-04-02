/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:27:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/08 22:30:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		btree_apply_suffix(root->left, applyf);
		btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}
