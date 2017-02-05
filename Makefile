# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                   \\             #
#                                                               (o >           #
#    By: cpoulet <cpoulet@student.42.fr>                     \\_//)            #
#                                                             \_/_)            #
#    Created: 2017/01/22 14:13:52 by cpoulet                   _|_             #
#    Updated: 2017/01/22 14:15:27 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES =	ft_printf.c\
	parser.c\
	format.c\
	num_field.c\
	str_field.c\
	fwp_int.c\
	fwp_u_int.c\
	fwp_bin.c\
	fwp_oct.c\
	fwp_hex.c\
	fwp_ptr.c\
	fwp_char.c\
	fwp_wchar.c\
	fwp_wstr.c\
	cast_mod.c\
	lst_arg.c\
	buffer.c

SRC = $(addprefix srcs/,$(FILES))
OBJ = $(FILES:.c=.o)

DIR = bin
INCLUDES = -I includes/ -I libft/includes/
LIBS = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C libft/
	@echo "Compiling libft.a... OK"
	@gcc $(CFLAGS) $(INCLUDES) -c $(SRC)
	@libtool -static -o $@ $(OBJ) libft/libft.a
	@ranlib $@
	@echo "Compiling libftprintf.a... OK"

clean :
	@rm -f $(OBJ)
	@echo "Deleting objects... OK"
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

diff :
	cc -I includes -I libft/includes main1.c -L. -lftprintf
	./a.out > diff_1
	cc -I includes -I libft/includes main2.c -L. -lftprintf
	./a.out > diff_2
	diff diff_1 diff_2 > toto

main :
	@make -C libft/
	@make clean -C libft/
	gcc $(INCLUDES) $(SRC) main.c $(LIBS)

.PHONY : all clean fclean re
