/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/28 16:41:32 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	has_delimiter(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	t_link	*stack_b;
	int		size;

	if (argc < 2 || (argc == 2 && count_of_numbers(argv[1], 32) < 2))
		exit(EXIT_FAILURE);
	if (argc > 2 && has_delimiter(argc, argv))
		error();
	if (argc == 2)
		stack_a = create_stack_from_str(argv);
	else
		stack_a = create_stack(argc, argv);
	stack_b = NULL;
	size = stack_size(&stack_a);
	if (size > 100 && size <= 1000)
		sort_five_hundred(&stack_a, &stack_b);
	else if (size > 5 && size <= 100)
		sort_one_hundred(&stack_a, &stack_b);
	else if (size == 4 || size == 5)
		sort_five(&stack_a, &stack_b);
	else if (size == 2 || size == 3)
		sort_three(&stack_a, 0);
	free_stacks(&stack_a, &stack_b);
}
