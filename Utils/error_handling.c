/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/29 18:12:58 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

bool	int_errors(char *str)
{
	int		i;

	i = 1;
	if (str[0] != '+' && str[0] != '-' && !(str[0] >= 48 && str[0] <= 57))
		return (true);
	if ((str[0] == '+' || str[0] == '-') && !(str[1] >= 48 && str[1] <= 57))
		return (true);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (true);
		i++;
	}
	return (false);
}

void	error_exit(t_stack **stack)
{
	ft_lstclear(stack);
	ft_printf("Error\n");
	exit(1);
}
