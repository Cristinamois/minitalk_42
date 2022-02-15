NAME	=
CLIENT	= client
SERVER	= server

SRC_C	= client.c
SRC_S	= server.c
INC	= minitalk.h

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER) :
	@ $(CC) $(CFLAGS) $(SRC_S) -o $(SERVER)

$(CLIENT) :
	@ $(CC) $(CFLAGS) $(SRC_C) -o $(CLIENT)

clean:
	@ $(RM) $(CLIENT) $(SERVER)

fclean:
	@ $(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY: all clean fclean re
