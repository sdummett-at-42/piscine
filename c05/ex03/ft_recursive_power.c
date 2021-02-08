int ft_recursive_power(int nb, int power)
{
	int n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
	{
		nb = n * ft_recursive_power(nb, power - 1);
		return (nb);
	}
	return (nb);
}
