#include "../includes/pushswap.h"

void	ft_initstruct(t_a *a, int ac, char **av)
{
	a->ac = ac;
	a->av = av;
	a->sep = 0;
	a->lst = 0;
	a->raw_str = 0;
	a->opcount = 0;
	a->med = 0;
	a->minpos = 0;
	a->minval = 0;
	a->maxpos = 0;
	a->maxval = 0;
	a->use_rr = 0;
}

void	ft_cleanexit(t_a *a, char *exit_message, int fd)
{
	if (a->raw_str != 0)
		ft_freesplit(a->raw_str);
	if (a->lst != 0)
		free (a->lst);
	if (!exit_message)
		exit (fd - 1);
	else if (DEBUG == 1 && exit_message)
		ft_putstr_fd(exit_message, fd);
	else
		ft_putstr_fd("Error\n", fd);
	exit (fd - 1);
}
