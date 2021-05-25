#include "../includes/pushswap.h"

void	ft_printlist(t_a *a)
{
	int i;
	//PENSER A SUPP AVANT DE PUSH
	if (DEBUG)
	{
		i = 0;
		printf("*****Print List*****\n");
		printf("List len : %d  opcount : %d med : %d\n\
minpos : %d minpval : %d maxpos : %d maxval : %d \n"
		, a->lst_len, a->opcount, a->med, a->minpos, a->minval, a->maxpos, a->maxval);
		while (i < a->lst_len)
		{
			if (i == a->sep)
				printf("|sep :%d |", i);
			if (i > 0)
				printf(",");
			printf(" %d ", a->lst[i]);
			i++;
		}
		if (i == a->sep)
				printf("|sep :%d |", i);
		printf("\n******************\n");
	}
}
