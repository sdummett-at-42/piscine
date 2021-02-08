int ft_iterative_power(int nb, int power)
{
	int n;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb;
	while (power > 1)
	{
		nb = nb * n;
		power--;
	}
	return (nb);
}
