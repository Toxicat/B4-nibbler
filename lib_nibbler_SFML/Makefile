##
## Makefile for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_SFML
## 
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
## 
## Started on  Sat Apr  5 22:56:28 2014 Nathan AUBERT
## Last update Sun Apr  6 17:10:55 2014 Nathan AUBERT
##

CXX	=	g++
RM	=	rm -f
BIN	=	lib_nibbler_SFML_$(HOSTTYPE).so
LN	=	../lib_nibbler_SFML.so
I_DIR	=	include

CXXFLAGS +=	-W -Wall -Wextra
CXXFLAGS +=	-fPIC
CXXFLAGS +=	-I. -I../
CXXFLAGS +=	-I/usr/local/SFML-2.1/include
CXXFLAGS +=	-I/usr/local/Trolltech/Qt-4.8.5/include

LDFLAGS	+=	-L/usr/local/Trolltech/Qt-4.8.5/lib
LDFLAGS	+=	-lQtGui
LDFLAGS	+=	-lQtCore
LDFLAGS	+=	-L/usr/local/SFML-2.1/lib
LDFLAGS	+=	-lsfml-graphics
LDFLAGS	+=	-lsfml-window
LDFLAGS	+=	-lsfml-system
LDFLAGS	+=	-ldl

SRCS	=	extern.cpp \
		Canvas.cpp \
		SFMLCanvas.cpp

OBJS	=	$(SRCS:.cpp=.o)

$(BIN):	$(OBJS)
	@echo -e "\E[33;35mCompiling SFML library...\E[33;37m"
	$(CXX) -shared -o $(BIN) $(OBJS) $(LDFLAGS) 
	@echo -e "\E[33;35mLinking SFML library...\E[33;37m"
	ln -sf ./lib_nibbler_SFML/$(BIN) $(LN)

all:	$(BIN)

clean:
	@echo -e "\E[33;35mCleaning SFML object files...\E[33;37m"
	$(RM) $(OBJS)

fclean:	clean
	@echo -e "\E[33;35mCleaning SFML binaries, links...\E[33;37m"
	$(RM) $(BIN)
	$(RM) $(LN)

re:	fclean all

.PHONY:	all clean fclean re
