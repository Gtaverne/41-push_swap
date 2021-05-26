#include "../includes/pushswap.h"

void	ft_quantcal(t_a *a)
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