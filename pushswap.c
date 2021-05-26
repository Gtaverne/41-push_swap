#include "./includes/pushswap.h"

int	main(int ac, char **av)
{
	t_a	a;

	ft_initstruct(&a, ac, av);
	ft_parser(&a);
	ft_sort(&a);
	ft_cleanexit(&a, 0, 2);
	return (0);
}
