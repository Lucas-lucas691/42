#include <stdlib.h>

int	*get_numbers(char *str)
{
	int	*entry;
	int	i;
	int	j;

	entry = malloc(16 * sizeof(int));
	if (!entry)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (j >= 16) // Por si pasan más de 16 números
				return (0);
			entry[j++] = str[i] - '0';
		}
		i++;
	}
	if (j != 16) // Si pasan menos de 16 números
		return (0);
	return (entry);
}