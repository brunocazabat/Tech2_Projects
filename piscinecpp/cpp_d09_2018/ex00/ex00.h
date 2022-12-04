/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef EX00_H_
	#define EX00_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_cthulhu
{
	int			m_power;
	char		*m_name;
}	cthulhu_t;

typedef struct	s_koala
{
	cthulhu_t	m_parent;
	char		m_is_a_legend;
}	koala_t;

cthulhu_t 	*new_cthulhu();
void 		print_power(cthulhu_t *this);
void 		attack(cthulhu_t *this);
void		sleeping(cthulhu_t *this);
koala_t 	*new_koala(char *name, char is_a_legend);
void		eat(koala_t *this);
static void cthulhu_initializer(cthulhu_t *this);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);

#endif /* !EX00_H_ */