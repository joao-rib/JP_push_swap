/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/03 11:12:47 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/push_swap.h"

static void	sort_it_out(t_stack **stack_a, t_stack **stack_b)
{
	reset_cost(*stack_a);
	if (!check_sort(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			swap(stack_a, 'a');
		else if (ft_lstsize(*stack_a) == 3)
			sort_three(stack_a, 'a');
		else
			sort_all(stack_a, stack_b);
	}
}

static void	fill_the_stack(char **argv, t_stack **stack)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (int_errors(argv[i]))
			error_exit(stack);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_exit(stack);
		if (*stack == NULL)
			*stack = ft_lstnew_int(n);
		else
			ft_lstadd_back(stack, ft_lstnew_int(n));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**av;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		return (ft_printf("Error\n"));
	if (argc == 2 && ft_strchr(argv[1], ' '))
		av = ft_split(argv[1], ' ');
	else
		av = argv + 1;
	if (!av)
		return (ft_printf("Error\n"));
	if (ft_rptcheck_str(av))
		return (ft_printf("Error\n"));
	fill_the_stack(av, &stack_a);
	fill_the_order(stack_a);
	fill_desired_order(stack_a, ft_lstsize(stack_a));
	sort_it_out(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
