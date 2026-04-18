#include <unistd.h>

void	display_solution(int tab[4][4])
{
	int i;
	int j;
	char c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			// Si no es el último número de la fila, ponemos un espacio
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}