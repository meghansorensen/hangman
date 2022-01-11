#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hangman Game
// This game will allow the user 10 tries to guess the answer.
// January 10, 2022
// Meghan Sorensen

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

void printProgress(char progressAnswer[])
{
    for (int j = 0; j < strlen(progressAnswer); j++)
    {
        if (j == strlen(progressAnswer) - 1)
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

void playGame()
{
    // Set the string answer
    char answer[] = "paul";
    char progressAnswer[] = "____";
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
            printProgress(progressAnswer);
        }
        else
        {
            printf("Nice try, but it isn't in there. Try again\n");
            guesses--;
            // _,_,_,e,r
            printProgress(progressAnswer);
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
    playGame();
}
