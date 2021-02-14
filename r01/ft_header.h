/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:15:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/14 17:15:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

int		ft_strlen(char *str);
void	ft_putstr(char *str, int strlen);
void	ft_display(int tab[6][6]);
int		ft_valid_test(int tab[6][6], int line, int column);
int		ft_horizontal_verif(int tab[6][6], int line);
int		ft_recursive_bis(int tab[6][6], int line, int column);
void	ft_main(int ta[6][6]);
void	ft_putchar(char c);

#endif
