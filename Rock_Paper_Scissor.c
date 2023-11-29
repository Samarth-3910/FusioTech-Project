#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player, computer, playerWins = 0, computerWins = 0;
    srand(time(NULL));

    printf("Rock (1), Paper (2), Scissors (3) - Enter your choice (0 to quit): ");
    scanf("%d", &player);

    while (player != 0) {
        computer = rand() % 3 + 1;

        printf("You chose: %s\n", (player == 1) ? "Rock" : (player == 2) ? "Paper" : "Scissors");
        printf("Computer chose: %s\n", (computer == 1) ? "Rock" : (computer == 2) ? "Paper" : "Scissors");

        if (player == computer) {
            printf("It's a tie!\n");
        } else if ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2)) {
            printf("You win!\n");
            playerWins++;
        } else {
            printf("Computer wins!\n");
            computerWins++;
        }

        printf("Rock (1), Paper (2), Scissors (3) - Enter your choice (0 to quit): ");
        scanf("%d", &player);
    }

    printf("Total player wins: %d\n", playerWins);
    printf("Total computer wins: %d\n", computerWins);

    if (playerWins > computerWins) {
        printf("You are the overall winner!\n");
    } else if (playerWins < computerWins) {
        printf("Computer is the overall winner!\n");
    } else {
        printf("It's a tie overall!\n");
    }

    return 0;
}
