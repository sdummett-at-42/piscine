/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:59:22 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/06 14:13:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../ft_list.h"
t_list	*ft_list_push_strs(int size, char **strs);

void	ft_list_clear(t_list *begin_list/*, void (*free_fct)(void *)*/)
{
	t_list	*elem;
	t_list	*last_elem;

	elem = begin_list;
	while (elem)
	{
		free_fct(elem->data);
		last_elem = elem;
		elem = elem->next;
		free(last_elem);
	}
}
