/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/29 17:26:29 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static void	lst_swap(t_stack **stack)
{
	int	l;

	l = ft_lstsize(*stack);
	if (*stack == NULL || stack == NULL || l == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	lst_swap(stack_a);
	lst_swap(stack_b);
	ft_printf("ss\n");
}

void	swap(t_stack **stack, char stack_name)
{
	lst_swap(stack);
	ft_printf("s%c\n", stack_name);
}
