/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cataloguing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/23 15:12:49 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	total_cost(t_stack *stack)
{
	stack->cost_total = stack->cost_ra + stack->cost_rb;
	stack->cost_total += stack->cost_rra + stack->cost_rrb;
	stack->cost_total += stack->cost_rr + stack->cost_rrr;
}

void	reset_cost(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->cost_ra = 0;
		stack->cost_rb = 0;
		stack->cost_rra = 0;
		stack->cost_rrb = 0;
		stack->cost_rr = 0;
		stack->cost_rrr = 0;
		stack->cost_total = 100;
		stack = stack->next;
	}
}

void	fill_desired_order(t_stack *stack, int l)
{
	t_stack	*no_order;
	t_stack	*buff;
	int		biggest_num;

	while (l != 0)
	{
		buff = stack;
		biggest_num = INT_MIN;
		no_order = NULL;
		while (buff)
		{
			if (buff->num == INT_MIN && buff->final_order < 0)
				buff->final_order = 0;
			else if (buff->num > biggest_num && buff->final_order < 0)
			{
				biggest_num = buff->num;
				no_order = buff;
			}
			else
				buff = buff->next;
		}
		if (no_order)
			no_order->final_order = l - 1;
		l--;
	}
}

void	fill_the_order(t_stack *stack)
{
	int		i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->order = i;
		stack = stack->next;
		i++;
	}
}
