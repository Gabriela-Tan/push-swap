/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:09:51 by gabtan            #+#    #+#             */
/*   Updated: 2023/05/30 10:12:11 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		ft_error();
	return (sign * result);
}
