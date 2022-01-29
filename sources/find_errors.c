/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/28 12:36:22 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_alpha(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j++]))
				error();
		}
		i++;
	}
}

void	find_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				error();
			j++;
		}
		i++;
	}
}

void	free_stack(t_link **a)
{
	t_link	*ptr;

	while (*a != NULL)
	{
		ptr = *a;
		*a = (*a)->next;
		free(ptr);
	}
	exit(EXIT_FAILURE);
}

void	free_stacks(t_link **a, t_link **b)
{
	t_link	*ptr;

	while (*a != NULL)
	{
		ptr = *a;
		*a = (*a)->next;
		free(ptr);
	}	
	while (*b != NULL)
	{
		ptr = *b;
		*b = (*b)->next;
		free(ptr);
	}
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	ft_putstr_fd(ERROR, FD);
	exit(EXIT_FAILURE);
}
