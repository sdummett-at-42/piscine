/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:53:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 12:30:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*following;
	t_list	*tmp;

	curr = *begin_list;
	if (curr->next)
	{
		following = curr->next;
		curr->next = 0;
		tmp = following->next;
		while (following->next)
		{
			following->next = curr;
			curr = following;
			following = tmp;
			if (tmp->next)
				tmp = tmp->next;
		}
		following->next = curr;
		*begin_list = following;
	}
}
