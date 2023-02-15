#include <stdio.h>
#include <stdlib.h>
#include "write.h"
#include "read.h"
#include "delete.h"
#include "update.h"

int main()
{
    printf(
        "\033[1;31m _____ _____ _____ _____  _   ____   __\033[0m\n"
        "\033[1;31m/  ___|_   _|  _  /  __ \\| | / /\\ \\ / /\033[0m\n"
        "\033[1;35m\\ `--.  | | | | | | /  \\/| |/ /  \\ V / \033[0m\n"
        "\033[1;35m `--. \\ | | | | | | |    |    \\   \\ /  \033[0m\n"
        "\033[1;33m/\\__/ / | | \\ \\_/ / \\__/\\| |\\  \\  | |  \033[0m\n"
        "\033[1;33m\\____/  \\_/  \\___/ \\____/\\_| \\_/  \\_/\033[0m\n");
    printf("\033[1;32mWelcome to the Stock Portfolio Manager\033[0m\n");
    int option;
    printf("1. Add stocks\n"    // Create
           "2. View stocks\n"   // Read
           "3. Update stock\n" // Update
           "4. Delete stock\n" // Delete
           "5. Exit\n");
    while(option != 5){
        printf("\033[1;36mEnter option from the menu: \033[0m\n");
        scanf("%d", &option);
        if (option == 1)
        {
            int numStocks, numFlag;
            printf("How many stocks do you want to enter: ");
            scanf("%d", &numFlag);
            stock *Stocks = readStocks(&numStocks);
            stock stocks[100];
            int i = 0;
            for (i = 0; i < numStocks; i++)
            {
                stocks[i] = Stocks[i];
            }
            printf("\033[1;31mAdding Stock Options\033[0m\n");
            for (i = numStocks; i < numStocks + numFlag; i++)
            {
                printf("Enter the stock \033[1;33mSymbol\033[0m: ");
                scanf("%s", &stocks[i].symbol);
                printf("Enter the stock \033[1;34mPurchase Price\033[0m: ");
                scanf("%lf", &stocks[i].purchasePrice);
                printf("Enter the stock \033[1;35mNumber of Shares\033[0m: ");
                scanf("%d", &stocks[i].numShares);
                printf("Enter the stock \033[1;34mCurrent Price\033[0m: ");
                scanf("%lf", &stocks[i].currentPrice);
                printf("\033[1;36mAdding %s to the database...\033[0m\n", stocks[i].symbol);
            }
            printf("Updating the database");
            for (int i = 0; i < numStocks + numFlag; i++)
            {
                printf("\033[1;36m.\033[0m");
            }
            printf("\n");
            printf("\033[1;32mSuccessfully Added to Database\033[0m\n");
            writeStocks(stocks, numStocks + numFlag);
        }
        else if (option == 2)
        {
            int numStocks;
            stock *Stocks = readStocks(&numStocks);
            float totalProfit = 0;
            printf("Viewing the database");
            for (int i = 0; i < 3; i++)
            {
                printf("\033[1;36m.\033[0m");
            }
            printf("\n");
            for (int i = 0; i < numStocks; i++)
            {
                float difference = (Stocks[i].currentPrice - Stocks[i].purchasePrice) * Stocks[i].numShares;
                totalProfit = totalProfit + difference;
                printf("\033[1;36m--------------------------\033[0m\n");
                printf("Name of the Stock: \033[1;33m%s\033[0m\n", Stocks[i].symbol);
                printf("Purchase Price: \033[1;34m%.2f\033[0m\n", Stocks[i].purchasePrice);
                printf("Number of Shares: \033[1;35m%d\033[0m\n", Stocks[i].numShares);
                printf("Current Price: \033[1;34m%.2f\033[0m\n", Stocks[i].currentPrice);
                if (difference > 0)
                {
                    printf("Profit: \033[1;32m%.2f\033[0m\n", difference);
                }
                else
                {
                    printf("Loss: \033[1;31m%.2f\033[0m\n", difference);
                }
                printf("\033[1;36m--------------------------\033[0m\n");
            }
            if (totalProfit > 0)
            {
                printf("Total Profit:\033[1;32m %.2f INR\033[0m\n", totalProfit);
            }
            else
            {
                printf("Total Loss:\033[1;31m %.2f INR\033[0m\n", totalProfit);
            }
            // Free memory
            free(Stocks);
        }
        else if (option == 4)
        {
            printf("\033[1;31mDeleting Stock Options\033[0m\n");
            printf("Enter the \033[1;31mSymbol\033[0m of the stock you want to delete: ");
            char symbol[6];
            scanf("%s", &symbol);
            deleteStock(symbol);
        }
        else if (option == 3)
        {
            printf("\033[1;mUpdating Stock Options\033[0m\n");
            printf("Enter the \033[1;31mSymbol\033[0m of the stock you want to update: ");
            char symbol[6];
            scanf("%s", &symbol);
            updateStock(symbol);
        }
        else if (option == 5)
        {
            printf("\033[1;31mGracefully Exiting...\033[0m");
            exit(0);
        }
        else
        {
            printf("\033[1;31mInvalid Option\033[0m\n");
            continue;
        }
    }
    return 0;
}
