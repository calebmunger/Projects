# Random Duck and Goose Game

## Description
This program implements a "Duck, Duck, Goose" game simulation using object-oriented programming principles. It uses dynamic memory allocation, virtual functions, and class inheritance to determine and display 
the randomly selected "Goose" among the players.

---

## Features
1. Prompts the user to enter the number of players.
2. Generates a random number to select the "Goose."
3. Dynamically allocates an array of `Player` pointers to store all players.
4. Sets most players as `Duck` objects and one as a `Goose` object (based on the randomly generated index).
5. Iterates through the player list and displays:
   - "Duck" for `Duck` objects.
   - "Goose" for the `Goose` object.
6. Cleans up dynamically allocated memory before exiting.

---

## Class Structure
- **Player**: Base class with a virtual function to differentiate between `Duck` and `Goose`.
- **Duck**: Derived class representing a player who is not the "Goose."
- **Goose**: Derived class representing the randomly selected "Goose."
