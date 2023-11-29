#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    char username[50];
    char password[50];
    double balance;
};

struct Bank {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts;
};

// Function prototypes
int createAccount(struct Bank *bank);
int login(struct Bank *bank, int *loggedInIndex);
void checkBalance(struct Bank *bank, int loggedInIndex);
void transferMoney(struct Bank *bank, int loggedInIndex);
void depositMoney(struct Bank *bank, int loggedInIndex);
void customerCare();

int main() {
    struct Bank bank;
    bank.numAccounts = 0;

    int loggedInIndex = -1;
    int choice;

    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Check Balance\n");
        printf("4. Transfer Money\n");
        printf("5. Deposit Money\n");
        printf("6. Customer Care\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&bank);
                break;

            case 2:
                if (login(&bank, &loggedInIndex)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

            case 3:
                if (loggedInIndex != -1) {
                    checkBalance(&bank, loggedInIndex);
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 4:
                if (loggedInIndex != -1) {
                    transferMoney(&bank, loggedInIndex);
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 5:
                if (loggedInIndex != -1) {
                    depositMoney(&bank, loggedInIndex);
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 6:
                customerCare();
                break;

            case 7:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

int createAccount(struct Bank *bank) {
    if (bank->numAccounts < MAX_ACCOUNTS) {
        printf("Enter username: ");
        scanf("%s", bank->accounts[bank->numAccounts].username);

        printf("Enter password: ");
        scanf("%s", bank->accounts[bank->numAccounts].password);

        bank->accounts[bank->numAccounts].balance = 0.0;
        bank->numAccounts++;

        printf("Account created successfully!\n");
        return 1; // Success
    } else {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return 0; // Failure
    }
}

int login(struct Bank *bank, int *loggedInIndex) {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < bank->numAccounts; i++) {
        if (strcmp(username, bank->accounts[i].username) == 0 && strcmp(password, bank->accounts[i].password) == 0) {
            *loggedInIndex = i;
            return 1; // Login successful
        }
    }

    return 0; // Login failed
}

void checkBalance(struct Bank *bank, int loggedInIndex) {
    printf("Balance for account %s: $%.2lf\n", bank->accounts[loggedInIndex].username, bank->accounts[loggedInIndex].balance);
}

void transferMoney(struct Bank *bank, int loggedInIndex) {
    double amount;
    char recipient[50];

    printf("Enter recipient username: ");
    scanf("%s", recipient);

    int recipientIndex = -1;
    for (int i = 0; i < bank->numAccounts; i++) {
        if (strcmp(recipient, bank->accounts[i].username) == 0) {
            recipientIndex = i;
            break;
        }
    }

    if (recipientIndex != -1) {
        printf("Enter the amount to transfer: $");
        scanf("%lf", &amount);

        if (amount > 0 && amount <= bank->accounts[loggedInIndex].balance) {
            bank->accounts[loggedInIndex].balance -= amount;
            bank->accounts[recipientIndex].balance += amount;

            printf("Transfer successful!\n");
        } else {
            printf("Invalid amount or insufficient funds.\n");
        }
    } else {
        printf("Recipient not found.\n");
    }
}

void depositMoney(struct Bank *bank, int loggedInIndex) {
    double amount;

    printf("Enter the amount to deposit: $");
    scanf("%lf", &amount);

    if (amount > 0) {
        bank->accounts[loggedInIndex].balance += amount;
        printf("Deposit successful! New balance: $%.2lf\n", bank->accounts[loggedInIndex].balance);
    } else {
        printf("Invalid amount.\n");
    }
}

void customerCare() {
    printf("Welcome to Customer Care!\n");
    printf("Please call our customer support hotline at 1-800-123-4567 for assistance.\n");
}
