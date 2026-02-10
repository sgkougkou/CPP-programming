#include <iostream>
#include <random>
using namespace std;

class demigorgon {
    public:
        demigorgon();
        int attack();
    int height;
    int weight;
    int health;
};

class demidogs {
    public:
        demidogs();
        int attack();
    int health;
};

class hive {
    public:
        hive(bool in_demigorgon); // if demigorgon exists
        int attack();
    demigorgon *demi_ptr;
    demidogs *dogs_ptr;
    int n_demidogs;
};

int main()
{
    hive h(true);
    int dmg;

    dmg=h.attack();

    cout<<"Total attack damage:"<<dmg<<endl;

    return 0;
}

demigorgon::demigorgon() {
    height = 5;
    health = 10000;
    weight = 500;
}

demidogs::demidogs() {
    health = 100;
}

int demigorgon::attack() {
    /*C++11 style*/
    mt19937 gen(random_device{}()); 
    uniform_int_distribution<int> dist(300, 500);
    return dist(gen);
}

int demidogs::attack() {
    /*C++11 style*/
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(10, 30);
    return dist(gen);
}

hive::hive(bool in_demigorgon) {
    if (in_demigorgon) {
        demi_ptr = new demigorgon;
        /*if (!demi_ptr) cout<<"Error in allocatin memory!";*/
        /*not needed in modern C++*/ 
    }
    else
        demi_ptr=NULL;

    mt19937 gen(random_device{}()); 
    uniform_int_distribution<int> dist(5, 20);
    n_demidogs=dist(gen);

    dogs_ptr = new demidogs[n_demidogs];

}

int hive::attack() {
    int damage, sum=0 , count=0;

    if(demi_ptr!=NULL) {
        damage = demi_ptr->attack();
        sum+=damage;
        cout<<"Demigorgon did "<<damage<<" points of damage."<<endl;
    }

    for(int i=0; i<n_demidogs; i++) {
        damage = dogs_ptr[i].attack(); // no need to store each attack damage individually
        sum+=damage;
        cout<<"Demidog "<<i+1<<" did "<<damage<<" points of damage."<<endl;
    }

    return sum; // total damage

}