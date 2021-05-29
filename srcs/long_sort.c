#include "../includes/pushswap.h"

void	ft_move_left(t_a *a, int val_min, int val_max, int num)
{
	int	i;
	int k;

	i = a->sep - 1;
	k = a->sep - 1;
	while (i >= a->lst_len - num)
	{
		if (a->lst[k] <= val_max && a->lst[k] >= val_min)
		{
			ft_pa(a);
			k--;
		}
		else
			ft_rb(a);
		i--;
	}
	a->rbmember = 0;
}

void	ft_sort_long_chain(t_a *a)
{
	(void)a;
}