#include <stdio.h>
#include <stdlib.h>
#include "write.h"
#include "read.h"

int main()
{
    // Define 5 stocks
    stock AAPL = {"AAPL", 125.50, 100, 130.00};
    stock TSLA = {"TSLA", 750.00, 50, 780.00};
    stock AMZN = {"AMZN", 3000.00, 10, 3100.00};
    stock MSFT = {"MSFT", 240.00, 75, 250.00};
    stock GOOG = {"GOOG", 2000.00, 25, 2050.00};

    // Write stocks to file
    stock stocks[5] = {AAPL, TSLA, AMZN, MSFT, GOOG};
    writeStocksToFile(stocks, 5);

    int numStocks;
    stock *readStocks = readStocksFromFile(&numStocks);

    for (int i = 0; i < numStocks; i++)
    {
        printf("%s: $%.2f, %d shares, current price $%.2f\n",
               readStocks[i].symbol, readStocks[i].purchasePrice,
               readStocks[i].numShares, readStocks[i].currentPrice);
    }

    // Free memory
    free(readStocks);

    return 0;
}
