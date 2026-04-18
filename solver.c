int		check_case(int tab[4][4], int pos, int entry[16]);

int		solve(int tab[4][4], int entry[16], int pos)
{
	int		num;

	if (pos == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		tab[pos / 4][pos % 4] = num; // Ponemos el número
		if (check_case(tab, pos, entry) == 0) // Si check_case devuelve 0, es que TODO BIEN
		{
			if (solve(tab, entry, pos + 1)) // Siguiente casilla
				return (1);
		}
		tab[pos / 4][pos % 4] = 0; // Si no funcionó, reseteamos (Backtracking)
	}
	return (0);
}