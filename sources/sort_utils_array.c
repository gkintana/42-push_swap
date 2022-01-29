/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/23 19:23:06 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sort_partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
			ft_swap(&array[++i], &array[j]);
		j++;
	}
	ft_swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	part_index;

	if (start < end)
	{
		part_index = sort_partition(array, start, end);
		quick_sort(array, start, part_index - 1);
		quick_sort(array, part_index + 1, end);
	}
}

int	*create_temp_sorted_array(t_link **a, int *array)
{
	t_link	*ptr;
	int		i;

	ptr = *a;
	ft_bzero(array, stack_size(a));
	i = -1;
	while (++i < stack_size(a) && ptr != NULL)
	{
		array[i] = ptr->num;
		ptr = ptr->next;
	}
	quick_sort(array, 0, i - 1);
	return (array);
}
