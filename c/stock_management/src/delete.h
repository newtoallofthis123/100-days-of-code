#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"
#include "read.h"
#include "write.h"

void deleteStock(char *symbol){
    int numStocks;
    stock *Stocks = readStocks(&numStocks);
    for (int i = 0; i < numStocks; i++){
        if (strcmp(Stocks[i].symbol,symbol) == 0){
            Stocks[i] = Stocks[numStocks-1];
            numStocks--;
            Stocks = (stock *)realloc(Stocks,numStocks*sizeof(stock));
        }
    }
    writeStocks(Stocks, numStocks);
}