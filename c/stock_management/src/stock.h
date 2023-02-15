#ifndef STOCK_H
#define STOCK_H

// Define the stock struct
typedef struct
{
    char symbol[6];
    double purchasePrice;
    int numShares;
    double currentPrice;
} stock;

#endif /* STOCK_H */
