/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/29 17:26:14 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static void	lst_rev_rotate(t_stack **stack)
{
	int		l;
	t_stack	*last_node;

	l = ft_lstsize(*stack);
	if (*stack == NULL || stack == NULL || l == 1)
		return ;
	last_node = ft_lstlast(*stack);
	(*stack)->prev = last_node;
	last_node->next = *stack;
	*stack = last_node;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	lst_rev_rotate(stack_a);
	lst_rev_rotate(stack_b);
	ft_printf("rrr\n");
}

void	rev_rotate(t_stack **stack, char stack_name)
{
	lst_rev_rotate(stack);
	ft_printf("rr%c\n", stack_name);
}
