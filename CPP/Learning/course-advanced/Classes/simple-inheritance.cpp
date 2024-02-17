// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-04
#include <cstdio>
#include <string>
using namespace std;

//Fur class
class Fur {
    string _quality;
    Fur(){}

    protected:
        Fur(const string & f): _quality(f){}
    
    public:
        const string & quality() const {return _quality;}

};
// Base class
class Animal {
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){};
protected:
    // protected constructor for use by derived classes
    Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}

friend class Bird; // if there is a Bird class, it will have access to all the private members
friend const string & get_animal_name(const Animal &);
public:
    virtual void speak() const; //indcate that it will be overloaded, needed for some caveats
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
    virtual ~Animal(){} // needed because of the virtual speak()
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int walked;
public:
    Dog( string n ) : Animal(n, "dog", "woof"), walked(0) {};
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
class Cat : public Animal, public Fur {
    int petted;
public:
    Cat( string n ) : Animal(n, "cat", "meow"), Fur("silky"), petted(0) {};
    int pet() { return ++petted; }
    //polymorphism
    void speak() const {puts("purrr!!!");}
};

// Pig class - derived from Animal
class Pig : public Animal {
    int fed;
public:
    Pig( string n) : Animal(n, "pig", "oink"), fed(0) {};
    string latin() const {return Animal::name() + "-anis";} //simply name() would work if not overloaded anywehere else

    int feed() { return ++fed; }
};


const string & get_animal_name(const Animal & a){
    return a._name;
}
int main( int argc, char ** argv ) {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the pig has been fed %d times\n", p.feed());

    Animal *ap[] = {&d, &c, &p};
    //overloaded speak() will be called for the cat due to the 'virtual' keyword
    for(auto p: ap){
        p->speak();
    }
}
