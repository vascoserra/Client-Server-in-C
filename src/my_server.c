#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int	g_binary_count = 0;

int	reconvert_to_int(char *binary)
{
	int	len;
	int	i;
	int	ascii;
	int	n;
	int	j;

	len = 8;
	ascii = 0;
	i = 0;
	while (i < len)
	{
		if (binary[i] == '1')
		{
			n = 1;
			j = len - 1;
			while (j > i)
			{
				n *= 2;
				j--;
			}
			ascii += n;
		}
		i++;
	}
	return (ascii);
}

void	handler_sigusr1(int signum)
{
	char	binary[9];
	int		result;

	if (signum == SIGUSR1)
	{
		binary[g_binary_count++] = '0';
	}
	else if (signum == SIGUSR2)
	{
		binary[g_binary_count++] = '1';
	}
	if (g_binary_count == 8)
	{
		binary[g_binary_count] = '\0';
		result = reconvert_to_int(binary);

		if (result == 10)
		{
			printf("\n");
		}
		else
			printf("%c", result);
	g_binary_count = 0;
	}
}

int	main()
{
	pid_t	pid;

	pid = getpid();
	printf("my PID number is %d\n", pid);
	while(1)
	{
		signal(SIGUSR1, handler_sigusr1);
		signal(SIGUSR2, handler_sigusr1);
	}
	return (0);
}

