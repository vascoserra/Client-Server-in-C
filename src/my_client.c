#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	return (number * sign);
}

void	send_signals(int pid, char *message)
{
	int i;
	int bit_counter;

	i = 0;
	while (message[i] != '\0')
	{	
		bit_counter = 7;
		while (bit_counter >= 0)
		{
			if ((message[i] >> bit_counter) & 1)
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			bit_counter--;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*new_line; 
	
	new_line = "\n";
	if (ac != 3)
	{
		printf("Input should be: %s <PID number> <string to send>\n", av[0]);
		exit(1);
	}
	int pid = ft_atoi(av[1]);
	send_signals(pid, av[2]);
	send_signals(pid, new_line);
	return 0;
}