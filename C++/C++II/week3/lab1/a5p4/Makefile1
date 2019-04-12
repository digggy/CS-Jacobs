.SUFFIXES:  .cpp .o
CC      = g++
OBJS    = Card.o Deck.o Game.o GenericPlayer.o Hand.o House.o Player.o
CFLAGS  = -Wall

all:		blackjack
blackjack:	$(OBJS) blackjack.o
			$(CC) $(OBJS) blackjack.o -o blackjack

%.o:		%.cpp %.h
			$(CC) $(CFLAGS) -c $<