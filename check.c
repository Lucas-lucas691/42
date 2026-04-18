#include <unistd.h>

/* Verifica si el número ya existe en la fila o la columna actual */
int	check_double(int tab[4][4], int pos, int num)
{
	int	i;
	int	row;
	int	col;

	row = pos / 4;
	col = pos % 4;
	i = 0;
	while (i < 4)
	{
		if (tab[row][i] == num && i != col)
			return (1);
		if (tab[i][col] == num && i != row)
			return (1);
		i++;
	}
	return (0);
}

/* Cuenta edificios visibles desde arriba y abajo (solo al llenar la columna) */
int	check_col(int tab[4][4], int pos, int entry[16])
{
	int	i;
	int	max;
	int	count;

	if (pos / 4 == 3) // Solo cuando llegamos a la última fila de la columna
	{
		// Check UP
		i = -1;
		max = 0;
		count = 0;
		while (++i < 4)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
		}
		if (entry[pos % 4] != count)
			return (1);
		
		// Check DOWN (puedes meterlo aquí o en otra función si te pasas de líneas)
		i = 4;
		max = 0;
		count = 0;
		while (--i >= 0)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
		}
		if (entry[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

/* Cuenta edificios visibles desde izquierda y derecha (solo al llenar la fila) */
int	check_row(int tab[4][4], int pos, int entry[16])
{
	int	i;
	int	max;
	int	count;

	if (pos % 4 == 3) // Solo cuando llegamos al final de la fila
	{
		// Check LEFT
		i = -1;
		max = 0;
		count = 0;
		while (++i < 4)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
		}
		if (entry[8 + pos / 4] != count)
			return (1);

		// Check RIGHT
		i = 4;
		max = 0;
		count = 0;
		while (--i >= 0)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
		}
		if (entry[12 + pos / 4] != count)
			return (1);
	}
	return (0);
}

/* Función principal de validación que llama a las anteriores */
int	check_case(int tab[4][4], int pos, int entry[16])
{
	if (check_double(tab, pos, tab[pos / 4][pos % 4]))
		return (1);
	if (check_col(tab, pos, entry))
		return (1);
	if (check_row(tab, pos, entry))
		return (1);
	return (0);
}