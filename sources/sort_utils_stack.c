/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:23:09 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_max(t_link **stack)
{
	t_link	*ptr;
	int		max;

	ptr = *stack;
	max = ptr->num;
	while (ptr != NULL)
	{
		if (max < ptr->num)
			max = ptr->num;
		ptr = ptr->next;
	}
	return (max);
}

int	find_min(t_link **stack)
{
	t_link	*ptr;
	int		min;

	ptr = *stack;
	min = ptr->num;
	while (ptr != NULL)
	{
		if (min > ptr->num)
			min = ptr->num;
		ptr = ptr->next;
	}
	return (min);
}

int	dist_to_top(t_link **stack, int number)
{
	t_link	*ptr;
	int		distance;

	ptr = *stack;
	while (ptr->num != number)
		ptr = ptr->next;
	distance = 0;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		distance++;
	}
	return (distance);
}

int	dist_to_bot(t_link **stack, int number)
{
	t_link	*ptr;
	int		distance;

	ptr = *stack;
	distance = 0;
	while (ptr && ptr->num != number)
	{
		ptr = ptr->next;
		distance++;
	}
	return (distance);
}
