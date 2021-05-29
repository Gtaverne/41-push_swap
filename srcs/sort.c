#include "../includes/pushswap.h"

void	ft_findstrat(t_a *a)
{
	int i;
	/*In col b
	0- Find min, rb it to the top, pa it, ra it
	1- Find min, rrb it to the top, pa it, ra it
	2- Find max, rb it to the top, pa it
	3- Find max, rrb it to the top, pa it
	*/
	ft_minpos(a, a->sep, a->lst_len);
	ft_maxpos(a, a->sep, a->lst_len);
	a->strat_tab[0] = 2 + (a->minpos - a->sep);
	a->strat_tab[1] = 2 + (a->lst_len - a->minpos);
	a->strat_tab[2] = 1 + (a->maxpos - a->sep);
	a->strat_tab[3] = 1 + (a->lst_len - a->maxpos);
	i = 1;
	a->strat = 0;
	while (i < 4)
	{
		if (a->strat_tab[i] < a->strat_tab[a->strat] + a->strat / 2)
			a->strat = i;
		i++;
	}
	//ft_printlist(a);
	//printf("Here is the strat : %d and its value %d\n", a->strat, a->strat_tab[a->strat]);
}

void	ft_runstrat(t_a *a)
{
	int	i;

	i = -1;
	if (a->strat == 0)
		ft_strat_zero(a);
	else if (a->strat == 1)
		ft_strat_one(a);
	else if (a->strat == 2)
		ft_strat_two(a);
	else if (a->strat == 3)
		ft_strat_three(a);	
}

void	ft_initializer(t_a *a)
{
	a->sep = a->lst_len;
	ft_med(a, 0, a->lst_len - 1);
	ft_minpos(a, 0, a->lst_len);
	ft_maxpos(a, 0, a->lst_len);
	//ft_printlist(a);
	//printf("Voici la situation initiale\n*****************************\n");
}

void	ft_sort(t_a *a)
{
	int	i;
	int	k;

	ft_initializer(a);
	
	if (a->lst_len <= 10)
		ft_sort_short_chain(a);
	if (a->lst_len < SPLITTER)
	{
		ft_move_right(a, a->minval, a->med, a->lst_len);
		i = 0;
		k = a->lst_len - a->sep;
		while (i < k)
		{
			ft_findstrat(a);
			ft_runstrat(a);
			i++;
		}
		while (a->ramember-- + a->use_rr > 0)
			ft_ra(a);
		ft_minpos(a, 0, a->lst_len);
		ft_maxpos(a, 0, a->lst_len);
		ft_move_right(a, a->med, a->maxval, a->lst_len - a->minpos - 1);
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
	//	printf("_____________\nthe end\n");
		ft_minpos(a, 0, a->lst_len);
		ft_maxpos(a, 0, a->lst_len);
		//ft_printlist(a);
		return ;
	}
	else
		ft_sort_long_chain(a);
}

/*
void	ft_sort(t_a *a)
{
		ft_move_right(a, a->minval, a->med, a->lst_len);
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
		
		ft_minpos(a, 0, a->lst_len);
		ft_maxpos(a, 0, a->lst_len);
		ft_move_right(a, a->med, a->maxval, a->lst_len - a->minpos - 1);
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
		//printf("_____________\nthe end\n");
		ft_minpos(a, 0, a->lst_len);
		ft_maxpos(a, 0, a->lst_len);
		return ;
		//ft_printlist(a);
}

}*/
