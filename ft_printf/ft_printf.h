/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:32:32 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/29 12:33:39 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_int(int number);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_unsigned(unsigned int number);
int	ft_hex(unsigned long long number, int mod);
int	ft_printf(const char *format, ...);

#endif
