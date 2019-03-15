/*
CH08-320142
Problem 4.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

class Creature {
	public:
		Creature();
        ~Creature();  
		void run() const;

	protected:
		int distance;
};

class Wizard : public Creature {
	public:
		Wizard();
        ~Wizard();
		void hover() const;

	private:
		int distFactor;
};

//New Class Dragon 
class Dragon : public Creature {
    public:
        Dragon();
        ~Dragon();
        void breathe() const;
    private:
        int flame;
};

//New Class Treebeard
class Treebeard : public Creature {
    public:
        Treebeard();
        ~Treebeard();
        void leechSeed() const;
    private:
        int seeds;
};

