/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/23 14:02:30 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

t_stack	*find_node_order(t_stack *stack, int order)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->order == order)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheap_node;
	int		lowcost;

	lowcost = INT_MAX;
	cheap_node = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cost_total < lowcost)
		{
			lowcost = stack->cost_total;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	return (cheap_node);
}

t_stack	*findmin_int(t_stack *stack)
{
	t_stack	*min_node;
	int		min;

	min = INT_MAX;
	min_node = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*findmax_int(t_stack *stack)
{
	t_stack	*max_node;
	int		max;

	max = INT_MIN;
	max_node = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
