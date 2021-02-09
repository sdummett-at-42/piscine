int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt =  nb / 2 + 1;
	while (sqrt > 0)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt--;
	}
	return (0);
}
