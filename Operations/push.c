/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/29 17:26:06 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static void	lst_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*buffer_node;

	if (*stack_src == NULL || stack_src == NULL)
		return ;
	buffer_node = *stack_src;
	buffer_node->prev = NULL;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	if (*stack_dst)
	{
		(*stack_dst)->prev = buffer_node;
		buffer_node->next = *stack_dst;
		*stack_dst = buffer_node;
	}
	else
	{
		*stack_dst = buffer_node;
		(*stack_dst)->next = NULL;
	}
}

void	push(t_stack **stack_src, t_stack **stack_dst, char name_dst)
{
	lst_push(stack_src, stack_dst);
	ft_printf("p%c\n", name_dst);
}
