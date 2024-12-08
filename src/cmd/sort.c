/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "organized.h"
#include "lib.h"

static
int compare_str(org_materials_t const *s1, org_materials_t const *s2)
{
    int i = 0;

    for (; s1->name[i] == s2->name[i] && s1->name[i] != '\0'; i++);
    return s2->name[i] - s1->name[i];
}

static
int compare_id(org_materials_t const *a, org_materials_t const *b)
{
    return b->id - a->id;
}

static
int compare_type(org_materials_t const *a, org_materials_t const *b)
{
    return b->type - a->type;
}

int sort(of_t *of, char **args)
{
    if (!args[0])
        return ORG_FAILURE;
    if (my_strcmp(args[0], "ID") == 0)
        mini_qsort((char *)of->om, of->act_i, sizeof *of->om,
            (__compar_fn_t)&compare_id);
    if (my_strcmp(args[0], "NAME") == 0)
        mini_qsort((char *)of->om, of->act_i, sizeof *of->om,
            (__compar_fn_t)&compare_str);
    if (my_strcmp(args[0], "TYPE") == 0)
        mini_qsort((char *)of->om, of->act_i, sizeof *of->om,
            (__compar_fn_t)&compare_type);
    return ORG_SUCCESS;
}
