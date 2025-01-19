#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void provideClue(int targetNumber, int guessedNumber, int attemptCount);

int main()
{
    int guessedNumber = 0, attemptCount = 0;
    srand(time(0));
    int targetNumber = rand() % 100 + 1;
    while (guessedNumber != targetNumber)
    {
        cout << "Enter your guessing number: ";
        cin >> guessedNumber;
        if (guessedNumber != targetNumber)
        {
            provideClue(targetNumber, guessedNumber, attemptCount);
            attemptCount++;
        }
    }
    if (guessedNumber == targetNumber)
    {
        cout << "\n" << "GUESSING MATCHED WITH ORIGINAL VALUE ";
    }
}

void provideClue(int targetNumber, int guessedNumber, int attemptCount)
{
    int difference, remainder, steps, count = 0;
    guessedNumber > targetNumber ? cout << "Your guessing is too high" << endl : cout << "Your guessing is too low " << endl;
    cout << "\n";
    if (attemptCount == 1)
    {
        if (targetNumber >= 10)
        {
            cout << "Clue 1 : [It is a double digit number]" << endl << endl;
        }
    }
    if (attemptCount == 1)
    {
        if (targetNumber < 10)
        {
            cout << "Clue 1: [It is a single digit number]" << endl << endl;
        }
    }
    if ((targetNumber % 2 == 0) && (attemptCount >= 2))
    {
        cout << "Clue 2" << "\n" << "[The number is a multiple of two]" << endl << endl;
    }
    if ((targetNumber % 2 != 0) && (attemptCount >= 2))
    {
        cout << "Clue 2" << "\n" << "[The number is an odd number]" << endl << endl;
    }
    if (attemptCount >= 3)
    {
        remainder = targetNumber % 10;
        while (steps != 0)
        {
            remainder += 1;
            count++;
            if (remainder % 10 == 0)
                steps = 0;
        }
        cout << "Clue 3" << "\n" << "[The number is in the range (1 to " << targetNumber + count;
        targetNumber % 2 == 0 ? cout << " ) and a multiple of two]" : cout << ") and an odd number]" << endl << endl;
        remainder = 0;
        count = 0;
    }
    if (attemptCount >= 5)
    {
        difference = targetNumber - guessedNumber;
        cout << "[Your guess is nearby by [" << difference << "] digit(s) ahead or before the original digit]" << endl << endl;
    }
}