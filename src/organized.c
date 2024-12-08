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

const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};

int handle_realloc(of_t *of)
{
    org_materials_t *new_ptr;

    if (of->act_i == of->act_sz - 1) {
        new_ptr = my_realloc(of->om, (sizeof *of->om) * of->act_sz,
            (sizeof *of->om) * (of->act_sz << 1));
        if (new_ptr == NULL)
            return ORG_FAILURE;
        of->om = new_ptr;
        for (size_t i = of->act_sz; i < (of->act_sz << 1); i++) {
            of->om[i].id = -1;
            of->om[i].type = -1;
            of->om[i].name = NULL;
        }
        of->act_sz = of->act_sz << 1;
    }
    return ORG_SUCCESS;
}

int organized(void)
{
    of_t of = { 0, .act_sz = 512 };
    int result = 0;

    of.om = malloc((sizeof *of.om) * of.act_sz);
    if (!of.om)
            return ORG_FAILURE;
    for (size_t i = 0; i < of.act_sz; i++) {
        of.om[i].id = -1;
        of.om[i].type = -1;
        of.om[i].name = NULL;
    }
    result = workshop_shell(&of);
    return result;
}
