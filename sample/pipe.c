// C program to demonstrate use of fork() and pipe()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		arr[] = {1, 2, 7, 11, 5, 1, 9};
	int		arrSize = sizeof(arr) / sizeof(int);
	int		start, end;
	printf("%s\n", envp[3]);
	printf("%d, %d\n", fd[0], fd[1]);
	if (pipe(fd) == -1)
	{
		fprintf(stderr, "Pipe Failed");
		return (1);
	}
	int		id = fork();
	if (id == -1)
	{
		fprintf(stderr, "fork Failed");
		return (2);
	}
	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int	sum = 0;
	int	i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("Calculated partial sum: %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int	sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);
		int	totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}
}
