#ifndef LIBRARY
#define LIBRARY .H

// personal Library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SIZE 100 // defines
#define Cpf_num 17

// structs

typedef struct
{
    char name[MAX_SIZE];
    char passengers[MAX_SIZE];
    int day, mth, age, hour, min;
    int status;
} Basicfly;

typedef struct
{
    char num[MAX_SIZE];
    char flynum[MAX_SIZE];
    char CPF[Cpf_num];
    char name[MAX_SIZE];
    char sex;
    int day, mth, age;
    int status;
} Reserve;

// functions

int isDigit(char plate[], int startPosition, int stopPosition)
{ // verify if the caracter one is a digit
    int i;
    for (i = startPosition; i < stopPosition; i++)
    {
        if (plate[i] < 48 || plate[i] > 57)
        {             // see on ascii
            return 0; //false
        }
    }
    return 1; //true
}

int verifyname(char board[])
{ // verify if the Flight serie is correct;
    int b;
    b = strlen(board); // calculate the occuped part from array
    if (b == 8)
    { // if it is equal 8,
        if (board[0] == 'J' && board[1] == 'E' && board[2] == 'B' && board[3] == '-' && isDigit(board, 4, 7) == 1)
        {             // see if the letters are the required one;
            return 0; //true
        }
        else
            return 1; //false
    }
    else
        return 1; //false
}

int verifypassengers(char board[])
{
    if (board[0] == 48 && board[1] == 48 && board[2] == 48) // See on ASCII if the number is equal 0
    {
        return 0;
    }
    return 1;
}

int verifyreserve(char board[])
{ // Verify if the reserve if correct
    int b;
    b = strlen(board);
    if (b == 9)
    {
        if (board[0] == 'G' && board[1] == 'B' && board[2] == '-' && isDigit(board, 3, 9) == 1)
        { // verify reserve
            return 0;
        }
        return 1;
    }
    return 1;
}

int verifycpf(char board[])
{
    int cpflen, i, j = 0;
    int cpfbody[12], dig1 = 0, dig2 = 0;

    cpflen = strlen(board);
    if (cpflen != 14)
    { //verify the cpf length
        return 0;
    }
    if (isdigit(board[0]) == 0 || isdigit(board[1]) == 0 ||
        isdigit(board[2]) == 0 || board[3] != '.' || isdigit(board[4]) == 0 ||
        isdigit(board[5]) == 0 || isdigit(board[6]) == 0 || board[7] != '.' ||
        isdigit(board[8]) == 0 || isdigit(board[9]) == 0 || isdigit(board[10]) == 0 ||
        board[11] != '-' || isdigit(board[12]) == 0 || isdigit(board[13]) == 0)
    {
        return 0;
    }
    else
    {

        for (i = 0; i < 14; i++)
        {
            if (i != 3 && i != 7 && i != 11)
            {
                cpfbody[j] = board[i] - '0'; //char to int
                j = j + 1;
            }
        }

        if (cpfbody[0] == cpfbody[1] && cpfbody[1] == cpfbody[2] && cpfbody[2] == cpfbody[3] && cpfbody[3] == cpfbody[4] && cpfbody[4] == cpfbody[5] && cpfbody[5] == cpfbody[6] && cpfbody[6] == cpfbody[7] && cpfbody[7] == cpfbody[8] && cpfbody[8] == cpfbody[9] && cpfbody[9] == cpfbody[10])
        { //equal numbers on cpf body
            return 0;
        }

        for (i = 0; i < 9; i++)
        { //see the frist digit
            dig1 = dig1 + cpfbody[i] * (10 - i);
        }

        dig1 = (dig1 * 10) % 11;

        if (dig1 == 10)
        {
            dig1 = 0;
        }
        if (dig1 != cpfbody[9])
        {
            return 0;
        }
        else
        { // verify the second digit

            for (i = 0; i < 10; i++)
            {
                dig2 = dig2 + cpfbody[i] * (11 - i);
            }

            dig2 = (dig2 * 10) % 11;

            if (dig2 == 10)
            {
                dig2 = 0;
            }
            if (dig2 == cpfbody[10])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int verifybirth(int day, int mth, int age)
{
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    if (age < 1900)
    {
        return 0;
    }
    if (age > (tm.tm_year + 1900))
    { // if the year is higher than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth > (tm.tm_mon + 1))
    { // if the month is higher than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth == (tm.tm_mon + 1) && day > tm.tm_mday)
    { // if the day is higher than the actual
        return 0;
    }

    if (mth <= 0 || mth >= 13 || day <= 0 || day > 31 || age == 0)
    { // veirfy if the date is basically correct
        return 0;
    }

    if ((age % 4 != 0 || (age % 100 == 0 && age % 400 != 0)) && mth == 2 && day > 28)
    { // verify if it is a leap year
        return 0;
    }

    if ((mth == 4 || mth == 6 || mth == 9 || mth == 11) && (day > 30))
    { // 30 day month
        return 0;
    }

    if (mth == 2 && day > 29)
    { // february
        return 0;
    }

    return 1;
}

int verifysex(char board)
{
    if (board == 'W')
    {
        return 0; // return 0 if the person is a woman
    }
    if (board == 'M')
    {
        return 0; // return 0 if the person is a man
    }
    return 1; // return 1 if the person is neither a woman nor man
}

int searchpersoncpf(FILE *database, char search[MAX_SIZE])
{
    Reserve person;

    fseek(database, 0, SEEK_SET); //define the began of read

    while (!feof(database))
    {
        fread(&person, sizeof(Reserve), 1, database);
        if (strstr(search, person.CPF) != NULL)
        {
            return 1; // found the search string
        }
    }
    return 0; // not found the string
}

int searchpersonfunction(FILE *database, char search[MAX_SIZE])
{
    Reserve person;
    fseek(database, 0, SEEK_SET); //define the began of read

    while (!feof(database))
    {
        fread(&person, sizeof(Reserve), 1, database);
        if (strstr(search, person.num) != NULL)
        {
            return 1; // found the search string
        }
    }
    return 0; // not found the string
}

int searchfligthfunction(FILE *database, char search[MAX_SIZE])
{
    Basicfly fly;

    fseek(database, 0, SEEK_SET); //define the began of read
    while (!feof(database))
    {
        fread(&fly, sizeof(Basicfly), 1, database);
        if (strstr(search, fly.name) != NULL)
        {
            return 1; // found the search string
        }
    }
    return 0; // not found the string
}

int verifypercentage(FILE *database, FILE *database2, char search[MAX_SIZE])
{
    Reserve person;
    Basicfly fly;
    int passengers_counter = 0, passengerson, percent;

    fseek(database2, 0, SEEK_SET);
    while (fread(&person, sizeof(Reserve), 1, database2) != 0) // count the number os passengers
    {
        if (strcmp(person.flynum, search) == 0 && person.status == 1)
        {
            passengers_counter++; // increment
        }
    }

    fseek(database, 0, SEEK_SET);
    while (fread(&fly, sizeof(Basicfly), 1, database) != 0) // extract the number of passengers allowed in fligth
    {
        if (strstr(fly.name, search) != NULL)
        {
            passengerson = atof(fly.passengers);
            percent = (float)passengers_counter / passengerson;
        }
    }
    return percent; // percent
}

FILE *Open_file(char path[MAX_SIZE], char mode[MAX_SIZE])
{ // open file
    FILE *database;
    database = fopen(path, mode);

    if (database == NULL)
    { // if file doesnt exist or it isnt opening, close the program
        system("cls");
        printf("Creating the file ....\n");
        database = fopen(path, "w+b"); // create file
    }

    return database; // return file oppened
}

FILE *Open_fileaux(char path[MAX_SIZE], char mode[MAX_SIZE])
{ // open file
    FILE *database;
    database = fopen(path, mode);

    if (database == NULL)
    { // if file doesnt exist or it isnt opening, close the program
        system("cls");
        printf("Creating the file ....\n");
        database = fopen(path, "w+b"); // create file
    }

    return database; // return file oppened
}

int verifydate(int day, int mth, int age, int hour, int min)
{ // Verify if the date is valid
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    if (age < (tm.tm_year + 1900))
    { // if the year is less than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth < (tm.tm_mon + 1))
    { // if the month is less than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth == (tm.tm_mon + 1) && day < tm.tm_mday)
    { // if the day is less than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth == (tm.tm_mon + 1) && day == tm.tm_mday && hour < tm.tm_hour)
    { // if the hour is less than the actual
        return 0;
    }

    if (age == (tm.tm_year + 1900) && mth == (tm.tm_mon + 1) && day == tm.tm_mday && hour == tm.tm_hour && min < tm.tm_min)
    { // if the minute is less than the actual
        return 0;
    }

    if (mth <= 0 || mth >= 13 || day <= 0 || day > 31 || age == 0 || hour < 0 || min < 0 || hour >= 24 || min >= 60)
    { // veirfy if the date is basically correct
        return 0;
    }

    if ((age % 4 != 0 || (age % 100 == 0 && age % 400 != 0)) && mth == 2 && day > 28)
    { // verify if it is a leap year
        return 0;
    }

    if ((mth == 4 || mth == 6 || mth == 9 || mth == 11) && (day > 30))
    { // 30 day month
        return 0;
    }

    if (mth == 2 && day > 29)
    { // february
        return 0;
    }

    return 1;
}

int verifycpf2(FILE *database, char search[MAX_SIZE], char search2[MAX_SIZE])
{
    Reserve person;
    fseek(database, 0, SEEK_SET);
    while (!feof(database)) // while the file not over
    {
        fread(&person, sizeof(Reserve), 1, database);
        if (strcmp(search, person.CPF) == 0) // if CPF is equal
        {
            if (strcmp(search2, person.flynum) == 0) // if the fly num is equal
            {
                if (person.status == 1) // is the reserve is active
                {
                    return 0; //false
                }
            }
        }
    }
    return 1; // true
}

int verifydatereserve(FILE *database, char search2[MAX_SIZE])
{
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    Basicfly fly;
    fseek(database, 0, SEEK_SET);

    while (fread(&fly, sizeof(Basicfly), 1, database) != 0) // while the file isnt over
    {
        if (strstr(fly.name, search2) != NULL) // if the fly name is equal.
        {
            if (fly.age < (tm.tm_year + 1900))
            { // if the  year is less than the actual

                return 0;
            }

            if (fly.age == (tm.tm_year + 1900) && fly.mth < (tm.tm_mon + 1))
            { // if the month is less than the actual
                return 0;
            }

            if (fly.age == (tm.tm_year + 1900) && fly.mth == (tm.tm_mon + 1) && fly.day < tm.tm_mday)
            { // if the day is less than the actual
                return 0;
            }

            if (fly.age == (tm.tm_year + 1900) && fly.mth == (tm.tm_mon + 1) && fly.day == tm.tm_mday && fly.hour < tm.tm_hour)
            { // if the hour is less than the actual
                return 0;
            }

            if (fly.age == (tm.tm_year + 1900) && fly.mth == (tm.tm_mon + 1) && fly.day == tm.tm_mday && fly.hour == tm.tm_hour && fly.min < tm.tm_min)
            { // if the minute is lass than the actual
                return 0;
            }

            if (fly.mth <= 0 || fly.mth >= 13 || fly.day <= 0 || fly.day > 31 || fly.age == 0 || fly.hour < 0 || fly.min < 0 || fly.hour >= 24 || fly.min >= 60)
            { // veirfy if the date is basically correct
                return 0;
            }

            if ((fly.age % 4 != 0 || (fly.age % 100 == 0 && fly.age % 400 != 0)) && fly.mth == 2 && fly.day > 28)
            { // leap years
                return 0;
            }

            if ((fly.mth == 4 || fly.mth == 6 || fly.mth == 9 || fly.mth == 11) && (fly.day > 30))
            { // 30 day month
                return 0;
            }

            if (fly.mth == 2 && fly.day > 29)
            { // february
                return 0;
            }

            return 1; // true
        }
    }
    return 0;
}

int verifystatus(char flynum[MAX_SIZE], FILE *database)
{
    Basicfly fly;
    fseek(database, 0, SEEK_SET);

    while (fread(&fly, sizeof(Basicfly), 1, database) != 0) // while the file isnt over
    {
        if (strstr(flynum, fly.name) != NULL) //  is the fly name is equal of the num
        {
            if (fly.status == 1) // if it is active
            {
                return 1;
            }
            if (fly.status == 0) // if it is cancelled
            {
                return 0;
            }
        }
    }
    return 0;
}

#endif