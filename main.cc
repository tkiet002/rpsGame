#include <stdio.h>
#include <random>
#include <iostream>
// #include <string>
int main(int argc, char const *argv[])
{
    char rps[3] = {'r', 'p', 's'};
    size_t randomIndex = sizeof(rps) - 1;
    char computerMove;
    char playerMove;

    char playAgain;
    bool continuePlay = true;

    while (continuePlay)
    {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, randomIndex);
        computerMove = rps[dis(gen)];
        printf("Pick your move, R = Rock, P = Paper,S = Scissor\n");
        scanf("%s", &playerMove);
        playerMove = tolower(playerMove);

        if (playerMove == computerMove)
        {
            printf("Draw!!!!\n");
        }
        else if (
            (playerMove == 'r' && computerMove == 's') ||
            (playerMove == 'p' && computerMove == 'r') ||   
            (playerMove == 's' && computerMove == 'p'))
        {
            printf("You are Win!!\n");
        }
        else
        {
            printf("You are lose!!\n");
        }
        while (true)
        {
            printf("Do you want to continue?\n");
            scanf("%s", &playAgain);
            if (playAgain == 'y')
            {
                continuePlay = true;
                continue;
            }
            else if (playAgain == 'n')
            {
                continuePlay = false;
                break;
            }
            else
            {
                printf("Wrong Input, try again!!!\n");
            }
        }

        // else
        // {
        //     printf("Wrong input, try again!");
        //     playerMove = 'o';
        // }
        /*
        rd:      Random device. Gives some initial randomness to help initialize things.
             Think of this as the `srand(time())` in the old random (but better).

        mt19937: This is the algorithm used to generate the random number.
             It is initialized with some random value from rd. But it
             is a well know well understood random algorithm.

             Also be seperating this out into its own object.
             We don't have a central random number place. This means
             different applications can have their own unique random number stream.

             Note: If you want a random number stream. But the same stream
             every time (testing/debugging) then don't use the random
             device to initialize this object. Just use a nice normal
             integer and it will give a random stream of numbers but each
             time you run the application you get the same stream (which is useful
             for debugging when you don't actually want real randomness).


        dis:     The main issue with the old rand() is that if just gave a number.
             It was up to the user of the number to build appropriate distributions
             and to be blunt most people either got it wrong or did not bother.
             In the random library there are several built in distributions but uniform
             is a nice easy one that is often useful (and I hope obvious).
        */
    }
    return 0;
}
