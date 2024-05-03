/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/23 14:57:57 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static t_stack	*find_nearest(t_stack *stack, int new_num)
{
	t_stack	*buff;

	if (!stack)
		return (NULL);
	buff = stack;
	while (stack && stack->next)
	{
		if (stack->num < new_num && stack->next->num > new_num)
			return (stack->next);
		stack = stack->next;
	}
	return (buff);
}

static void	alloc_a_operations(t_stack *stack_a, t_stack *node_b)
{
	t_stack	*nearest;
	int		i;

	i = 0;
	if (node_b->num < findmin_int(stack_a)->num
		|| node_b->num > findmax_int(stack_a)->num)
		nearest = findmin_int(stack_a);
	else
		nearest = find_nearest(stack_a, node_b->num);
	if (nearest->order < (ft_lstsize(stack_a) / 2))
		node_b->cost_ra = nearest->order;
	else
		node_b->cost_rra = ft_lstsize(stack_a) - nearest->order;
}

static void	rotate_again(t_stack **stack_a, int ra, int rra)
{
	while (--ra >= 0)
		rotate(stack_a, 'a');
	while (--rra >= 0)
		rev_rotate(stack_a, 'a');
	return ;
}

void	push_it_again(t_stack **stack_a, t_stack **stack_b)
{
	int		len_b;

	len_b = ft_lstsize(*stack_b);
	while (len_b > 0)
	{
		fill_the_order(*stack_a);
		fill_the_order(*stack_b);
		if ((*stack_b)->final_order != (*stack_a)->final_order - 1)
		{
			alloc_a_operations(*stack_a, *stack_b);
			rotate_again(stack_a, (*stack_b)->cost_ra, (*stack_b)->cost_rra);
		}
		push(stack_b, stack_a, 'a');
		len_b--;
	}
	fill_the_order(*stack_a);
}
