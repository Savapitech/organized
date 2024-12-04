/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "lib.h"
#include "organized.h"
#include "shell.h"
#include <stdlib.h>

int organized(void)
{
    of_t of = { 0 };

    of.om = malloc((sizeof *of.om) * 10);
    workshop_shell(&of);
    return ORG_SUCCESS;
}
