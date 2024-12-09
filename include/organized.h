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
    INVALID = -1,
    ACTUATOR = 0,
    DEVICE = 1,
    PROCESSOR = 2,
    SENSOR = 3,
    WIRE = 4
} org_type_t;

typedef struct {
    int id;
    org_type_t type;
    char *name;
} org_materials_t;

typedef struct {
    org_materials_t *om;
    size_t act_sz;
    uint32_t act_i;
} of_t;

extern const char *TYPES[];

int organized(void);
int handle_realloc(of_t *);
int get_type(char *);
#endif /* ORGANIZED_H */
