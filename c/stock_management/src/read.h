#ifndef READ_H
#define READ_H
#include "stock.h"

stock *readStocks(int *numStocks)
{
    FILE *fp;
    stock *stocks;
    fp = fopen("data.dat", "rb");
    fseek(fp, 0, SEEK_END);
    *numStocks = ftell(fp) / sizeof(stock);
    fseek(fp, 0, SEEK_SET);
    stocks = (stock *)malloc(*numStocks * sizeof(stock));
    fread(stocks, sizeof(stock), *numStocks, fp);
    fclose(fp);
    return stocks;
}

#endif /* READ_H */