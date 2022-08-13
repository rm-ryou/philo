NAME := philo
CFLAGS := -MMD -MP -pthread -fsanitize=thread -g #-Wall -Werror -Wextra
SRCS_DIR := ./srcs
OBJS_DIR := ./objs

SRCS := $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/init_all.c \
		$(SRCS_DIR)/launch_meal.c \
		$(SRCS_DIR)/monitor.c \
		$(SRCS_DIR)/handle_thread.c \
		$(SRCS_DIR)/utils/ft_atoi.c \
		$(SRCS_DIR)/utils/ft_isdigit.c \
		$(SRCS_DIR)/utils/print_utils.c \
		$(SRCS_DIR)/utils/time.c \

OBJS := $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))
DEPS := $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)/$(*D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
