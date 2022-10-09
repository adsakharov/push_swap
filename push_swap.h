/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:38:05 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 19:39:29 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pattern
{
	char	type;
	int		rank;
	int		rr;
	int		r;
}	t_pattern;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				ra_score;
	int				rra_score;
	int				rb_score;
	int				rrb_score;
	int				value;
	int				flag;
}	t_stack;

// check_errors.c
char		check_errors(char **array);
char		check_null_args(int argc, char **argv);

// count_rotation_utils.c
int			number_r(t_stack *stack);
int			number_rev_r(t_stack *stack);
int			number_ab(t_stack *stack);
int			number_ba(t_stack *stack);

// count_scores.c
t_pattern	count_scores(t_stack *stack_a, t_stack *stack_b);

// errors.c
int			write_error(char **arguments);

// fill_the_rank.c
t_pattern	fill_the_rank(t_stack *stack);

// final_sort.c
int			find_min_index(t_stack *stack);
void		final_sort(t_stack **stack);

// ft_atoi.c
int			check_space(const char *str);
long int	ft_atoi(const char *nptr);

// ft_split.c
char		**free_char_array(char **char_array);
char		**ft_split(char const *s, char c);

// libft_checker.c
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strcmp(const char *s1, const char *s2);

// libft.c
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);

// lists.c
t_stack		*ft_lst2new(int value, int index);
void		ft_lst2add_back(t_stack **lst, t_stack *new);
void		ft_free2(t_stack **lst);
int			count_size(t_stack *top);
int			ft_isdigit(int c);

// operations1.c
void		do_swap(t_stack **stack, char to_print);
void		do_double_swap(t_stack **stack_a, \
t_stack **stack_b, char to_print);
void		do_push(t_stack **stack1, t_stack **stack2, char to_print);

// operations2.c
void		do_rotation(t_stack **stack, char to_print);
void		do_double_rotation(t_stack **stack1, \
t_stack **stack2, char to_print);
void		do_reverse_rotation(t_stack **stack, char to_print);
void		do_double_reverse_rotation(t_stack **stack1, \
t_stack **stack2, char to_print);

// parser.c
char		**arg_to_array(int argc, char **argv);
t_stack		*fill_the_stack(char **arguments);

// preparations.c
void		prepare_stacks(t_stack **stack_a, t_stack **stack_b);

// push1.c
void		do_a_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);
void		do_b_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);
void		do_c_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);
void		do_d_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);
void		do_e_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);

// push2.c
void		do_f_type(t_stack **stack_a, t_stack **stack_b, \
t_pattern best_node);
void		push(t_stack **stack_a, t_stack **stack_b, t_pattern best_node);

#endif
