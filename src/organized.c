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

int handle_realloc(of_t *of)
{
    org_materials_t *new_ptr;

    if (of->act_i == of->act_sz - 1) {
        new_ptr = my_realloc(of->om, (sizeof *of->om) * of->act_sz,
            (sizeof *of->om) * my_pow(of->act_sz, 2));
        if (new_ptr == NULL)
            return ORG_FAILURE;
        of->om = new_ptr;
        of->act_sz = my_pow(of->act_sz, 2);
    }
    return ORG_SUCCESS;
}

int organized(void)
{
    of_t of = { 0, .act_sz = 4 };

    of.om = malloc((sizeof *of.om) * of.act_sz);
    return workshop_shell(&of);
}
