##
## EPITECH PROJECT, 2024
## organized
## File description:
## ./Makefile
##

MAKEFLAGS += -j

NAME := organized

LIB_NAME := libmy.a

SRC := $(wildcard src/*.c)
SRC += $(wildcard src/cmd/*.c)

LIB_SRC := $(wildcard lib/my/*.c)
LIB_SRC += $(wildcard lib/my/printf/*.c)
LIB_SRC += $(wildcard lib/my/printf/baby/*.c)
LIB_SRC += $(wildcard lib/my/printf/handler/*.c)

BUILD_DIR := .build

TEST_SRC := tests/main.c
TEST_OBJ := $(TEST_SRC:%.c=$(BUILD_DIR)/%.o)

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
LIB_OBJ := $(LIB_SRC:%.c=$(BUILD_DIR)/%.o)

CC := gcc

CFLAGS += -Wall -Wextra
CFLAGS += -iquote ./include
CFLAGS += -Wno-unused-parameter

LDFLAGS += -L .
LDLIBS := -lmy -lshell

include utils.mk

oui: $(NAME)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@ $(LOG_TIME) "$(C_GREEN) CC $(C_PURPLE) $(notdir $@) $(C_RESET)"

$(LIB_NAME): $(LIB_OBJ)
	@ ar rc $(LIB_NAME) $(LIB_OBJ)
	@ $(LOG_TIME) "$(C_CYAN) AR $(C_PURPLE) $(notdir $@) $(C_RESET)"

$(NAME): $(LIB_NAME) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@ $(LOG_TIME) "$(C_GREEN) CC $(C_PURPLE) $(notdir $@) $(C_RESET)"
	@ $(LOG_TIME) "$(C_GREEN) OK  Compilation finished $(C_RESET)"

clean:
	@ $(RM) $(OBJ)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(OBJ) $(C_RESET)"

fclean:
	@ $(RM) -r $(NAME) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME) $(BUILD_DIR) $(C_RESET)"
	@ $(RM) $(LIB_NAME)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(LIB_NAME) $(C_RESET)"

.NOTPARALLEL: re
re:	fclean oui

test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) $(LDFLAGS) $(LDLIBS)

tests_run: test
	./$<

.PHONY: all clean fclean re test tests_run
