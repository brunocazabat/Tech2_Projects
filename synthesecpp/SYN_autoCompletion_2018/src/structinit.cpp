/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"


autocomp	        *init_data()
{
    autocomp *data;
    data = (autocomp *)malloc(sizeof(autocomp));

	data->city 			= "oui";
	data->streetType 	= "oui";
	data->streetName 	= "oui";
	data->number 		= "oui";
	if (!data)
		return (NULL);
	return (data);
}

strinfo	            *init_info()
{
    strinfo *info;
    info = (strinfo *)malloc(sizeof(strinfo));

	if (!info)
		return (NULL);
	info->parserinc 	= 0;
	info->parsed_letter = "oui";
	info->line			= "oui";
	info->goodline 		= 0;
    info->help 			= "-h";
	return (info);
}