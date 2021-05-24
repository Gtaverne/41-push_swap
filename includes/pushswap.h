#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_a {
	int		ac;
	char	**av;
	int		*lst;
	int		sep;
}				t_a;

//utils
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(const char *nptr);
void	ft_initstruct(t_a *a, int ac, char **av);

//Basics
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