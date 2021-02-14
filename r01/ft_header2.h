/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:15:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/14 17:15:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER2_H
# define FT_HEADER2_H

void	ft_display(int tab[6][6]);
void	ft_putstr(char *str, int strlen);
void	ft_putchar(char c);
int		ft_valid_test(int tab[6][6], int line, int column);
void	ft_recursive(int tab[6][6], int line, int column);
int		ft_vertical_verif(int tab[6][6], int column);

#endif
