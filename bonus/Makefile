##
## EPITECH PROJECT, 2024
## organized
## File description:
## ./Makefile
##

MAKEFLAGS += -j

NAME := libshell.a


SRC := $(wildcard *.c)

BUILD_DIR := .build

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

CC := gcc

CFLAGS += -Wall -Wextra
CFLAGS += -iquote ./

include utils.mk

oui: $(NAME)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@ $(LOG_TIME) "$(C_GREEN) CC $(C_PURPLE) $(notdir $@) $(C_RESET)"

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ $(LOG_TIME) "$(C_CYAN) AR $(C_PURPLE) $(notdir $@) $(C_RESET)"
	@ $(LOG_TIME) "$(C_GREEN) OK  Compilation finished $(C_RESET)"

clean:
	@ $(RM) $(OBJ)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(OBJ) $(C_RESET)"

fclean:
	@ $(RM) -r $(NAME) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME) $(BUILD_DIR) $(C_RESET)"

.NOTPARALLEL: re
re:	fclean oui

test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) $(LDFLAGS) $(LDLIBS)

tests_run: test
	./$<

.PHONY: all clean fclean re test tests_run
