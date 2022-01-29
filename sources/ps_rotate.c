/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:22:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra_rb(t_link **stack, int a_or_b, int print_stdout)
{
	t_link	*old_top;
	t_link	*new_top;

	old_top = *stack;
	while (old_top->next != NULL)
	{
		new_top = old_top;
		old_top = old_top->next;
	}
	new_top->next = NULL;
	old_top->next = *stack;
	*stack = old_top;
	if (print_stdout == TRUE)
	{
		if (a_or_b == STACK_A)
			ft_putstr_fd(ROTATE_A, FD);
		else if (a_or_b == STACK_B)
			ft_putstr_fd(ROTATE_B, FD);
	}
}

void	rr(t_link **a, t_link **b)
{
	ra_rb(a, STACK_A, FALSE);
	ra_rb(b, STACK_B, FALSE);
	ft_putstr_fd(ROTATE_AB, FD);
}
