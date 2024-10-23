#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
    

    int SuitNum = 4;
    int FacesNum = 13;
    int CardNum = 0; // Variable to keep track of number of cards in deck
    string card = ""; // Variable to hold the card string (face and suit)

    // Create arrays for card labels
    string suits[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    string faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    // Create a vector to store the deck of cards
    vector<string> Cards;

    // Generate the deck
    for (int i = 0; i < SuitNum; i++) { // Iterate through suits
        for (int j = 0; j < FacesNum; j++) { // Iterate through faces
            card = faces[j] + " of " + suits[i]; // Combine face and suit
            Cards.push_back(card); // Add card to the vector
            CardNum++; // Increase the number of cards in the deck
        }
    }

   
    while (CardNum > 0) {
        // Generate a random number based on the number of cards left in the deck
        int RCard = rand() % CardNum;

        // Access the card at the random position
        string DrawCard = Cards.at(RCard);

        // Remove the drawn card from the vector so it can't be drawn again
        Cards.erase(Cards.begin() + RCard);

        // Decrease the number of available cards
        CardNum--;

        // Output the drawn card
        cout << DrawCard << endl;
    }

    return 0;
}

