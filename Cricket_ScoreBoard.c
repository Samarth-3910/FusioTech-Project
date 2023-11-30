#include <stdio.h>

typedef struct {
    char name[50];
    int runs;
    int wickets;
    float overs;
} Inning;

int main() {
    Inning inning1 = {"TeamA", 0, 0, 0.0};
    Inning inning2 = {"TeamB", 0, 0, 0.0};

    // Simulate match - Update scores
    inning1.runs += 150;
    inning1.wickets += 5;
    inning1.overs += 20.3;

    inning2.runs += 130;
    inning2.wickets += 6;
    inning2.overs += 18.2;

    // Print match stats
    printf("\n----------------------------------\n");
    printf("           MATCH STATS            \n");
    printf("----------------------------------\n");

    printf("Inning 1 - %s:\n", inning1.name);
    printf("Runs: %d\n", inning1.runs);
    printf("Wickets: %d\n", inning1.wickets);
    printf("Overs: %.1f\n", inning1.overs);

    printf("\nInning 2 - %s:\n", inning2.name);
    printf("Runs: %d\n", inning2.runs);
    printf("Wickets: %d\n", inning2.wickets);
    printf("Overs: %.1f\n", inning2.overs);

    // Print runs scored
    printf("\n----------------------------------\n");
    printf("          RUNS SCORED             \n");
    printf("----------------------------------\n");

    printf("%s - %d runs for %d wickets in %.1f overs\n", inning1.name, inning1.runs, inning1.wickets, inning1.overs);
    printf("%s - %d runs for %d wickets in %.1f overs\n", inning2.name, inning2.runs, inning2.wickets, inning2.overs);

    // Show results
    printf("\n----------------------------------\n");
    printf("             RESULTS              \n");
    printf("----------------------------------\n");

    if (inning1.runs > inning2.runs) {
        printf("%s wins by %d runs!\n", inning1.name, inning1.runs - inning2.runs);
    } else if (inning1.runs < inning2.runs) {
        printf("%s wins by %d runs!\n", inning2.name, inning2.runs - inning1.runs);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
