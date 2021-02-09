int ft_is_prime(int nb)
{
	int n;
	int i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	n = 2;
	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}
