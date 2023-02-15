#ifndef UPDATE_H
#define UPDATE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"
#include "read.h"
#include "write.h"

void updateStock(char *symbol)
{
    int numStocks, i=0;
    stock *stocks = readStocks(&numStocks);
    for (i = 0; i < numStocks; i++)
    {
        if (strcmp(stocks[i].symbol, symbol) == 0)
        {
            printf("Found Stock with Symbol\033[1;33m%s\033[0m\n: ", symbol);
            strcpy(stocks[i].symbol, symbol);
            printf("Enter the stock \033[1;34mPurchase Price\033[0m: ");
            scanf("%lf", &stocks[i].purchasePrice);
            printf("Enter the stock \033[1;35mNumber of Shares\033[0m: ");
            scanf("%d", &stocks[i].numShares);
            printf("Enter the stock \033[1;34mCurrent Price\033[0m:\n ");
            scanf("%lf", &stocks[i].currentPrice);
        }
    }
    writeStocks(stocks, numStocks);
}
#endif // Update_H