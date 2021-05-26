#include "../includes/pushswap.h"

void	ft_findstrat(t_a *a)
{
	int i;
	/*In col b
	1- Find min, rb it to the top, pa it, ra it
	2- Find min, rrb it to the top, pa it, ra it
	3- Find max, rb it to the top, pa it
	4- Find max, rrb it to the top, pa it
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
		if (a->strat_tab[i] < a->strat_tab[a->strat])
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
		while (++i < a->strat_tab[a->strat] - 2)
			ft_rb(a);
	else if (a->strat == 1)
		while (++i < a->strat_tab[a->strat] - 2)
			ft_rrb(a);
	else if (a->strat == 2)
		while (++i < a->strat_tab[a->strat] - 1)
			ft_rb(a);
	else if (a->strat == 3)
		while (++i < a->strat_tab[a->strat] - 1)
			ft_rrb(a);
	ft_pa(a);
	if (a->strat < 2)
		ft_ra(a);
	else
		a->ramember++;	
}

void	ft_initializer(t_a *a)
{
	a->sep = a->lst_len;
	ft_med(a, 0, a->lst_len - 1);
	ft_minpos(a, 0, a->lst_len);
	ft_maxpos(a, 0, a->lst_len);
	a->numquant = a->lst_len / BATCHSIZE + (a->lst_len % BATCHSIZE > 0);
	a->quantile = malloc(sizeof(int) * a->numquant);
	ft
	//ft_printlist(a);
	//printf("Voici la situation initiale\n*****************************");
}

void	ft_sort(t_a *a)
{
	int	i;
	int	k;

	ft_initializer(a);
	ft_move_right(a, a->minval, a->med, a->lst_len);

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
	//ft_printlist(a);
}

/*
void	ft_sort(t_a *a)
{
	int	i;
	int	k;

	ft_initializer(a);
	ft_move_right(a, a->minval, a->med, a->lst_len);

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
	//ft_printlist(a);
}

}*/
