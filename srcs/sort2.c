#include "../includes/pushswap.h"

void	ft_strat_zero(t_a *a)
{
	int	i;

	i = -1;
	if (a->use_rr)
	{
		if (a->strat_tab[a->strat] > 2)
		{
			i++;
			ft_rr(a);
		}
		else
			ft_ra(a);
		a->use_rr = 0;
	}
	while (++i < a->strat_tab[a->strat] - 2)
		ft_rb(a);
	ft_pa(a);
	a->use_rr = 1;
}

void	ft_strat_one(t_a *a)
{
	int	i;

	i = -1;
	if (a->use_rr)
	{
		ft_ra(a);
		a->use_rr = 0;
	}
	while (++i < a->strat_tab[a->strat] - 2)
		ft_rrb(a);
	ft_pa(a);
	a->use_rr = 1;
}

void	ft_strat_two(t_a *a)
{
	int	i;

	i = -1;
	if (a->use_rr)
	{
		if (a->strat_tab[a->strat] > 2)
		{
			i++;
			ft_rr(a);
		}
		else
			ft_ra(a);
		a->use_rr = 0;
	}
	while (++i < a->strat_tab[a->strat] - 1)
		ft_rb(a);
	ft_pa(a);
	a->ramember++;
}

void	ft_strat_three(t_a *a)
{
	int	i;

	i = -1;
	if (a->use_rr)
	{
		ft_ra(a);
		a->use_rr = 0;
	}
	while (++i < a->strat_tab[a->strat] - 1)
		ft_rrb(a);
	ft_pa(a);
	a->ramember++;
}

int	*ft_brutal_sort(int *tab, int init, int end)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < end - init)
	{
		k = 0;
		while (k < i)
		{
			if (tab[k] < tab[i])
			{
				tmp = tab[k];
				tab[k] = tab[i];
				tab[i] = tmp;
			}
			k++;
		}
		i++;
	}
	return (tab);
}
