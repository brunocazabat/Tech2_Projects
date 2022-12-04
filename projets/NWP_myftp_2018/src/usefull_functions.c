/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "my.h"

t_data	  *init_struct(void)
{
	t_data	*data = malloc(sizeof(t_data));

	if (!data)
		return (NULL);
	data->help = "-help";
	data->opt_t = 0;

	return (data);
}

void    print_usage()
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user");
}

short	  is_digit(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] < 48 || str[i] > 57)
      return (ERROR_PARAM);
  return (0);
}