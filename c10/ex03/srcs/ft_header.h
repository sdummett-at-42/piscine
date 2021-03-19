/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:38:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/19 01:59:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putbuf(char *str, int ret);
void	*ft_print_memory(void *addr, unsigned int size);

#endif
