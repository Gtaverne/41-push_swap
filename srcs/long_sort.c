#include "../includes/pushswap.h"

void	ft_move_left(t_a *a, int val_min, int val_max, int num)
{
	int	i;
	int	k;

	i = 0;
	k = a->sep;
	while (i < num)
	{
		if (a->lst[k] <= val_max && a->lst[k] >= val_min)
		{
			ft_pa(a);
			k++;
		}
		else
			ft_rb(a);
		i++;
	}
	a->rbmember = 0;
}

void	ft_move_right_while_under_val(t_a *a, int val)
{
	while (a->lst[a->sep - 1] <= val)
		ft_pb(a);
}

void	ft_move_right_while_over_val(t_a *a, int val)
{
	while (a->lst[a->sep - 1] > val)
		ft_pb(a);
}

void	ft_sort_right_and_bring_it_left(t_a *a)
{
	int	i;
	int	k;

	i = 0;
	k = a->lst_len - a->sep;
	while (i < k)
	{
		ft_findstrat(a);
		ft_runstrat(a);
		i++;
	}
	while (a->ramember -- + a->use_rr > 0)
		ft_ra(a);
}

void	ft_sort_long_chain(t_a *a)
{
	ft_move_right(a, a->minval, a->med, a->lst_len);
	ft_med(a, a->sep, a->lst_len - 1);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	ft_sort_right_and_bring_it_left(a);
	ft_med(a, 0, a->lst_len - 1);
	ft_move_right_while_under_val(a, a->med);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	ft_move_right_while_over_val(a, a->minval);
	ft_med(a, a->sep, a->lst_len - 1);
	ft_maxpos(a, a->sep, a->lst_len);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	ft_move_right_while_over_val(a, a->minval);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	while (a->lst[a->lst_len - 1] > a->minval)
		ft_ra(a);
}

/*
void	ft_sort_long_chain_backup(t_a *a)
{
	ft_move_right(a, a->minval, a->med, a->lst_len);
	ft_med(a, a->sep, a->lst_len - 1);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	ft_sort_right_and_bring_it_left(a);
	ft_med(a, 0, a->lst_len - 1);
	ft_move_right_while_under_val(a, a->med);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	ft_move_right_while_over_val(a, a->minval);
	ft_med(a, a->sep, a->lst_len - 1);
	ft_maxpos(a, a->sep, a->lst_len);
	ft_move_left(a, a->med, a->maxval, a->lst_len - a->sep);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	ft_move_right_while_over_val(a, a->minval);
	ft_sort_right_and_bring_it_left(a);
	ft_minpos(a, 0, a->lst_len);
	while (a->lst[a->lst_len - 1] > a->minval)
		ft_ra(a);
}
*/
