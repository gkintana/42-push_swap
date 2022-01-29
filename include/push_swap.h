/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:09:31 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/28 14:25:28 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*-------------------------- STDOUT & IDENTIFIERS ---------------------------*/
# define SWAP_A			"sa\n"
# define SWAP_B			"sb\n"
# define SWAP_AB		"ss\n"
# define PUSH_A			"pa\n"
# define PUSH_B			"pb\n"
# define ROTATE_A		"ra\n"
# define ROTATE_B		"rb\n"
# define ROTATE_AB		"rr\n"
# define REVERSE_A		"rra\n"
# define REVERSE_B		"rrb\n"
# define REVERSE_AB		"rrr\n"
# define ERROR			"Error\n"

# define STACK_A		1
# define STACK_B		2
# define TRUE			1
# define FALSE			0
# define FD				1

/*-------------------------------- LIBRARIES --------------------------------*/
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*---------------------------- PROGRAM STRUCTURE ----------------------------*/
typedef struct s_link
{
	int				num;
	struct s_link	*next;
}				t_link;

/*--------------------------- FUNCTION PROTOTYPES ---------------------------*/
void	find_alpha(int argc, char **argv);
void	find_alpha_in_str(char *argv);
void	find_duplicate(char **argv);
int		find_duplicate_in_split(char **array);
void	dup_has_been_found(char **array, char **argv, t_link *stack);
int		count_of_numbers(char *argv, char c);
long	mod_atoi(const char *nptr);
t_link	*free_split(char **array, char **argv, t_link *stack);
t_link	*create_stack(int argc, char **argv);
t_link	*create_stack_from_str(char **argv);
void	free_stack(t_link **a);
void	free_stacks(t_link **a, t_link **b);
void	error(void);

void	sa_sb(t_link **stack, int a_or_b, int print_stdout);
void	ra_rb(t_link **stack, int a_or_b, int print_stdout);
void	rra_rrb(t_link **stack, int a_or_b, int print_stdout);
void	pa(t_link **a, t_link **b);
void	pb(t_link **a, t_link **b);
void	ss(t_link **a, t_link **b);
void	rr(t_link **a, t_link **b);
void	rrr(t_link **a, t_link **b);

t_link	*top_of_stack(t_link **node);
int		is_sorted(t_link **stack);
int		stack_size(t_link **stack);
int		find_max(t_link **stack);
int		find_min(t_link **stack);
int		dist_to_top(t_link **stack, int number);
int		dist_to_bot(t_link **stack, int number);
int		*create_temp_sorted_array(t_link **a, int *array);

void	sort_three(t_link **a, int being_used);
void	sort_five(t_link **a, t_link **b);
void	sort_one_hundred(t_link **a, t_link **b);
void	sort_five_hundred(t_link **a, t_link **b);

#endif
