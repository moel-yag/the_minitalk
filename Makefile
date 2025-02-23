NAME = minitalk
CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
