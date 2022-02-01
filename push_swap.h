#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define N 200000
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long long		value;
	int				pos;
	int				flag;
	struct s_list	*next;
}					t_list;

typedef struct s_next
{
	int		save_argc;
	int		flag;
	int		next_el;
	int		save_flag_in_a;
	int		save_flag_in_b;
	int		pos_nextel_b;
	int		size_stack_b;
	int		max_a;
	int		max_b;
	int		mid_a;
	int		mid_b;
	int		push_more;
	int		push_less;
	char	*fin_str;
}				t_next;

int			main(int argc, char **argv);
//libft
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
int			ft_strlen(char *str);
char		*ft_substr(char *s, int start, int len);
long long	ft_atoi(char *str);
//errors
void		error_search(int argc, char **argv, t_list **stack_a, int check);
int			error_intmax(t_list **stack_a);
int			error_numstr(int argc, char **argv);
int			error_sortlist(t_list **stack_a);
int			error_dublicat(t_list **stack_a);
void		error_command(int n, char **array);
//algorithms
void		sel_alg(int argc, t_list **stack_a, t_list **stack_b, t_next *next);
void		alg23(t_next *next, t_list **stack_a);
void		alg45(t_next *next, t_list **stack_a, t_list **stack_b);
void		algbig(t_next *next, t_list **stack_a, t_list **stack_b);
void		scnd_algbig(t_next *next, t_list **stack_a, t_list **stack_b);
void		frst_algbig(t_next *next, t_list **stack_a, t_list **stack_b);
//utils for algbig
void		push_in_b(t_next *next, t_list **stack_a, t_list **stack_b);
void		push_a_frst_alg(t_next *next, t_list **stack_a, t_list **stack_b);
void		push_in_a_frst(t_next *next, t_list **stack_b, t_list **stack_a);
void		push_in_a_scnd(t_next *next, t_list **stack_b, t_list **stack_a);
void		prt1_frst(t_next *next, t_list **stack_a, t_list **stack_b);
void		prt2_frst(t_next *next, t_list **stack_a, t_list **stack_b);
int			check_swap(t_next *next, t_list **stack_a, t_list **stack_b);
//commands
void		ft_pa(t_next *next, t_list **stack_b, t_list **stack_a);
void		ft_pb(t_next *next, t_list **stack_a, t_list **stack_b);
void		ft_ra(t_next *next, t_list **stack_a);
void		ft_rb(t_next *next, t_list **stack_b);
void		ft_rr(t_next *next, t_list **stack_a, t_list **stack_b);
void		ft_rra(t_next *next, t_list **stack_a, int check);
void		ft_rrb(t_next *next, t_list **stack_b, int check);
void		ft_rrr(t_next *next, t_list **stack_a, t_list **stack_b);
void		ft_sa(t_next *next, t_list **stack_a);
void		ft_sb(t_next *next, t_list **stack_b);
void		ft_ss(t_next *next, t_list **stack_a, t_list **stack_b);
//utils function
int			stack_counter(t_list **stack);
void		*delete_elem(t_list **stack_a);
int			check_flags(t_list **stack_a);
int			check_posit_a(int mid, t_list **stack);
int			check_posit_b(int mid, t_list **stack);
int			search_pos_next_in_b(t_next *next, t_list **stack_b);
int			check_last_flag_in_a(t_list **stack_a);
int			search_max_a(t_list **stack_a);
void		fill_flags(t_next *next, t_list **stack_b);
int			search_mid_a(t_next *next, t_list **stack_a);
//other
void		*add_item(t_list **stack_a, long long num);
void		ft_free(t_list **stack);
void		print_sortlist(t_next *next);
void		save_finish_str(t_next *next, char *str);
void		make_sort_position(int argc, t_list **stack_a);
//bonus
void		ft_pb_bonus(t_list **stack_a, t_list **stack_b);
void		ft_pa_bonus(t_list **stack_b, t_list **stack_a);
void		ft_ra_bonus(t_list **stack_a);
void		ft_rb_bonus(t_list **stack_b);
void		ft_rr_bonus(t_list **stack_a, t_list **stack_b);
void		ft_rra_bonus(t_list **stack_a);
void		ft_rrb_bonus(t_list **stack_b);
void		ft_rrr_bonus(t_list **stack_a, t_list **stack_b);
void		ft_sa_bonus(t_list **stack_a);
void		ft_sb_bonus(t_list **stack_b);
void		ft_ss_bonus(t_list **stack_a, t_list **stack_b);
void		exec_cmd(int n, t_list **stack_a, t_list **stack_b, char **array);

#endif
