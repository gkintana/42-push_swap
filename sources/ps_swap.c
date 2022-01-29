/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:22:55 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa_sb(t_link **stack, int a_or_b, int print_stdout)
{
	t_link	*top;
	t_link	*second;

	top = *stack;
	while (top->next != NULL)
	{
		second = top;
		top = top->next;
	}
	ft_swap(&top->num, &second->num);
	if (print_stdout == TRUE)
	{
		if (a_or_b == STACK_A)
			ft_putstr_fd(SWAP_A, FD);
		else if (a_or_b == STACK_B)
			ft_putstr_fd(SWAP_B, FD);
	}
}

void	ss(t_link **a, t_link **b)
{
	sa_sb(a, STACK_A, FALSE);
	sa_sb(b, STACK_B, FALSE);
	ft_putstr_fd(SWAP_AB, FD);
}
