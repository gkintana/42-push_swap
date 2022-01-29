/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:22:48 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_link	*top_of_stack(t_link **stack)
{
	t_link	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_link	*remove_top(t_link **node)
{
	if (!(*node)->next)
		return (NULL);
	ra_rb(node, STACK_A, FALSE);
	return ((*node)->next);
}

void	pa(t_link **a, t_link **b)
{
	t_link	*ptr;

	if (!*b)
		return ;
	ptr = top_of_stack(b);
	*b = remove_top(b);
	ptr->next = *a;
	*a = ptr;
	rra_rrb(a, STACK_A, FALSE);
	ft_putstr_fd(PUSH_A, FD);
}

void	pb(t_link **a, t_link **b)
{
	t_link	*ptr;

	if (!*a)
		return ;
	ptr = top_of_stack(a);
	*a = remove_top(a);
	ptr->next = *b;
	*b = ptr;
	rra_rrb(b, STACK_B, FALSE);
	ft_putstr_fd(PUSH_B, FD);
}
