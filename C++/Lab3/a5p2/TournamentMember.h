/*
CH08-320142
Problem 5.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
 */

#include<cstring>
#include<string>

class TournamentMember{
    private:
        char fname[31];
        char lname[32];
        char dob[11] ;
        int age;
        std::string nationality;
        //static property location
        static std::string location;
    
    public:
        //Constructor
        TournamentMember(char fname[],char lname[],char dob[],
        int age,std::string nationality);
        
        //Destructor
        ~TournamentMember();
        

        //Setters
        void setFname(char fname[31]){
	        strcpy(this->fname,fname);
        }
        void setLname(char lname[31]){
	         strcpy(this->lname,lname);
        }
        void setDob(char dob[11]){
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
	        return fname;
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
