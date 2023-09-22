SOURCES = server.c client.c
OBJ		= $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g

all: libft server client

server: server.o
		$(CC) $(CFLAGS) libft/libft.a -o $@ $<

client: client.o
		$(CC) $(CFLAGS) libft/libft.a -o $@ $<

%.o: %.c 
	$(CC) -c $(CFLAGS) -o $@ $<

libft:
		make -C libft

bonus: all

clean:
		rm -f $(OBJ)
		make -C libft clean

fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re