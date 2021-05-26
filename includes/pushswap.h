#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DEBUG 1
# define BATCHSIZE 50

typedef struct s_a {
	int		ac;
	char	**av;
	int		lst_len;
	char	**raw_str;
	int		*lst;
	int		sep;
	int		med;
	int		minpos;
	int		minval;
	int		maxpos;
	int		maxval;
	int		strat_tab[4];
	int		strat;
	int		ramember;
	int		*quantile;
	int		numquant;
	int		opcount;
}				t_a;

//utils
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *nptr);
void	ft_initstruct(t_a *a, int ac, char **av);
int		is_insep(char c, char *sep);
int		ft_wrdlen(char *str, char *sep);
int		ft_wcount(char *str, char *sep);
char	*ft_wrdcpy(char *src, int wlen);
char	**ft_split(char *str, char *charset);
void	ft_freesplit(char **str);
char	*ft_strdup(char *s);
void	ft_cleanexit(t_a *a, char *exit_message, int fd);

//debug -- utilise printf
void	ft_printlist(t_a *a);

//Parser
void	ft_parser(t_a *a);

//Sort
void	ft_sort(t_a *a);
void	ft_med(t_a *a, int init, int end);
void	ft_minpos(t_a *a, int init, int end);
void	ft_maxpos(t_a *a, int init, int end);
void	ft_move_right(t_a *a, int val_min, int val_max, int num);

//Swappers
void	ft_sa(t_a *a);
void	ft_sb(t_a *a);
void	ft_ss(t_a *a);
void	ft_pa(t_a *a);
void	ft_pb(t_a *a);
void	ft_ra(t_a *a);
void	ft_rb(t_a *a);
void	ft_rr(t_a *a);
void	ft_rra(t_a *a);
void	ft_rrb(t_a *a);
void	ft_rrr(t_a *a);

#endif