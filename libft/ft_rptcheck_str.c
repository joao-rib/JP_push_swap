/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rptcheck_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/16 14:41:58 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

bool	ft_rptcheck_str(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[j])
		{
			if (ft_str_cmp(str[i], str[j]))
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}
