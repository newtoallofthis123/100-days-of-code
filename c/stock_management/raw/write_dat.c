#include <stdio.h>

struct stock
{
    char symbol[10];
    float purchase_price;
    int num_shares;
    float current_price;
};

int main()
{
    // create some stock records
    struct stock stocks[3];
    sprintf(stocks[0].symbol, "AAPL");
    stocks[0].purchase_price = 127.14;
    stocks[0].num_shares = 100;
    stocks[0].current_price = 140.99;

    sprintf(stocks[1].symbol, "GOOG");
    stocks[1].purchase_price = 1822.68;
    stocks[1].num_shares = 50;
    stocks[1].current_price = 2103.33;

    sprintf(stocks[2].symbol, "AMZN");
    stocks[2].purchase_price = 3019.79;
    stocks[2].num_shares = 25;
    stocks[2].current_price = 3467.42;

    // open the file for writing
    FILE *fp = fopen("stocks.dat", "wb");
    if (fp == NULL)
    {
        printf("Error opening file for writing.");
        return 1;
    }

    // write the records to the file
    int num_records = 3;
    fwrite(stocks, sizeof(struct stock), num_records, fp);

    // close the file
    fclose(fp);

    return 0;
}
