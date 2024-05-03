/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/24 17:05:47 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static t_stack	*find_closest(t_stack *stack, int new_num)
{
	t_stack	*buff;

	if (!stack)
		return (NULL);
	buff = stack;
	while (stack && stack->next)
	{
		if (stack->num > new_num && stack->next->num < new_num)
			return (stack->next);
		stack = stack->next;
	}
	return (buff);
}

static void	alloc_b_operations(t_stack *node_a, t_stack *stack_b)
{
	t_stack	*closest;
	int		i;

	i = 0;
	if (node_a->num < findmin_int(stack_b)->num
		|| node_a->num > findmax_int(stack_b)->num)
		closest = findmax_int(stack_b);
	else
		closest = find_closest(stack_b, node_a->num);
	if (closest->order < (ft_lstsize(stack_b) / 2))
		node_a->cost_rb = closest->order;
	else
		node_a->cost_rrb = ft_lstsize(stack_b) - closest->order;
	node_a->cost_rr = ft_smaller_int(node_a->cost_ra, node_a->cost_rb);
	node_a->cost_rrr = ft_smaller_int(node_a->cost_rra, node_a->cost_rrb);
	node_a->cost_ra -= node_a->cost_rr;
	node_a->cost_rra -= node_a->cost_rrr;
	node_a->cost_rb -= node_a->cost_rr;
	node_a->cost_rrb -= node_a->cost_rrr;
	total_cost(node_a);
}

static void	rotate_appropriate(t_stack *cheap, t_stack **a, t_stack **b)
{
	while (--cheap->cost_ra >= 0)
		rotate(a, 'a');
	while (--cheap->cost_rra >= 0)
		rev_rotate(a, 'a');
	while (--cheap->cost_rb >= 0)
		rotate(b, 'b');
	while (--cheap->cost_rrb >= 0)
		rev_rotate(b, 'b');
	while (--cheap->cost_rr >= 0)
		rotate_rr(a, b);
	while (--cheap->cost_rrr >= 0)
		rev_rotate_rr(a, b);
	push(a, b, 'b');
	reset_cost(*a);
}

void	push_it_bro(t_stack **stack_a, t_stack **stack_b, int len_a, int limit)
{
	t_stack	*buff;
	int		i;

	while (len_a > 3)
	{
		i = 0;
		fill_the_order(*stack_a);
		fill_the_order(*stack_b);
		while (i < limit)
		{
			buff = find_node_order(*stack_a, i);
			buff->cost_ra = i;
			alloc_b_operations(buff, *stack_b);
			buff = find_node_order(*stack_a, len_a - i - 1);
			buff->cost_rra = i + 1;
			alloc_b_operations(buff, *stack_b);
			i++;
		}
		buff = find_cheapest(*stack_a);
		rotate_appropriate(buff, stack_a, stack_b);
		len_a--;
		if (len_a < (limit * 2) && len_a % 2)
			limit--;
	}
}
