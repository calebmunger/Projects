#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DUCKDUCKGOOSE.h"
using namespace std;

void Duck::print() const 
{
    cout << "Duck" << endl;
}
void Goose::print() const 
{
    cout << "Goose" << endl;
}

int main() {
    
    srand(time(0)); 

    int numPlayers;
    cout << "Enter the number of players: ";
    cin >> numPlayers;


    int randomNum = rand() % numPlayers; 

    Player** players = new Player*[numPlayers]; 


    for (int i = 0; i < numPlayers; i++) 
    {
        if (i == randomNum) 
        {
            players[i] = new Goose();
        } 
        else 
        {
            players[i] = new Duck();
        }
    }

    for (int i = 0; i < numPlayers; i++) 
    {
        players[i]->print();
    }

    for (int i = 0; i < numPlayers; i++) 
    {
        delete players[i];
    }
    delete[] players;

    return 0;
}
