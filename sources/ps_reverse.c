/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:22:50 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra_rrb(t_link **stack, int a_or_b, int print_stdout)
{
	t_link	*new_top;
	t_link	*old_top;

	old_top = *stack;
	new_top = *stack;
	while (old_top->next != NULL)
		old_top = old_top->next;
	old_top->next = *stack;
	*stack = new_top->next;
	new_top->next = NULL;
	if (print_stdout == TRUE)
	{
		if (a_or_b == STACK_A)
			ft_putstr_fd(REVERSE_A, FD);
		else if (a_or_b == STACK_B)
			ft_putstr_fd(REVERSE_B, FD);
	}
}

void	rrr(t_link **a, t_link **b)
{
	rra_rrb(a, STACK_A, FALSE);
	rra_rrb(b, STACK_B, FALSE);
	ft_putstr_fd(REVERSE_AB, FD);
}
