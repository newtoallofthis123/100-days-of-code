#include <stdio.h>
#include <stdlib.h>

struct stock
{
    char symbol[10];
    float purchase_price;
    int num_shares;
    float current_price;
};

int main()
{
    // Open the file for reading
    FILE *fp = fopen("stocks.dat", "rb");
    if (fp == NULL)
    {
        // handle error opening file
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Calculate the number of records in the file
    int num_records = file_size / sizeof(struct stock);

    // Allocate memory for the records
    struct stock *stocks = malloc(num_records * sizeof(struct stock));

    // Read the records from the file
    fread(stocks, sizeof(struct stock), num_records, fp);

    // Close the file
    fclose(fp);

    // Process the records as needed
    for (int i = 0; i < num_records; i++)
    {
        printf("Symbol: %s\n", stocks[i].symbol);
        printf("Purchase price: %.2f\n", stocks[i].purchase_price);
        printf("Number of shares: %d\n", stocks[i].num_shares);
        printf("Current price: %.2f\n", stocks[i].current_price);
        printf("\n");
    }

    // Free the memory allocated for the records
    free(stocks);

    return 0;
}
