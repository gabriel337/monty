#include "monty.h"

/**
 * main - accepts input and reads monty file.
 * @argc: argumnets count
 * @argv: argument values
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd, flag_push = 0;
	unsigned int line = 1;
	ssize_t file_read;
	char *buffer, *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY); /*to read monty file in terminal*/
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);
	file_read = read(fd, buffer, 10000);
	if (file_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:");/*divide each digit by delims*/
	while (token != NULL)
	{
		if (flag_push == 1)
		{
			push(&h, line, token);
			flag_push = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			flag_push = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
				get_op_func(token)(&h, line);
			else
			{
				free_dlistint(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlistint(&h);
	free(buffer);
	close(fd);
	return (0);
}
