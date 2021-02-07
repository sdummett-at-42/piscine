int	ft_atoi(char *str)
{
	int sign;
	int nb;
	
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;		
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
	       str++;	
	}
	return(nb * sign);

}
