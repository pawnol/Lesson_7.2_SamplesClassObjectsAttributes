/*
Lesson 7.2 Samples Classes, Objects, and Attributes
Pawelski
5/14/2021
Here are the samples.
*/
#include <iostream>
#include <vector>
using namespace std;

/*
This enumeration is used for the Fruit class.
*/
enum FruitName
{
    apple,
    banana,
    grape,
    orange,
    strawberry,
    watermelon
};

/*
This enumeration is used for the Monster class.
*/
enum MonsterType
{
    goblin,
    orc,
    skeleton
};

/*
Represents a car with a given make, model, year and mileage.
Currently, we will make our attributes public as this allows
us to access them outside the class. In a future lesson, we
will revisit this!
*/
class Car
{
public:
    string make;
    string model;
    int year;

private:    // cannot be accessed outside the class!
    int mileage;
};

/*
Represents a type of fruit being sold in a
grocery store. This shows how to use an enumeration
within a class. In our case, the enumeration is
outside the class so that we can easily access it
throughout the program.
*/
class Fruit
{
public:
    FruitName name;
    double weight;
    double pricePerPound;
};

/*
Represents a monster within a game.
*/
class Monster
{
public:
    MonsterType type;
    int attack;
    int defense;
};

/*
Prints the name of the passed car in the format...
year make model
*/
void printCarName(Car c)
{
    cout << c.year << " " << c.make << " " << c.model;
}

/*
This function tries to change the attributes of the
passed car object. However, since a copy is made, there
is no effect on the original.
*/
void changeCarName(Car c)
{
    c.make = "Volkswagen";
    c.model = "Jetta";
    c.year = 2014;
}

/*
This function prints the stats of the passed monster.
*/
void printMonsterStats(Monster m)
{
    cout << "Type: " << m.type << "\n";
    cout << "Attack: " << m.attack << "\n";
    cout << "Defense: " << m.defense << "\n";
}

int main()
{
    /*
    Example #1
    This shows how to create an object and set the the attributes
    of the objects. I also show how to pass an object as a parameter.
    When an object is passed to a function, a copy is passed. This
    means that any changes made to the parameter in the funciton
    have no effect on the original!
    */
    Car c1;
    c1.make = "Ford";
    c1.model = "Focus";
    c1.year = 2012;

    cout << c1.year << " " << c1.make << " " << c1.model << "\n";
    changeCarName(c1);
    printCarName(c1);
    cout << "\n\n";

    /*
    Example #2
    Here I make another car object to show you that the name
    of the object is internal and independent of the attributes.
    */
    Car ford;
    ford.make = "Dodge";
    ford.model = "RAM";
    ford.year = 2020;
    printCarName(ford);
    cout << "\n\n";

    /*
    Example #3
    This example shows how to use an variable of the enumerated
    type within a class. Please note that the enumeration is
    defined outside the class and at the top! This is to
    provide access to the enumeration within the whole program.
    */
    Fruit f1;
    f1.name = apple;
    f1.pricePerPound = 1.5;

    cout << "What is the weight of the apples in lbs >> ";
    double weight;
    cin >> weight;
    double appleSubtotal = f1.pricePerPound * weight;
    cout << "The apples will cost $" << appleSubtotal << ".";
    cout << "\n\n";

    /*
    Example #4
    This example shows how to create an array of objects.
    */
    const int MONSTER_SIZE = 3;
    Monster levelOneMonsters[MONSTER_SIZE];
    for (int i = 0; i < MONSTER_SIZE; i++)
    {
        levelOneMonsters[i].type = orc;
        levelOneMonsters[i].attack = 2;
        levelOneMonsters[i].defense = 3;
    }
    
    for (int i = 0; i < MONSTER_SIZE; i++)
    {
        printMonsterStats(levelOneMonsters[i]);
    }
    cout << "\n\n";

    /*
    Example #5
    This example shows how to create a vector of objects.
    */
    vector<Monster> monsters;
    for (int i = 0; i < 3; i++)
    {
        Monster temp;
        temp.type = skeleton;
        temp.attack = 3;
        temp.defense = 1;
        monsters.push_back(temp);
    }

    for (int i = 0; i < monsters.size(); i++)
    {
        printMonsterStats(monsters[i]);
    }
    return 0;
}
