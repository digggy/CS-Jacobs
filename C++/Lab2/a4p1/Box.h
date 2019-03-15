/*
CH08-320142
Problem 3.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

class Box {
    private:
        double height;
        double width;
        double depth;

    public:
        //constructors
        Box();
        Box(double,double,double);
        
        //destructor
        ~Box();

        //setter
        void setHeight(int newHeight);
        void setWidth(int newWidth);
        void setDepth(int newDepth);

        //getter methods
        double getHeight();
        double getWidth();
        double getDepth();

        //Service Methods
        double volume();
};

