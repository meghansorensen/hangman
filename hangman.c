#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Hangman Game
// This game will allow the user 10 tries to guess the answer.
// January 10, 2022
// Meghan Sorensen

int getRandomNumber()
{
    time_t t;
    //Go off of time to make sure you get a different random number
    srand((unsigned)time(&t));
    // Gets a random number between 0 and 19
    return rand() % 19;
}

bool checkForWinner(char progressAnswer[], char answer[])
{
    // Check for winner
    if (strcmp(progressAnswer, answer) == 0)
    {
        printf("\n\nCongrats! You have solved the hangman!\n");
        printf("Winning word is: %s\n", answer);
        return true;
    }
    else
    {
        return false;
    }
}

void printProgress(char progressAnswer[], int sizeOfAnswer)
{
    for (int j = 0; j < sizeOfAnswer; j++)
    {
        if (j == sizeOfAnswer - 1)
        {
            printf("%c", progressAnswer[j]);
        }
        else
        {
            printf("%c,", progressAnswer[j]);
        }
    }
    printf("\n");
}

void playGame(char randomWord[])
{
    // Set the string answer
    char *answer = randomWord;
    char progressAnswer[20] = {};
    bool found = false;
    int guesses = 10;
    // Prompt the user for a guess
    char guess;
    while (guesses > 0)
    {
        found = false;
        printf("Welcome to hangman, the word has %lu letters\n", strlen(answer));
        printf("Please guess one letter: ");
        scanf(" %c", &guess);
        // If it exists, print out the work with _ for un-guessed and put the correct letter in the spot
        for (int i = 0; i < strlen(answer); i++)
        {
            if (guess == answer[i])
            {
                progressAnswer[i] = guess;
                found = true;
            }
        }
        if (found)
        {
            printf("Great guess, that was in there! \nThe updated word is:\n");
            // _,_,_,e,r
            printProgress(progressAnswer, strlen(answer));
        }
        else
        {
            printf("Nice try, but it isn't in there. Try again\n");
            guesses--;
            // _,_,_,e,r
            printProgress(progressAnswer, strlen(answer));
            // Also print out the number of guesses they have left
            printf("Also, you only have %d guesses left\n", guesses);
        }
        bool winner = checkForWinner(progressAnswer, answer);
        if (winner)
        {
            return;
        }
    }
    printf("\n\nYou LOSE!\n\n");
    return;
}

int main()
{
    char *randomWords[] = {"black", "gray", "yellow", "white", "purple", "blue", "orange", "pink", "red", "gold", "silver", "green", "maroon", "aqua", "beige", "almond", "eggshell", "mauve", "violet", "brown"};
    int randomNumber = getRandomNumber();
    printf("Random Number: %d", randomNumber);
    char *randomWord = randomWords[randomNumber];
    printf("Random Word: %s", randomWord);
    playGame(randomWord);
}
