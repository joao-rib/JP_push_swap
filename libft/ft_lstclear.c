/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/15 13:23:57 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*buff;

	if (lst)
	{
		while (*lst)
		{
			buff = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = buff;
		}
		ft_lstdelone(*lst);
		*lst = NULL;
	}
}
