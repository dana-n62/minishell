/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:02:18 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/29 09:46:30 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

void	print_char(unsigned int c, int *size);
void	print_str(char *str, int *size);
void	print_number(int number, int *size);
void	print_unsigned(int val_unsigned, int *size);
void	print_hexa(unsigned long number, char id, int *size);
void	print_pointer(unsigned long value, int *size);
int		ft_printf(const char *string, ...);
#endif
