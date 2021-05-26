#include "../includes/pushswap.h"

void	ft_rrr(t_a *a)
{
	int	tmp;
	int i;
	
	a->opcount++;
	ft_putstr_fd("rrr\n", 1);
	if (a->sep > 1)
	{
		i = 0;
		tmp = a->lst[0];
		while (i < a->sep - 1)
		{
			a->lst[i] = a->lst[i + 1];
			i++;
		}
		a->lst[a->sep - 1] = tmp;
	}
	if (a->sep < a->lst_len - 1)
	{
		i = a->lst_len - 1;
		tmp = a->lst[a->lst_len - 1];
		while (i > a->sep)
		{
			a->lst[i] = a->lst[i - 1];
			i--;
		}
		a->lst[a->sep] = tmp;
	}
}

void	ft_med(t_a *a, int init, int end)
{
	int	i;
	int	k;
	int tmp;
	int	tab[end - init + 1];

	i = -1;
	while (++i < end - init)
		tab[i] = a->lst[i + init];
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
	a->med = tab[(end - init) / 2];
}

void	ft_minpos(t_a *a, int init, int end)
{
	int i;
	int pos;
	int min;

	i = init;
	pos = i;
	min = a->lst[init];
	while (i < end)
	{
		if (a->lst[i] < min)
		{
			pos = i;
			min = a->lst[i];
		}
		i++;
	}
	a->minpos = pos;
	a->minval = min;
}

void	ft_maxpos(t_a *a, int init, int end)
{
	int i;
	int pos;
	int max;

	i = init;
	pos = i;
	max = a->lst[init];
	while (i < end)
	{
		if (a->lst[i] > max)
		{
			pos = i;
			max = a->lst[i];
		}
		i++;
	}
	a->maxpos = pos;
	a->maxval = max;
}

void	ft_move_right(t_a *a, int val_min, int val_max, int num)
{
	int	i;
	int k;

	i = a->sep - 1;
	k = a->sep - 1;
	while (i >= a->lst_len - num)
	{
		if (a->lst[k] <= val_max && a->lst[k] >= val_min)
		{
			ft_pb(a);
			k--;
		}
		else
			ft_ra(a);
		i--;
	}
}
