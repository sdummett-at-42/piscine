int ft_find_next_prime(int nb)
{
	int n;

	if (nb == 0 || nb == 1 || nb == 2)
		return (2);
	prime = 0;
	while (1)
	{
		n = 2;
		while (n < nb)
		{
			if (nb % n == 0)
				break;
			n++;
		}
		if (n == nb)
			return (nb);
		nb++;
	}
}
