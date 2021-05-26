#include "../includes/pushswap.h"

void	ft_split_all_in_av1(t_a *a)
{
	a->raw_str = ft_split(a->av[1], " ");
	a->lst_len = 0;
	while (a->raw_str[a->lst_len])
		a->lst_len++;
}

void	dup_env(t_a *a)
{
	int	i;

	a->raw_str = malloc(sizeof(char *) * (a->ac));
	if (!a->raw_str)
		exit (120);
	a->raw_str[a->ac - 1] = 0;
	i = 0;
	while (i < a->ac - 1)
	{
		a->raw_str[i] = ft_strdup(a->av[i + 1]);
		i++;
	}
	a->lst_len = i;
}

void	ft_convert_list_to_int(t_a *a)
{
	int	i;
	int	k;

	i = 0;
	a->lst = malloc(sizeof(int) * a->lst_len);
	if (!a->lst)
		exit(1);
	while (i < a->lst_len)
	{
		a->lst[i] = ft_atoi(a->raw_str[a->lst_len - 1 - i]);
		i++;
	}
	i = 1;
	while (i < a->lst_len)
	{
		k = 0;
		while (k < i)
		{
			if (a->lst[k] == a->lst[i])
				ft_cleanexit(a, "KO: il y a un doublon\n", 2);
			k++;
		}
		i++;
	}
}

void	ft_valid_characters(t_a *a)
{
	int	i;
	int	k;

	i = 0;
	while (i < a->lst_len)
	{
		k = 0;
		while (a->raw_str[i][k] != 0)
		{
			if (k == 0 && !is_insep(a->raw_str[i][k], "-0123456789"))
				ft_cleanexit(a, "KO : invalid Character\n", 2);
			if (k > 0 && !is_insep(a->raw_str[i][k], "0123456789"))
				ft_cleanexit(a, "KO : invalid Character\n", 2);
			if (k == 0 && a->raw_str[i][k] == '-' \
			&& !is_insep(a->raw_str[i][k + 1], "0123456789"))
				ft_cleanexit(a, "KO : check signs\n", 2);
			k++;
		}
		i++;
	}
	ft_convert_list_to_int(a);
}

void	ft_parser(t_a *a)
{
	if (a->ac < 2)
	{
		ft_putstr_fd("KO : Too few arguments\n", 2);
		exit (0);
	}
	else if (a->ac == 2)
		ft_split_all_in_av1(a);
	else if (a->ac > 2)
		dup_env(a);
	ft_valid_characters(a);
}
