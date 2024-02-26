#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// Dice class to roll the 6 dice at a time for each player
class Dice
{
private:
   int diceValue[6];
   bool rerollDiceValue[6];
   int rollDieCount;
   int countForReRoll;
public:
   Dice()
   {
       for(int i = 0; i < 6; i++)
       {
           diceValue[i] = 0;
           rerollDiceValue[i] = false;
       }
       countForReRoll = 0;
       rollDieCount = 0;
   }
    // to roll the 6-dice
   void rollTheDice()
   {
       for(int i = 0; i < 6; i++)
       {
           diceValue[i] = (rand() % 6 + 1);
           if(diceValue[i] != 1 && diceValue[i] != 5)
           {
               rerollDiceValue[i] = true;
           }
       }
   }
    // to re-roll the dice which are non-point dices
   void reRollTheDice()
   {
       for(int i = 0; i < 6; i++)
       {
           if(rerollDiceValue[i] == true)
               diceValue[i] = (rand() % 6 + 1);
       }
   }
    // to reset the rerollDiceValues to false
   void resetReRoll()
   {
       for(int i = 0; i < 6; i++)
       {
           rerollDiceValue[i] = false;
       }
   }
    // to get the scores of the 6-dice as per the rules provided
   int getRoundScore()
   {
       int one_Count = 0, two_Count = 0, three_Count = 0, four_Count = 0, five_Count = 0, six_Count = 0;
       int score = 0;
rollDieCount = 0;
       for(int i = 0; i < 6; i++)
       {
           switch(diceValue[i])
           {
               case 1:
                   score += 100;
                   one_Count++;
                   break;
               case 2:
                   two_Count++;
                   rollDieCount++;
 
                   break;
               case 3:
                   three_Count++;
                   rollDieCount++;
 
                   break;
               case 4:
                   four_Count++;
                   rollDieCount++;
 
                   break;
               case 5:
                   score += 50;
                   five_Count++;
                   break;
               case 6:
                   six_Count++;
                   rollDieCount++;
 
                   break;
           }
       }
       if(rollDieCount == 6)
       {
           cout << "Farkle!";
           score = 0;
       }
       else
       {
           if(one_Count >= 3)
           {
               score = (score - 300) + 1000;
           }
           else if(two_Count >= 3)
           {
               score += 200;
               for(int i = 0; i < 6; i++)
               {
                   if(diceValue[i] == 2)
                   {
                       rerollDiceValue[i] = false;
                   }
               }
               rollDieCount -= 3;
           }
           else if(three_Count >= 3)
           {
               score += 300;
               for(int i = 0; i < 6; i++)
               {
                   if(diceValue[i] == 3)
                   {
                       rerollDiceValue[i] = false;
                   }
               }
               rollDieCount -= 3;
           }
           else if(four_Count >= 3)
           {
               score += 400;
               for(int i = 0; i < 6; i++)
               {
                   if(diceValue[i] == 4)
                   {
                       rerollDiceValue[i] = false;
                   }
               }
               rollDieCount -= 3;
           }
           else if(five_Count >= 3)
           {
               score = (score - 150) + 500;
           }
           else if(six_Count >= 3)
           {
               score += 600;
               for(int i = 0; i < 6; i++)
               {
                   if(diceValue[i] == 6)
                   {
                       rerollDiceValue[i] = false;
                   }
               }
               rollDieCount -= 3;
           }
       }
       return score;
   }
    // to display the 6-dice values
   void displayDice()
   {
       for(int i = 0; i < 6; i++)
       {
           cout << diceValue[i] << "   ";
       }      
   }
    // to get the rollDieCount
   int getRollDieCount()
   {
       return rollDieCount;
   }
    // to set the rollDieCount
   void setRollDieCount(int value)
   {
       rollDieCount = value;
   }
};
// Player class to hold the each round score and overall score 
class Player
{
private:
   string name;
   int score;
   int totalScore;
public:
   Player()
   {
       name = "XXXXXX";
       score = 0;
       totalScore = 0;
   }

   Player(string name)
   {
       this->name = name;
       score = 0;
       totalScore = 0;
   }
    // to set the name
   void setName(string name)
   {
       this->name = name;
   }
    // to get the name
   string getName()
   {
       return this->name;
   }
    // to add score to the total
   void addScore(int roundscore)
   {
       score = roundscore;
       totalScore += roundscore;
   }
    // to set the score
   void setScore(int score)
   {
       this->score = score;
   }
    // to retrieve the totalscore
   int getTotalScore()
   {
       return totalScore;
   }
    // to retrieve the score of each round
   int getScore()
   {
       return score;
   }
};
// FarkleGame class which holds each player's name, each round game status and initializes the game and the winner
class FarkleGame
{
private:
   Player *players;
   int countPlayers;
   Dice dice;
public:
   FarkleGame(int numPlayers)
   {
       players = new Player[numPlayers];
       countPlayers = numPlayers;
   }
 
   // to read the names of the players
   void readNamesOfPlayers()
   {
       string name;
       for(int i = 0; i < countPlayers; i++)
       {
           cout << "Enter the name of player " << (i + 1) << ": ";
           cin >> name;
           players[i].setName(name);
       }
   }
    // to roll the dice for each player until the player scores 1000 or more points
   void playersToEnterGame()
   {      
       int score = 0;
       for(int i = 0; i < countPlayers; i++)
       {
           score = 0;
           while(score < 1000)
           {
               dice.rollTheDice();              
               dice.displayDice();
               score = dice.getRoundScore();
               cout << "\t Points Scored: " << score << endl;
           }
           players[i].addScore(score);
           cout << players[i].getName() << " enters the game!" << endl<<endl;
       }
       dice.setRollDieCount(0);
       cout << "All players entered the game. Let's begin the game!" << endl<<endl;
   }
// to check whether the game score of any player reaches 10000 or more
   // and to get the index of winner
   bool winsTheGame(int *index)
   {
       for(int i = 0; i < countPlayers; i++)
       {
           if(players[i].getTotalScore() >= 10000)
           {
               *index = i;
               return true;
           }
       }
       return false;
   }
    // to play each round for a player
   void eachPlayerGame(int i)
   {
       char wouldLikeToReRoll;
       int score = 0;
       cout << players[i].getName() << " roll's the dice: " << endl;
       dice.rollTheDice();
       dice.displayDice();
       score = dice.getRoundScore();
       cout << "\t Points Scored: " << score << endl;
       players[i].setScore(score);
       if(dice.getRollDieCount() == 0)
       {
           cout << "Point-dice scoring! You have got a chance to play one more round again!" << endl;
           players[i].addScore(score);
           dice.reRollTheDice();
           dice.displayDice();
           score += dice.getRoundScore();
           cout << "\t Points Scored: " << score << endl << endl;
           players[i].setScore(score);
       }
       else if(dice.getRollDieCount() != 6)
       {
           cout << endl << "Would you like to reroll the " << dice.getRollDieCount()
               << " non-point dice? (Y/N): ";
           cin >> wouldLikeToReRoll;
           cout << endl;
           if(wouldLikeToReRoll == 'y' || wouldLikeToReRoll == 'Y')
           {
               dice.reRollTheDice();
               dice.displayDice();
               score = dice.getRoundScore();
               cout << "\t Points Scored: " << score << endl << endl;
               if(players[i].getScore() > score)
                   score = players[i].getScore();
               players[i].setScore(score);
           }
           else if(wouldLikeToReRoll == 'n' || wouldLikeToReRoll == 'N')
           {
               cout << players[i].getName() << " turn is over..." << endl << endl;
               dice.setRollDieCount(0);
           }
       }
       dice.resetReRoll();
       cout << players[i].getName() << " your score from that round: " << players[i].getScore() << endl;
       players[i].addScore(score);
       cout << "Your total score after the round: " << players[i].getTotalScore() << endl << endl;
       cout << endl << "============================================" << "============================" << endl << endl;
   }
// to play a round
   void playEachRound(int index)
   {          
       for(int i = index; i < countPlayers; i++)
       {
           eachPlayerGame(i);
       }  
   }
    // to begin the game
   void playTheGame()
   {
       int index = 0;
       while(!winsTheGame(&index))
       {
           playEachRound(0);          
       }
       int i = 0;
       int count = 0;
 
       for(i = index + 1; i < countPlayers; i++)
       {
           eachPlayerGame(i);
           count++;
       }
       if(count != countPlayers - 1)
       {
           for(i = 0; i < index; i++)
               eachPlayerGame(i);
       }
int max = 0;
        // logic to check for the winner
       for(int i = 0; i < countPlayers; i++)
       {
           if(players[i].getTotalScore()>max)
           {
               max = players[i].getTotalScore();
               index = i;
           }
       }

       cout << endl<< players[index].getName() << " wins the game!" << endl;
   }
};
// to display the rules from the text file
void displayRules()
{
   string lineInFile;
   ifstream inputfile;
   inputfile.open("FarkleRules.txt");
   while(getline(inputfile, lineInFile))
   {
       cout << lineInFile << '\n';
   }
   inputfile.close();
}

int main()
{
   srand(time(0));
    int numPlayers;

    // Display the rules
    displayRules();

    cout << "*************************************************"
         << "******************************" << endl
         << endl
         << "\t\t===== Let us start the game! =====" << endl
         << endl
         << endl
         << "Number of players would like to play the game? ";

    // Prompt the user for the number of players participating in the game
    cin >> numPlayers;

    while (numPlayers < 2 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid whole number greater than 1." << endl;
        cout << "Number of players would like to play the game? ";
        cin >> numPlayers;
    }

    FarkleGame fg(numPlayers);
    fg.readNamesOfPlayers();
    fg.playersToEnterGame();
    fg.playTheGame();

   return 0;
}