/*
CH08-320142
Problem 4.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>

using namespace std;

class Creature {
	public:
		Creature();  
		~Creature();
		void run() const;

	protected:
		int distance;
};

Creature::Creature(): distance(10)
{
    cout<<"=> Constructor Creature"<<endl;
}    

Creature::~Creature(){
    cout<<"Destructor Creture"<<endl;
}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

class Wizard : public Creature {
	public:
		Wizard();
        ~Wizard();
		void hover() const;

	private:
		int distFactor;
};
//constructor Wizard
Wizard::Wizard() : distFactor(3)
{
    cout<<"=> Constructor Wizard"<<endl;
}
//destructor wizard
Wizard::~Wizard(){
    cout<<"Destructor Wizard"<<endl;
}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

//New Class Dragon 
class Dragon : public Creature {
    public:
        Dragon();
        ~Dragon();
        void breathe() const;
    private:
        int flame;
};

//Dragon Constructor
Dragon::Dragon():flame(2)
{
    cout<<"=> Constructor Dragon"<<endl;
}
//Dragon Destructor
Dragon::~Dragon(){
    cout<<"Destructor Dragon"<<endl;
}

//Dragon Breathe
void Dragon::breathe() const
{
    cout<<"Breathe flame : "<<(flame*distance)<< " meters !\n"<<endl;
}

//New Class Treebeard
class Treebeard : public Creature {
    public:
        Treebeard();
        ~Treebeard();
        void leechSeed() const;
    private:
        int seeds;
};

//Treebeard Constructor
Treebeard::Treebeard() : seeds(4)
{
    cout<<"=> Constructor Treebeard"<<endl;
}

//Treebeard Treebeard
Treebeard::~Treebeard(){
    cout<<"DestructorTreebeard"<<endl;
}

//Treebeard Special Ability
void Treebeard::leechSeed() const {
    cout<<"The Leechseed Range : "<<(seeds*distance)<<"meters! \n";
}

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();
    
    cout<<"\nCreating a Dragon.\n";
    Dragon d;
    d.run();
    d.breathe();
    
    cout<<"\nCreating a Treebeard.\n";
    Treebeard t;
    t.run();
    t.leechSeed();

    //blankl lines
    cout<<endl<<endl;

    return 0;
} 
