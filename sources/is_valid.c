 #include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_num(char *num) 
{
    int	i;

	i = 0;
	if (num == NULL || *num == '\0')
        return (0);
    if (num[0] == '-') 
    	i++;;
    while (num[i]) 
	{
        if (!is_digit(num[i]))
			return (0);
        i++;
    }
    return (1);
}

static int	is_dup(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	is_valid(int ac, char **av)
{
	int		i;
	long	tmp;	

	i = 1;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (!is_num(av[i]))
			ft_error("Error");
		if (is_dup(tmp, av, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(av);
}
