#include "../includes/pushswap.h"

void	ft_ra(t_a *a)
{
	int	tmp;
	int	i;

	a->opcount++;
	ft_putstr_fd("ra\n", 1);
	if (a->sep > 1)
	{
		i = a->sep - 1;
		tmp = a->lst[a->sep - 1];
		while (i > 0)
		{
			a->lst[i] = a->lst[i - 1];
			i--;
		}
		a->lst[0] = tmp;
	}
}

void	ft_rb(t_a *a)
{
	int	tmp;
	int	i;

	a->opcount++;
	ft_putstr_fd("rb\n", 1);
	if (a->sep < a->lst_len - 1)
	{
		i = a->sep;
		tmp = a->lst[a->sep];
		while (i < a->lst_len - 1)
		{
			a->lst[i] = a->lst[i + 1];
			i++;
		}
		a->lst[a->lst_len - 1] = tmp;
	}
}

void	ft_rr(t_a *a)
{
	int	tmp;
	int	i;

	a->opcount++;
	ft_putstr_fd("rr\n", 1);
	if (a->sep > 1)
	{
		i = a->sep;
		tmp = a->lst[a->sep - 1];
		while (--i > 0)
			a->lst[i] = a->lst[i - 1];
		a->lst[0] = tmp;
	}
	if (a->sep < a->lst_len - 1)
	{
		i = a->sep - 1;
		tmp = a->lst[a->sep];
		while (++i < a->lst_len - 1)
			a->lst[i] = a->lst[i + 1];
		a->lst[a->lst_len - 1] = tmp;
	}
}

void	ft_rra(t_a *a)
{
	int	tmp;
	int	i;

	a->opcount++;
	ft_putstr_fd("rra\n", 1);
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
}

void	ft_rrb(t_a *a)
{
	int	tmp;
	int	i;

	a->opcount++;
	ft_putstr_fd("rrb\n", 1);
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
