/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:23:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	send_to_b(t_link **a, t_link **b, int *array, int num)
{
	while (stack_size(b) != num)
	{
		if (top_of_stack(a)->num >= array[num]
			&& *b && top_of_stack(b)->num != find_max(b)
			&& dist_to_top(b, find_max(b)) < dist_to_bot(b, find_max(b)))
			rr(a, b);
		else if (top_of_stack(a)->num >= array[num])
			ra_rb(a, STACK_A, TRUE);
		if (top_of_stack(a)->num < array[num])
			pb(a, b);
	}
}

static void	return_to_a(t_link **a, t_link **b)
{
	int	reverse;

	reverse = 0;
	while (stack_size(b) != 0)
	{
		if (top_of_stack(b)->num == find_max(b))
			pa(a, b);
		else if (top_of_stack(b)->num == find_min(b))
		{
			pa(a, b);
			ra_rb(a, STACK_A, TRUE);
			reverse++;
		}
		while (*b && top_of_stack(b)->num != find_max(b)
			&& top_of_stack(b)->num != find_min(b))
		{
			if (dist_to_top(b, find_max(b)) < dist_to_bot(b, find_max(b)))
				ra_rb(b, STACK_B, TRUE);
			else
				rra_rrb(b, STACK_B, TRUE);
		}
	}
	while (reverse--)
		rra_rrb(a, STACK_A, TRUE);
}

void	sort_one_hundred(t_link **a, t_link **b)
{
	int	array[100];
	int	i;

	if (is_sorted(a))
		free_stack(a);
	create_temp_sorted_array(a, array);
	i = stack_size(a);
	send_to_b(a, b, array, i * 0.35);
	send_to_b(a, b, array, i * 0.50);
	send_to_b(a, b, array, i * 0.60);
	send_to_b(a, b, array, i * 0.70);
	send_to_b(a, b, array, i * 0.80);
	send_to_b(a, b, array, i * 0.90);
	while (*a)
		pb(a, b);
	return_to_a(a, b);
}

void	sort_five_hundred(t_link **a, t_link **b)
{
	int	array[1000];
	int	i;

	if (is_sorted(a))
		free_stack(a);
	create_temp_sorted_array(a, array);
	i = stack_size(a);
	send_to_b(a, b, array, i * 0.18);
	send_to_b(a, b, array, i * 0.27);
	send_to_b(a, b, array, i * 0.36);
	send_to_b(a, b, array, i * 0.45);
	send_to_b(a, b, array, i * 0.54);
	send_to_b(a, b, array, i * 0.63);
	send_to_b(a, b, array, i * 0.72);
	send_to_b(a, b, array, i * 0.81);
	send_to_b(a, b, array, i * 0.90);
	send_to_b(a, b, array, i * 0.94);
	send_to_b(a, b, array, i * 0.98);
	while (*a)
		pb(a, b);
	return_to_a(a, b);
}
