#include "../includes/pushswap.h"


void	ft_move_right_until_min(t_a *a)
{
	while (a->lst[a->sep - 1] > a->minval)
	{
		ft_pb(a);
	}
}

void	ft_cut_and_sort_right(t_a *a)
{
	int	i;
	int	k;
	
	ft_med(a, a->sep, a->lst_len - 1);
	ft_maxpos(a, a->sep, a->lst_len);
	ft_minpos(a, a->sep, a->lst_len);
	//printf("Juste avant move left\n");
	//ft_printlist(a);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	//printf("Juste apres move left\n");
	//ft_printlist(a);
	i = 0;
	k = a->lst_len - a->sep;
	while (i < k)
	{
		ft_findstrat(a);
		ft_runstrat(a);
		i++;
	}
	//ft_printlist(a);
	k = a->med;
	i = a->lst_len - 1;
	ft_med(a, 0, a->lst_len - 1);
	ft_move_right(a, k, a->med, (1 + a->lst_len) / 2);	
	//ft_printlist(a);
	i = 0;
	k = a->lst_len - a->sep;
	while (i < k)
	{
		ft_findstrat(a);
		ft_runstrat(a);
		i++;
	}
}

void	ft_cut_and_sort_right_2(t_a *a)
{
	int	i;
	int	k;
	
	ft_med(a, a->sep, a->lst_len - 1);
	ft_maxpos(a, a->sep, a->lst_len);
	ft_minpos(a, a->sep, a->lst_len);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	//printf("Juste apres move left\n");
	//ft_printlist(a);
	i = 0;
	k = a->lst_len - a->sep;
	while (i < k)
	{
		ft_findstrat(a);
		ft_runstrat(a);
		i++;
	}
	while (a->ramember-- > 0)
		ft_ra(a);
	//ft_printlist(a);
	k = a->med;
	i = a->lst_len - 1;
	ft_med(a, 0, a->lst_len - 1);
	ft_minpos(a, 0, a->lst_len);
	ft_move_right_until_min(a);
	//printf("WE MOVED RIGHT UNTIL MIN\n");
	//ft_printlist(a);
	i = 0;
	k = a->lst_len - a->sep;
	while (i < k)
	{
		ft_findstrat(a);
		ft_runstrat(a);
		i++;
	}
	while (a->ramember-- + 1 > 0)
		ft_ra(a);
}

void	ft_sort_long_chain(t_a *a)
{
	//printf("Juste avant move right 1\n");
	//ft_printlist(a);
	ft_move_right(a, a->minval, a->med, a->lst_len);
	ft_cut_and_sort_right(a);
	while (a->ramember-- > 0)
		ft_ra(a);
	//printf("ABOUT TO MOVE RIGHT\n");
	//ft_printlist(a);
	ft_move_right_until_min(a);
	//printf("WE MOVED RIGHT UNTIL MIN\n");
	//ft_printlist(a);
	ft_cut_and_sort_right_2(a);
	
	ft_printlist(a);
}