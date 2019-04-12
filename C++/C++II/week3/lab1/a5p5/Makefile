CC      = g++
OBJS    = Card.o Deck.o Game.o GenericPlayer.o Hand.o House.o Player.o
CFLAGS  = -Wall

all:		blackjack
blackjack:	$(OBJS) blackjack.o
			$(CC) $(OBJS) blackjack.o -o blackjack

Card.o:		Card.cpp Card.h
			$(CC) $(CFLAGS) -c Card.cpp 
Deck.o:		Deck.cpp Deck.h
			$(CC) $(CFLAGS) -c Deck.cpp 
GenericPlayer.o:		GenericPlayer.cpp GenericPlayer.h
			$(CC) $(CFLAGS) -c GenericPlayer.cpp 
Hand.o:		Hand.cpp Hand.h
			$(CC) $(CFLAGS) -c Hand.cpp 
House.o:		House.cpp House.h
			$(CC) $(CFLAGS) -c House.cpp 
Player.o:		Player.cpp Player.h
			$(CC) $(CFLAGS) -c Player.cpp 
Game.o:		Game.cpp Game.h
			$(CC) $(CFLAGS) -c Game.cpp 
