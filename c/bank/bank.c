#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct transc
{
    float amt;
    struct transc *prev;
    struct transc *next;
    char s;
};
struct accnt
{
    char first_name[15];
    char last_name[15];
    char father_name[20];
    char birthdate[3];
    char birthmonth[3];
    char birthyear[5];
    char ph_no[12];
    char accnt_no[15];
    char aadhaar[15];
    float balance;
    char date[12];
    struct transc *transctions;
};
typedef struct accnt cust;
struct custlinks
{
    struct custlinks *prev;
    cust details;
    struct custlinks *next;
} *head = NULL;
typedef struct custlinks data;
int count = 0;
void display_accnts()
{
    data *temp = head;
    if (temp == NULL)
        printf("NO ACCOUNTS FOUND\n");
    else
    {
        while (temp != NULL)
        {
            printf("ACCOUNTANT FULLNAME : %s %s\n", temp->details.first_name, temp->details.last_name);
            printf("ACCOUNT NUMBER      : %s\n", temp->details.accnt_no);
            printf("ACCOUNT BALANCE     : %.2frs\n", temp->details.balance);
            printf("__________________________________________\n");
            temp = temp->next;
        }
    }
}
void display(data *temp)
{
    printf("\t\tYOUR BANK DETAILS\n");
    printf("\tACCOUNT OPENED ON   : %s\n", temp->details.date);
    printf("\tACCOUNTANT FULLNAME : %s %s\n", temp->details.first_name, temp->details.last_name);
    printf("\tACCOUNT NUMBER      : %s\n", temp->details.accnt_no);
    printf("\tACCOUNT BALANCE     : %.2frs\n", temp->details.balance);
    printf("\tFATHER NAME         : %s\n", temp->details.father_name);
    printf("\tDATE OF BIRTH       : %s-%s-%s\n", temp->details.birthdate, temp->details.birthmonth, temp->details.birthyear);
    printf("\tPHONE NUMBER        : %s\n", temp->details.ph_no);
}
data *find_acc(data *temp, char *acc)
{
    if (temp == NULL)
    {
        printf("\tNO ACCOUNT FOUND\n");
        return NULL;
    }
    else
    {
        while (temp->next != NULL && strcmp(temp->details.accnt_no, acc) != 0)
            temp = temp->next;
        if (temp == NULL)
        {
            printf("\tNO ACCOUNT FOUND\n");
            return NULL;
        }
        else
            return temp;
    }
}
void deposit()
{
    system("clear");
    char acc[15];
    data *ptr = head;
    struct transc *temp;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        temp = (struct transc *)malloc(sizeof(struct transc));
        while (ptr->details.transctions->next != NULL)
            ptr->details.transctions = ptr->details.transctions->next;
        printf("\tENTER AMOUNT TO DEPOSIT : \n");
        scanf("%f", &temp->amt);
        ptr->details.transctions->next = temp;
        temp->prev = ptr->details.transctions;
        temp->next = NULL;
        ptr->details.balance += temp->amt;
        temp->s = '+';
        printf("\033[1;32m\t%.2frs IS CREDITED INTO YOUR ACCOUNT\033[0m\n", temp->amt);
        printf("\tAVAILABLE BALANCE : %.2frs\n", ptr->details.balance);
    }
}
void withdrawl()
{
    system("clear");
    char acc[15];
    float amunt;
    data *ptr = head;
    struct transc *temp;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        while (ptr->details.transctions->next != NULL)
            ptr->details.transctions = ptr->details.transctions->next;
        printf("\tENTER AMOUNT TO WITHDRAW : \n");
        scanf("%f", &amunt);
        if (amunt < ptr->details.balance)
        {
            temp = (struct transc *)malloc(sizeof(struct transc));
            temp->amt = amunt;
            ptr->details.transctions->next = temp;
            temp->prev = ptr->details.transctions;
            temp->next = NULL;
            ptr->details.balance -= temp->amt;
            temp->s = '-';
            printf("\033[1;31m\t%.2frs IS DEBITED SUCCESSFULLY FROM YOUR ACCOUNT\033[0m\n", amunt);
            printf("\tAVAILABLE BALANCE : %.2frs\n", ptr->details.balance);
        }
        else
            printf("\tNO SUFFICIENT BALANCE\n");
    }
}
void tranc_hist()
{
    system("clear");
    char acc[15];
    data *ptr = head;
    struct transc *temp;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        printf("\tTRANSCATION DETAILS OF ACCOUNT NUMBER : %s \n", acc);
        temp = ptr->details.transctions;
        while (temp != NULL)
        {
            if (temp->s == '+')
            {
                printf("\033[1;32m\t%c %.2f\033[0m\n", temp->s, temp->amt);
            }
            else{
                printf("\033[1;31m\t%c %.2f\033[0m\n", temp->s, temp->amt);
            }
            temp = temp->next;
        }
    }
}
void check_balance()
{
    system("clear");
    char acc[15];
    data *ptr = head;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        printf("\t\tBALANCE AVAILABLE :: \n\tACCOUNT NUMBER : %s \n\tACCOUNT HOLDER : %s %s \n\tAVAILABLE BALANCE : %.2frs\n", acc, ptr->details.first_name, ptr->details.last_name, ptr->details.balance);
    }
}
void delete_acc()
{
    system("clear");
    char acc[15];
    float amunt;
    data *ptr = head, *del_acc;
    struct transc *temp;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        del_acc = ptr;
        printf("\tAVAILABLE BALANCE IS %.2frs\n", del_acc->details.balance);
        if ((int)ptr->details.balance != 0)
        {
            printf("\t%.2frs IS RECEIVED BY ACCOUNT HOLDER %s %s\n", ptr->details.balance, ptr->details.first_name, ptr->details.last_name);
        }
        else
            printf("\tBALANCE IS 0.00rs,NO AMOUNT TO WITHDRAW\n");
        if (ptr == head)
        {
            if (ptr->next == NULL)
                head = NULL;
            else
            {
                head = ptr->next;
                head->prev = NULL;
            }
        }
        else
        {
            ptr->prev->next = ptr->next;
            if (ptr->next != NULL)
                ptr->next->prev = ptr->prev;
        }
    }
    free(del_acc);
    printf("\t*ACCOUNT SUCCESSFULLY DELETED*\n");
}
void addcustomer()
{
    int amunt;
    system("cls");
    cust user;
    count++;
    printf("Enter Your FIRST NAME:: ");
    scanf(" %[^\n]", user.first_name);
    printf("Enter Your LAST NAME:: ");
    scanf(" %[^\n]", user.last_name);
    printf("Enter Your FATHER NAME:: ");
    scanf(" %s", user.father_name);
    printf("ENTER YOUR DOB\nDATE MONTH YEAR\n ");
    scanf(" %s %s %s", user.birthdate, user.birthmonth, user.birthyear);
    printf("\nEnter Your PHONE NUMBER::\n ");
    scanf(" %[^\n]", user.ph_no);
    printf("Enter Your AADHAAR NUMBER::\n ");
    scanf(" %[^\n]", user.aadhaar);
    char d[3];
    char *m = __DATE__;
    strcpy(user.date, m);
    sprintf(d, "%d", count);
    strcpy(user.accnt_no, "");
    strcat(user.accnt_no, "567843219");
    strcat(user.accnt_no, d);
    printf("Please DEPOSIT INITIAL amount:: ");
    user.transctions = (struct transc *)malloc(sizeof(struct transc));
    scanf("%f", &user.transctions->amt);
    user.balance = user.transctions->amt;
    user.transctions->next = user.transctions->prev = NULL;
    user.transctions->s = '+';
    data *new_customer;
    new_customer = (data *)malloc(sizeof(data));
    new_customer->prev = new_customer->next = NULL;
    new_customer->details = user;
    system("clear");
    display(new_customer);
    printf("\t\tYOUR BANK DETAILS\n");
    if (head == NULL)
        head = new_customer;
    else
    {
        data *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_customer;
    }
    printf("\n\033[1;32m\t\t\t*ACCOUNT SUCCESSFULLY CREATED*\033[0m\n");
}
void edit_details()
{
    system("cls");
    char acc[15];
    int ch;
    data *ptr = head;
    printf("\tENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s", acc);
    ptr = find_acc(ptr, acc);
    if (ptr != NULL)
    {
        display(ptr);
        printf("\tWHAT DO YOU WANT TO UPDATE\n");
        printf("\t1.FIRST NAME\n\t2.LAST NAME\n\t3.PHONE NUMBER\n\t4.Date of birth\n");
        printf("ENTER YOUR CHOICE TO EDIT YOUR DETAILS\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter first name want to change : ");
            scanf(" %[^\n]", ptr->details.first_name);
            break;
        case 2:
            printf("Enter last name want to edit : ");
            scanf(" %s", ptr->details.last_name);
            break;
        case 3:
            printf("Enter new PHONE NUMBER : ");
            scanf(" %s", ptr->details.ph_no);
            break;
        case 4:
            printf("Enter new date of birth want to change : ");
            scanf(" %s %s %s", ptr->details.birthdate, ptr->details.birthmonth, ptr->details.birthyear);
            break;
        }
        system("clear");
        printf("UPDATED DETAILS");
        display(ptr);
    }
}
int main()
{
    int ch;
    char acc[15];
    printf("\033[1;31m ____    _    _   _ _  __\033[0m\n");
    printf("\033[1;32m| __ )  / \\  | \\ | | |/ /\033[0m\n");
    printf("\033[1;33m|  _ \\ / _ \\ |  \\| | ' /\033[0m\n");
    printf("\033[1;32m| |_) / ___ \\| |\\  | . \\\033[0m\n");
    printf("\033[1;31m|____/_/   \\_\\_| \\_|_|\\_\\\n\033[0m\n");
    printf("\033[1;36m========================\033[0m\t\n\n");
    printf("\033[1;35m*WELCOME TO OUR BANK SERVICES*\033[0m\n");
    while (1)
    {
        printf("\n1.New account\n2.DEPOSIT\n3.WITHDRAWL\n4.CHECK TRANSACTION HISTORY\n");
        printf("5.BALANCE ENQUIRY\n6.DELETE ACCOUNT\n7.DISPLAY ALL ACCOUNTS\n8.EDIT DETAILS\n9.DISPLAY MY ACCOUNT DETAILS\n");
        printf("\n\033[1;33m=>  Enter your choice\n\033[0m");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addcustomer();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdrawl();
            break;
        case 4:
            tranc_hist();
            break;
        case 5:
            check_balance();
            break;
        case 6:
            delete_acc();
            break;
        case 7:
            display_accnts();
            break;
        case 8:
            edit_details();
            break;
        case 9:
            data *ptr = head;
            scanf(" %s", acc);
            ptr = find_acc(ptr, acc);
            if (ptr != NULL)
                display(ptr);
        default:
            printf("\tINVALID CHOICE\n");
        }
    }
    return 0;
}