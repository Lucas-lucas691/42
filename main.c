#include <unistd.h>
#include <stdlib.h>

/* Prototipos para que el compilador no se queje */
int		*get_numbers(char *str);
int		solve(int tab[4][4], int entry[16], int pos);
void	display_solution(int tab[4][4]);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int ac, char **av)
{
	int		tab[4][4];
	int		*entry;
	int		row;
	int		col;

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	entry = get_numbers(av[1]);
	if (!entry)
	{
		ft_putstr("Error\n");
		return (0);
	}
	// Inicializar tablero a 0
	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			tab[row][col] = 0;
	}
	// Resolver e imprimir
	if (solve(tab, entry, 0))
		display_solution(tab);
	else
		ft_putstr("Error\n");
	free(entry);
	return (0);
}