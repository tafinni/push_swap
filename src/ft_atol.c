/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:15 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:17 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long int	ft_atol(const char *str)
{
	long int	sign;
	long int	result;

	sign = 1;
	result = 0;
	while ((*str < 14 && *str > 8) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{			
		if (str[0] == '-')
			sign = -sign;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str != '\0' && ft_isdigit((int)*str) > 0)
	{
		if ((*str >= 48) && (*str <= 57))
			result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}
