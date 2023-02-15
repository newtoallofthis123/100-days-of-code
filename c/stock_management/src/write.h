#ifndef WRITE_H
#define WRITE_H

#include "stock.h"

// Write stocks to file
void writeStocks(stock *stocks, int numStocks)
{
    FILE *fp;
    fp = fopen("data.dat", "wb");
    fwrite(stocks, sizeof(stock), numStocks, fp);
    fclose(fp);
}

#endif /* WRITE_H */