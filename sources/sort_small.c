/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:23:04 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	conditions(t_link **a, t_link *top, t_link *mid)
{
	if (top->num > (*a)->num && mid->num > (*a)->num)
	{
		if (top->num > mid->num && mid->num > (*a)->num)
			sa_sb(a, STACK_A, TRUE);
		rra_rrb(a, STACK_A, TRUE);
	}
	if (mid->num > (*a)->num)
	{
		sa_sb(a, STACK_A, TRUE);
		ra_rb(a, STACK_A, TRUE);
	}	
	else if (top->num > mid->num && mid->num < (*a)->num)
	{
		if (top->num > (*a)->num)
			ra_rb(a, STACK_A, TRUE);
		else
			sa_sb(a, STACK_A, TRUE);
	}
	else if (top->num > (*a)->num)
		sa_sb(a, STACK_A, TRUE);
}

void	sort_three(t_link **a, int being_used)
{		
	t_link	*top;
	t_link	*mid;

	if (is_sorted(a) && !being_used)
		free_stack(a);
	top = *a;
	while (top->next != NULL)
	{
		mid = top;
		top = top->next;
	}
	conditions(a, top, mid);
}

static void	send_min_to_b(t_link **a, t_link **b)
{
	int	node;

	node = 0;
	while (node++ < 5 && top_of_stack(a)->num != find_min(a))
	{
		if (dist_to_top(a, find_min(a)) > 3)
			rra_rrb(a, STACK_A, TRUE);
		else
			ra_rb(a, STACK_A, TRUE);
	}
	pb(a, b);
}

void	sort_five(t_link **a, t_link **b)
{
	if (is_sorted(a))
		free_stack(a);
	if (stack_size(a) == 5)
		send_min_to_b(a, b);
	send_min_to_b(a, b);
	sort_three(a, 1);
	pa(a, b);
	pa(a, b);
}
