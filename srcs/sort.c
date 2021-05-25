#include "../includes/pushswap.h"

void	ft_sort(t_a *a)
{
	a->sep = a->lst_len;
	ft_med(a, 0, a->lst_len - 1);

	ft_ra(a);
	ft_sa(a);
	ft_ra(a);
	ft_sa(a);
	ft_ra(a);
	ft_ra(a);

	ft_move_right(a, a->med);
	ft_minpos(a, 0, a->sep - 1);
	ft_maxpos(a, 0, a->sep - 1);
	ft_printlist(a);
}
