/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_from_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/28 16:20:10 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_alpha_in_str(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isalpha(argv[i++]))
			error();
	}
}

int	count_of_numbers(char *argv, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[i] != '\0')
	{
		while (argv[i] == c)
			i++;
		if (argv[i] != c && argv[i] != '\0')
			count++;
		while (argv[i] != c && argv[i] != '\0')
			i++;
	}
	return (count);
}

t_link	*free_split(char **array, char **argv, t_link *stack)
{
	int	i;

	i = 0;
	while (i < count_of_numbers(argv[1], 32))
		free(array[i++]);
	free(&(*array));
	return (stack);
}

int	find_duplicate_in_split(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (mod_atoi(array[i]) == mod_atoi(array[j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

void	dup_has_been_found(char **array, char **argv, t_link *stack)
{
	if (find_duplicate_in_split(array))
	{
		free_split(array, argv, NULL);
		free(stack);
		error();
	}
}
