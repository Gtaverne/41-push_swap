#include "../includes/pushswap.h"

void	ft_sa(t_a *a)
{
	int	tmp;

	a->opcount++;
	ft_putstr_fd("sa\n", 1);
	if (a->sep > 1)
	{
		tmp = a->lst[a->sep - 1];
		a->lst[a->sep - 1] = a->lst[a->sep - 2];
		a->lst[a->sep - 2] = tmp;
	}
}

void	ft_sb(t_a *a)
{
	int	tmp;

	a->opcount++;
	ft_putstr_fd("sb\n", 1);
	if (a->lst_len - a->sep > 1)
	{
		tmp = a->lst[a->sep];
		a->lst[a->sep] = a->lst[a->sep + 1];
		a->lst[a->sep + 1] = tmp;
	}
}

void	ft_ss(t_a *a)
{
	int	tmp;

	a->opcount++;
	ft_putstr_fd("ss\n", 1);
	if (a->sep > 1)
	{
		tmp = a->lst[a->sep - 1];
		a->lst[a->sep - 1] = a->lst[a->sep - 2];
		a->lst[a->sep - 2] = tmp;
	}
	if (a->lst_len - a->sep > 1)
	{
		tmp = a->lst[a->sep];
		a->lst[a->sep] = a->lst[a->sep + 1];
		a->lst[a->sep + 1] = tmp;
	}
}

void	ft_pa(t_a *a)
{
	a->opcount++;
	ft_putstr_fd("pa\n", 1);
	if (a->sep < a->lst_len)
		a->sep++;
}

void	ft_pb(t_a *a)
{
	a->opcount++;
	ft_putstr_fd("pb\n", 1);
	if (a->sep > 0)
		a->sep--;
}
