#ifndef DUCKDUCKGOOSE_H
#define DUCKDUCKGOOSE_H
#include <iostream>
using namespace std;

class Player 
{
public:
    virtual void print() const = 0; 
    virtual ~Player() {}; 
};
class Duck : public Player 
{
public:
    void print() const override;
};
class Goose : public Player 
{
public:
    void print() const override;
};
#endif 