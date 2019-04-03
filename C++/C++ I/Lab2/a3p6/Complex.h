/*
CH08-320142
Problem 3.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

class Complex {
    private:
        double real;
        double img;
   
    public:
        Complex();
        Complex(double real,double img);
        Complex(Complex &obj);
        ~Complex();

        //setters
        void setReal(double newReal);
        void setImg(double newImg);

        //getters
        double getReal();
        double getImg();

        //service methods
        void print();
        Complex add(Complex& obj); 
        Complex sub(Complex& obj); 
        Complex mul(Complex& obj);
        Complex conjugate();

};
