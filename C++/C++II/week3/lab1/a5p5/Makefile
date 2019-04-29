CC      = g++
OBJS    = Card.o Deck.o Game.o GenericPlayer.o Hand.o House.o Player.o
FLAGS  = -Wall

all:		blackjack

run:		blackjack
			./blackjack

blackjack:	$(OBJS) blackjack.o
			$(CC) $(OBJS) blackjack.o -o blackjack

Card.o:		Card.cpp Card.h
			$(CC) $(FLAGS) -c Card.cpp 
Deck.o:		Deck.cpp Deck.h
			$(CC) $(FLAGS) -c Deck.cpp 
GenericPlayer.o:		GenericPlayer.cpp GenericPlayer.h
			$(CC) $(FLAGS) -c GenericPlayer.cpp 
Hand.o:		Hand.cpp Hand.h
			$(CC) $(FLAGS) -c Hand.cpp 
House.o:		House.cpp House.h
			$(CC) $(FLAGS) -c House.cpp 
Player.o:		Player.cpp Player.h
			$(CC) $(FLAGS) -c Player.cpp 
Game.o:		Game.cpp Game.h
			$(CC) $(FLAGS) -c Game.cpp 
remove:		
			rm -f *.o 