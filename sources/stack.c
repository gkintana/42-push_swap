/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/28 14:23:51 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long	mod_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]))
		num = (num * 10) + (nptr[i++] - 48);
	if (num == 2147483648 && sign == -1)
		return (INT_MIN);
	else if (num < INT_MIN || num > INT_MAX)
		error();
	return (sign * num);
}

t_link	*create_stack(int argc, char **argv)
{
	t_link	*stack;
	t_link	*node;
	int		i;

	find_alpha(argc, argv);
	find_duplicate(argv);
	node = (t_link *)malloc(sizeof(t_link));
	if (!node)
		return (NULL);
	stack = node;
	i = argc - 1;
	node->num = mod_atoi(argv[i--]);
	while (i > 0)
	{
		node->next = (t_link *)malloc(sizeof(t_link));
		if (!node->next)
			return (NULL);
		node = node->next;
		node->num = mod_atoi(argv[i--]);
	}
	node->next = NULL;
	return (stack);
}

t_link	*create_stack_from_str(char **argv)
{
	t_link	*stack;
	t_link	*node;
	char	**array;
	int		i;

	find_alpha_in_str(argv[1]);
	node = (t_link *)malloc(sizeof(t_link));
	if (!node)
		return (NULL);
	stack = node;
	i = count_of_numbers(argv[1], 32);
	array = ft_split(argv[1], 32);
	dup_has_been_found(array, argv, stack);
	node->num = mod_atoi(array[--i]);
	while (i > 0)
	{
		node->next = (t_link *)malloc(sizeof(t_link));
		if (!node->next)
			return (NULL);
		node = node->next;
		node->num = mod_atoi(array[--i]);
	}
	node->next = NULL;
	return (free_split(array, argv, stack));
}

int	is_sorted(t_link **stack)
{
	t_link	*ptr;

	ptr = *stack;
	while (ptr->next != NULL)
	{
		if (ptr->num < ptr->next->num)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int	stack_size(t_link **stack)
{
	t_link	*ptr;
	int		count;

	ptr = *stack;
	count = 0;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
