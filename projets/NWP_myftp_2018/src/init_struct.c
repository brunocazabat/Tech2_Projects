/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init
*/

#include "my.h"

t_data	*init_struct(void)
{
	t_data	*data = malloc(sizeof(t_data));

	if (!data)
		return (NULL);
	data->help = "-help";
	data->opt_t = 0;

	return (data);
}
