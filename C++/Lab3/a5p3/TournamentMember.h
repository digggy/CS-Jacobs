/*
CH08-320142
Problem 5.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
 */

#include<cstring>
#include<string>

class TournamentMember{
    private:
        char fname[31];
        char lname[31];
        char dob[11] ;
        int age;
        std::string nationality;
        //static property location
        static std::string location;
    
    public:
        //Constructor
        TournamentMember(const char fname[31],const char lname[31],
        const char dob[11],int age,std::string nationality);
        
        ~TournamentMember();
        

        //Setters
        void setFname(const char fname[31]){
	        strcpy(this->fname,fname);
        }
        void setLname(const char lname[31]){
	         strcpy(this->lname,lname);
        }
        void setDob(const char dob[11]){
	        strcpy(this->dob,dob);
        }
        void setAge(int age){
            this->age=age;
        }
        void setNationality(std::string nationality){
            this->nationality=nationality;
        }
        static void setLocation(std::string loc){
            location=loc;
        }


        //Getters
        const char* getFname() const{
	        return fname;
        }
        const char* getLname() const {
	        return lname;
        }
        const char* getDob() const {
	        return dob;
        }
        int getAge() const {
            return age;
        }
        std::string getNationality() const{
            return nationality;
        }
        static std::string getLocation(){
            return location;
        }

        //Service Methods
        void print();

};

class Player : public TournamentMember{
    private:
        int number;
        std::string position;
        int goal;
        std::string foot;

    public:
        Player(const char fname[31],const char lname[31],
        const char dob[11],int age,std::string nationality,int number,
        std::string position,int goal,std::string foot);
        
        Player(Player& src);
        ~Player();

        //Setters
        void setNumber(int number){
            this->number=number;
        }
        void setPosition(std::string position){
            this->position=position;
        }
        void setFoot(std::string foot){
            this->foot=foot;
        }

        //Getters
        int getNumber(){
            return number;
        }
        std::string getPosition(){
            return position;
        }
        int getGoal(){
            return goal;
        }
        std::string getFoot(){
            return foot;
        }

        //Application Methods
        void print();
        //method to increase goal
        void addGoal();
};