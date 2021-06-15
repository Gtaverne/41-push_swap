#include "../includes/pushswap.h"

void	ft_quantcal2(t_a *a, int *tab)
{
	int	i;

	i = 1;
	while (a->lst_len > i * BATCHSIZE)
	{
		a->quantile[i - 1] = tab[BATCHSIZE * i];
		i++;
	}
	a->quantile[i - 1] = a->minval;
	printf("Quantiles : %d\n", a->numquant);
	i = -1;
	while (++i < a->numquant)
		printf(" %d : %d | ", i, a->quantile[i]);
}

void	ft_quantcal(t_a *a)
{
	int	i;
	int	k;
	int tmp;
	int	tab[a->lst_len];

	i = -1;
	while (++i < a->lst_len)
		tab[i] = a->lst[i];
	i = 0;
	while (i < a->lst_len)
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
	ft_quantcal2(a, tab);
}

void	ft_quantopt(t_a *a)
{
	int	i;
	int	j;
	int	k;

	j = a->numquant - 1;
	while (j > 0)
	{
		ft_minpos(a, 0, a->lst_len);
		ft_maxpos(a, 0, a->lst_len);
		if (j == 0)
			ft_move_right(a, a->quantile[j], a->quantile[j - 1], 0);
		else if (j > 0)
			ft_move_right(a, a->quantile[j], a->quantile[j - 1], a->lst_len - a->minpos);
		else
			ft_move_right(a, a->quantile[j], a->maxval + 1, a->lst_len - a->minpos);
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
		j--;
	}
}