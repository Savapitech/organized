/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H
    #define ORG_SUCCESS 0
    #define ORG_FAILURE 84
    #include <stddef.h>
    #include <stdint.h>

typedef enum {
    ACTUATOR = 0,
    DEVICE = 1,
    PROCESSOR = 2,
    SENSOR = 3,
    WIRE = 4
} org_type_t;

typedef struct {
    uint32_t id;
    org_type_t type;
    char *name;
} org_materials_t;

typedef struct {
    org_materials_t *om;
    size_t act_sz;
    uint32_t act_i;
} of_t;

int organized(void);
#endif /* ORGANIZED_H */
