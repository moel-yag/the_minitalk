NAME = minitalk
CLIENT = client
SERVER = server
PRINTF = ft_printf/

FT_PRINTF = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME)
	
$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) utils.h
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(FT_PRINTF)

$(SERVER): $(OBJ_SERVER) utils.h
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(FT_PRINTF)


clean:
	make clean -C $(PRINTF)
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C $(PRINTF)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
