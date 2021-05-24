#include "../includes/pushswap.h"

void	ft_initstruct(t_a *a, int ac, char **av)
{
	a->ac = ac;
	a->av = av;
	a->sep = 0;
}