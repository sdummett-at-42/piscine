/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:38:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/20 16:42:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

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
void	putaddr_inhex(long int addr);
int	ft_memcmp(const void *b1, const void *b2, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
