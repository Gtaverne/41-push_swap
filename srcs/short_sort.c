#include "../includes/pushswap.h"

void	ft_sort_two_left(t_a *a)
{
	if (a->lst[1] > a->lst[0])
		ft_sa(a);
}

void	ft_sort_two_right(t_a *a)
{
	if (a->lst[1] > a->lst[0])
		ft_sa(a);
}

void	ft_sort_three(t_a *a)
{
	if (a->lst[0] > a->lst[1] && a->lst[1] > a->lst[2])
		return;
	else if (a->lst[0] > a->lst[2] && a->lst[2] > a->lst[1])
		ft_sa(a);
	else if (a->lst[1] > a->lst[0] && a->lst[0] > a->lst[2])
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (a->lst[1] > a->lst[0] && a->lst[0] > a->lst[2])
		ft_rra(a);
	else if ((a->lst[2] > a->lst[0] && a->lst[0] > a->lst[1]))
		ft_ra(a);
	else if (a->lst[2] > a->lst[1] && a->lst[1] > a->lst[0])
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	ft_sort_short_chain(t_a *a)
{
	if (a->sep == 1)
		return ;
	if (a->sep == 2)
		ft_sort_two(a);
	if (a->sep == 3)
		ft_sort_three(a);
	if (a->sep == 4)
	{
		ft_med(a, 0 , 4);
		ft_move_right(a, a->minval - 1, a->sep, 4);
	}

}