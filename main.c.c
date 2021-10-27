/* Programa para o sistema operacional Windows
Certifico que os algoritmos e programas que estou entregando sao de minha autoria e 
que nao os repassei ou os recebi de qualquer outra pessoa. Kaua Vini­cius Ponte Aguiar - Matri­cula 211029399.
Objective: To produce a system for a Jeff Elon Branson fictional business.
Input : operant choices.
Output: data saved in the system.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h" // self library

void RegisterF()
{ // register fligth
    FILE *database;
    Basicfly fly;
    int choose;
    database = Open_file("Data_Space.bin", "r+b"); // open file

    printf("___________________________________\n");
    printf("__________Register Flight__________\n"); //menu
    printf("___________________________________\n");
    printf("\n");
    printf("Please enter:\n");
    printf("The Flight number: \n\n");
    printf("Follow the model : JEB-XXXX\n");
    scanf("%s", fly.name); // scan the Flight number

    if (verifyname(fly.name) == 1 || searchfligthfunction(database, fly.name) == 1)
    { //verify if the Flight number is correct
        while (verifyname(fly.name) == 1 || searchfligthfunction(database, fly.name) == 1)
        {
            printf("\n\nThis fligth is already registered or in a wrong format\nPlease, enter again the Flight number:\n");
            scanf("%s", fly.name);
            verifyname(fly.name);
        }
    }

    printf("___________________________________\n");
    printf("\nThe maximum number of passengers:\n");
    printf("\nModel: XXX\n");
    scanf("%s", fly.passengers); // scan the number of passengers

    if (isDigit(fly.passengers, 0, 2) == 0 || verifypassengers(fly.passengers) == 0)
    { // verify if the number of passengers is correct
        while (isDigit(fly.passengers, 0, 2) == 0 || verifypassengers(fly.passengers) == 0)
        { // loop to rescan the number
            printf("\nInvalid passengers Number, please, insert a correct number:\n");
            scanf("%s", fly.passengers);
            isDigit(fly.passengers, 0, 2);
        }
    }
    printf("___________________________________\n");
    printf("\nThe flight date:\n\nExample : XX/XX/XXXX-XX:XX\n\nDate:");        //data com loop infinito
    scanf("%d/%d/%d-%d:%d", &fly.day, &fly.mth, &fly.age, &fly.hour, &fly.min); //scan the date

    if (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 0)
    {
        while (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 0)
        { //verify if the date is correct
            printf("\nInvalid date \nPlease, enter again a correct date:\n");
            scanf("%d/%d/%d-%d:%d", &fly.day, &fly.mth, &fly.age, &fly.hour, &fly.min);
        }
    }

    fly.status = 1;

    fwrite(&fly, sizeof(Basicfly), 1, database); // write on database
    fclose(database);                            // close the file
    printf("__________________________________\n");
    printf("\n");
    printf("\nCompleted flight registration!!\n"); // mensage to say that the registration was succeful,
    printf("\n");
    printf("___________________________________\n");

    printf("\nDo you want to register anothers flights ? ?\n");
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose); // if the person wants register anothers fligths

    if (choose == 1) // yes, it clean the window and repeat
    {
        system("cls"); // clean and restart the function
        RegisterF();
    }
    else

        printf("Press enter to continue\n");
    getchar();
    system("cls || clear"); // clean the window
}

void RegisterR()
{ // register a reserve
    FILE *database;
    FILE *database2;
    Reserve person;
    int choose;
    database = Open_file("Data_reserve.bin", "r+b"); // open and create a new file
    database2 = Open_file("Data_Space.bin", "r+b");

    printf("___________________________________\n"); // visual
    printf("________Register Passenger_________\n");
    printf("___________________________________\n");
    printf("\n");
    printf("Please enter \n");
    printf("\nThe inclusion Number:\n"); // enter the inclusion number
    printf("Follow the model : GB-XXXXXX\n");
    scanf("%s", person.num);

    if (verifyreserve(person.num) == 1 || searchpersonfunction(database, person.num) == 1)
    { // see if the inclusion number is correct
        while (verifyreserve(person.num) == 1 || searchpersonfunction(database, person.num) == 1)
        {
            printf("______________________________________\n");
            printf("\nRepeated or invalid inclusion number\n"); // if the inclusion number is repeated or invalid return 1
            printf("Please, insert a valid inclusion number:\n");
            scanf("%s", person.num);
        }
    }

    printf("___________________________________\n");
    printf("\nPlease, insert the Flight number: \n");
    printf("Follow the model : JEB-XXXX\n");
    scanf("%s", person.flynum); // scan the Flight number
    if (searchfligthfunction(database2, person.flynum) == 0 || verifypercentage(database2, database, person.flynum) == 1 || verifydatereserve(database2, person.flynum) == 0 || verifystatus(person.flynum, database2) == 0)
    { //verify if the Flight number is correct
        while (searchfligthfunction(database2, person.flynum) == 0 || verifypercentage(database2, database, person.flynum) == 1 || verifydatereserve(database2, person.flynum) == 0 || verifystatus(person.flynum, database2) == 0)
        {
            printf("_______________________________\n");
            printf("\n\nNon-existent,Canceled or full flight\nPlease, enter again the Flight number:\n");
            scanf("%s", person.flynum);
        }
    }

    printf("___________________________________\n");
    printf("\nPlease, insert the CPF: \n");
    printf("You should follow the model = XXX.XXX.XXX-XX\n");
    printf("Your CPF: ");
    scanf("%s", person.CPF); // insert cpf

    while (verifycpf(person.CPF) == 0 || verifycpf2(database, person.CPF, person.flynum) == 0)
    { // verify if cpf is correct or if this cpf is already registered on that fly
        printf("______________________________________");
        printf("\nCPF already registered or incorrect\n");
        printf("\nPlease, enter a valid CPF number:\n");
        scanf("%s", person.CPF);
    }

    fflush(stdin);
    printf("___________________________________\n");
    printf("\nPlease, enter your full name(only letters):\n"); // enter the person name
    scanf(" %[^\n]s", person.name);                            // get the name

    fflush(stdin);
    printf("___________________________________\n");
    printf("\nPlease, insert your sex:\n"); // enter sex
    printf("'M' for man\n'W' for woman \n");
    printf("Your Sex: ");
    scanf("\n%c", &person.sex); // get sex

    while (verifysex(person.sex) == 1)
    { // if sex is different of M or W
        printf("_____________________________\n");
        printf("\nPlease, enter a valid sex: \n");
        printf("Your Sex: ");
        scanf("\n%c", &person.sex);
    }

    printf("___________________________________\n");
    printf("\nPlease, enter your birth date: \n"); // enter the birthday
    printf("You should follow the model: XX/XX/XXXX\n");
    printf("Your Birth (Only numbers):");
    scanf("%d/%d/%d", &person.day, &person.mth, &person.age);

    if (verifybirth(person.day, person.mth, person.age) == 0) // verify the birth from person
    {
        while (verifybirth(person.day, person.mth, person.age) == 0)
        {
            printf("___________________________\n");
            printf("Please, enter a valid date:\n");
            scanf("%d/%d/%d", &person.day, &person.mth, &person.age);
        }
    }

    person.status = 1;

    fwrite(&person, sizeof(Reserve), 1, database); // keep the informations on file.

    fclose(database); // close the file
    fclose(database2);

    printf("___________________________________\n");
    printf("\n");
    printf("\nSuccessful reserve!!\n"); // mensage to say that the registration was succeful
    printf("\n");
    printf("___________________________________\n");

    printf("\nDo you want to register anothers reservers ?\n");
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("cls || clear");
        RegisterR();
    }
    else
        printf("___________________________________\n");
    printf("Press enter to continue\n");
    getchar();
    system("cls"); // clean the window
}

void ConsultF()
{ // consult fligth
    FILE *database;
    FILE *database2;
    Basicfly fly;
    Reserve person;
    char search[MAX_SIZE], status[MAX_SIZE];
    int choose, passengers_counter = 0, counter = 1;
    float percent, passengerson;
    database = Open_file("Data_space.bin", "r+b");    // open the record of fligths
    database2 = Open_file("Data_reserve.bin", "r+b"); // open the record of reserve

    printf("_______________________________________\n"); // visual
    printf("____________ Consult Fligth____________\n");
    printf("_______________________________________\n");
    printf("\n");
    printf("Fligths:\n"); //search for active fligths and print on screen
    fseek(database, 0, SEEK_SET);
    while (fread(&fly, sizeof(Basicfly), 1, database) != 0)
    {
        printf("\n  %s", fly.name);
    }
    printf("\n_________________________________________\n");
    printf("\n");
    printf("\nPlease, please enter the flight number: \n");
    printf("Fligth: ");
    scanf("%s", search); // get the string  that will be comparred

    if (searchfligthfunction(database, search) == 0) // if the string doesnt exist on database
    {
        printf("________________________\n");
        printf("\n");
        printf("\nNon-existent flight\n"); // mensage
        printf("\n");
        printf("_________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }
    if (searchfligthfunction(database, search) == 1)
    {
        system("cls || clear");
        printf("_______________________________________\n");
        printf("____________ Consult Fligth____________\n"); //visual
        printf("_______________________________________\n");

        fseek(database2, 0, SEEK_SET); // put the indicator in the top of the database
        while (fread(&person, sizeof(Reserve), 1, database2))
        {
            if (strstr(person.flynum, search) != 0 && person.status != 0) // if the loop found a string with the same name of  search, it will sum 1 to passengers count
            {
                passengers_counter++;
            }
        }

        fseek(database, 0, SEEK_SET); // put again the indicador in the top of the database

        while (fread(&fly, sizeof(Basicfly), 1, database) != 0)
        {
            if (strstr(fly.name, search) != NULL) // if the fly name if equal to search do ...
            {

                passengerson = atof(fly.passengers); // calculate the percentage
                percent = (float)passengers_counter / passengerson;
                percent = percent * 100;

                if (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 1)
                {
                    if (fly.status == 1) // if status is 1, print active, if 0 print inactive
                    {
                        strcpy(status, "Active");
                    }
                    if (fly.status == 0)
                    {
                        strcpy(status, "Canceled");
                    }
                }
                if (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 0)
                {
                    strcpy(status, "Expired Flight"); // if the date is obsolete, it will print waxed fligth
                }

                printf("\n");
                printf("\nFligth Number: %s \nStatus: %s\nDate: %02d/%02d/%d-%02d:%02d\nPercentage of occupancy: %.2f%%\n", search, status, fly.day, fly.mth, fly.age, fly.hour, fly.min, percent); // print the data
                printf("\nPassengers active by CPF: \n");

                if (percent <= 0)
                {
                    printf("\nEmpty flight\n");
                    printf("_______________________________________\n");
                }
                else
                {

                    fseek(database2, 0, SEEK_SET);
                    while (fread(&person, sizeof(Reserve), 1, database2))
                    {
                        if (strstr(person.flynum, search)) // print the name of passengers in the fligth
                        {
                            if (person.status != 0)
                            {
                                printf("%d - %s\n", counter, person.CPF); // print the CPF of the person
                                counter++;
                            }
                        }
                    }

                    printf("\n___________________________________\n");
                    fread(&fly, sizeof(Basicfly), 1, database); // restart the loop
                }
            }
        }
    }
    fclose(database); // close the file
    fclose(database2);
    printf("\nDo you want to consult more flights ?\n");
    printf("1-Yes\n2-No\n");
    printf("Answer: "); // ask if the person wants to consult another fligth
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("cls || clear");
        ConsultF();
    }
    else
        printf("Press enter to continue\n");
    getchar();
    system("cls || clear"); // clean the window
}

void ConsultR()
{
    FILE *database;
    FILE *database2;
    Reserve person;
    Basicfly fly;
    char search[MAX_SIZE], status[MAX_SIZE], sex[MAX_SIZE];
    int choose;
    database = Open_file("Data_reserve.bin", "r+b"); // open files
    database2 = Open_file("Data_Space.bin", "r+b");

    printf("_______________________________\n");
    printf("________Consult Reserve________\n"); // visual
    printf("_______________________________\n");
    printf("\n");
    printf("\nPlease, please enter the reserve number: \n");
    printf("Reserves:\n"); //search for active fligths and print on screen
    fseek(database, 0, SEEK_SET);
    while (fread(&person, sizeof(Reserve), 1, database) != 0)
    {
        printf("\n %s", person.num);
    }
    printf("\n");
    printf("\n");
    printf("Number: ");
    scanf("%s", search); // get the reserve number that the person wants to consult

    if (searchpersonfunction(database, search) == 0)
    {
        printf("___________________________\n");
        printf("\nNon-existent reservation\n"); // if the search reservation isnt on database
        printf("___________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }
    if (searchpersonfunction(database, search) == 1) // if the reservation is on database
    {
        system("cls || clear");
        printf("_____________________________________\n");
        printf("___________Consult Reserve___________\n"); // visual
        printf("_____________________________________\n");
        fseek(database, 0, SEEK_SET);
        while (!feof(database)) // run on database
        {
            fread(&person, sizeof(Reserve), 1, database);
            if (strstr(person.num, search) != NULL) // search for the string on database
            {
                fseek(database, 0, SEEK_SET);
                while (fread(&fly, sizeof(Basicfly), 1, database2) != 0)
                {
                    if (strstr(person.flynum, fly.name) != NULL)
                    {
                        if (person.status != 0 && fly.status != 0 && verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 1) // if status is 1, print active, if 0 print canceled
                        {
                            strcpy(status, "Active");
                        }
                        else

                            strcpy(status, "Canceled");
                    }
                }
                if (person.sex == 'M') // compare the char and put the correct string
                {
                    strcpy(sex, "Man");
                }
                if (person.sex == 'W')
                {
                    strcpy(sex, "Woman");
                }

                printf("_____________________________________\n");
                printf("\n");
                printf("Reserve: %s \nFligth number : %s\nCPF: %s\nReserve Status : %s\nName: %s\nSex: %s\nBirth: %02d/%02d/%d \n", search, person.flynum, person.CPF, status, person.name, sex, person.day, person.mth, person.age); // print informations
                printf("\n________About Fligth________\n");                                                                                                                                                                           // informations about the fligth on that reserve

                fseek(database2, 0, SEEK_SET);
                while (!feof(database2))
                {
                    fread(&fly, sizeof(Basicfly), 1, database2);
                    if (strstr(person.flynum, fly.name) != NULL) // verify if there are any flygth
                    {
                        if (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 1) // verify if the date exists
                        {
                            if (fly.status != 0) // if status is 1, print active, if 0 print canceled
                            {
                                strcpy(status, "Active");
                            }
                            if (fly.status == 0)
                            {
                                strcpy(status, "Canceled");
                            }
                        }
                        if (verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 0)
                        {
                            strcpy(status, "Waxed Flight"); // if the date is before, print waxed flight
                        }

                        printf("\nStatus: %s\nDate: %02d/%02d/%d-%02d:%02d\n", status, fly.day, fly.mth, fly.age, fly.hour, fly.min); // print flyght informations
                        break;
                    }
                }
                break;
            }

            fread(&person, sizeof(Reserve), 1, database); // read again
        }
    }
    fclose(database); // close the file
    fclose(database2);

    printf("_____________________________________\n");
    printf("\nDo you want to consult more reservers ?\n");
    printf("1-Yes\n2-No\n");
    printf("Answer: "); // ask if the person wants to consult more reserves
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("cls || clear");
        ConsultR(); //return to function
    }
    else
        printf("Press enter to continue\n");
    getchar();
    system("cls || clear "); // clean the window
}

void ConsultP()
{
    FILE *database;
    Reserve person;
    char search[MAX_SIZE], status[MAX_SIZE], sex[MAX_SIZE];
    int choose, counter = 1;
    database = Open_file("Data_reserve.bin", "r+b"); // open file

    printf("____________________________________\n");
    printf("__________Consult Passenger_________\n"); //visual
    printf("____________________________________\n");
    printf("\n");
    printf("Active CPFs:\n");
    fseek(database, 0, SEEK_SET);
    while (fread(&person, sizeof(Reserve), 1, database) != 0)
    {
        printf("\n %s", person.CPF);
    }
    printf("\n____________________________________\n");
    printf("\nSearch for (insert CPF): \n");
    scanf("%s", search);

    if (searchpersoncpf(database, search) == 0)
    {
        printf("\n___________________________\n");
        printf("\nNon-existent passenger\n"); // if the passenger not exist
        printf("___________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }

    if (searchpersoncpf(database, search) == 1)
    {
        system("cls || clear");
        printf("_____________________________________\n");
        printf("__________Consult Passenger__________\n"); // if the passenger exist
        printf("_____________________________________\n");
        fseek(database, 0, SEEK_SET);
        while (!feof(database)) // search on file
        {
            fread(&person, sizeof(Reserve), 1, database);
            if (strstr(person.CPF, search) != NULL)
            {
                fseek(database, 0, SEEK_SET);
                if (person.status == 1) // copy the string, if it is 1, print Active, if it is 0, print Canceled
                {
                    strcpy(status, "Active");
                }
                if (person.status == 0)
                {
                    strcpy(status, "Canceled");
                }

                if (person.sex == 'M') // compare the char to put the correct string
                {
                    strcpy(sex, "Man");
                }
                if (person.sex == 'W')
                {
                    strcpy(sex, "Woman");
                }

                printf("\n");
                printf("Name: %s\nCPF: %s\nSex: %s\nBirth: %02d/%02d/%d\n", person.name, person.CPF, sex, person.day, person.mth, person.age); // print the file
                printf("\nAbout reserves: \n");                                                                                                // print about the active reserves

                fseek(database, 0, SEEK_SET);
                while (fread(&person, sizeof(Reserve), 1, database) != 0) // searsh on database
                {

                    if (strstr(person.CPF, search) != NULL)
                    {
                        if (person.status == 1) // if it is 1, print active, if it is 0, print canceled
                        {
                            printf("%d- %s -> Active\n", counter, person.num);
                        }
                        if (person.status == 0)
                        {
                            printf("%d- %s -> Canceled \n", counter, person.num);
                        }
                        counter++; // design counter
                    }
                }
                break;
            }
            fread(&person, sizeof(Reserve), 1, database); // repeat the process
        }
    }
    fclose(database); // close the file

    printf("________________________________________\n");
    printf("\nDo you want to consult more passengers ?\n"); // visual
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose); // choose

    if (choose == 1)
    {
        system("cls || clear");
        ConsultP(); // restart the function
    }
    else
        printf("Press enter to continue\n");
    getchar();
    system("cls || clear"); // clean the window
}

void CancelF()
{
    FILE *database; // var files
    FILE *database2;
    FILE *aux, *aux2;
    Basicfly fly;
    Basicfly fly2;
    Reserve person;
    Reserve person2;
    int choose, i, count2 = 0, count3 = 0; // counters
    char search[MAX_SIZE];
    database = Open_file("Data_Space.bin", "r+b");    // open files
    database2 = Open_file("Data_reserve.bin", "r+b"); // open files
    aux = Open_fileaux("Aux3.bin", "w+b");            // create files
    aux2 = Open_fileaux("Aux2.bin", "w+b");           // create files

    printf("__________________________________________\n");
    printf("_______________Cancel Fligth______________\n"); // visual
    printf("__________________________________________\n");
    printf("\n");
    printf("Active Fligths:\n");

    fseek(database, 0, SEEK_SET);
    while (fread(&fly, sizeof(Basicfly), 1, database) != 0) // print the active fligths
    {
        count3++;                                                                             // counter to see the fligths on the file
        if (fly.status == 1 && verifydate(fly.day, fly.mth, fly.age, fly.hour, fly.min) == 1) // see if the fligth is active and in a valid date
        {
            printf("   %s\n", fly.name); // print the actives fligths on the screen
        }
    }

    printf("________________________________________________\n");
    printf("\nPlease, type the fligth that you like to cancel:\n");
    printf("Cancel: ");
    scanf("%s", search); // write the option that the person wants to cancel

    if (searchfligthfunction(database, search) == 0)
    {
        printf("__________________________________________\n");
        printf("\n");
        printf("\nNon-existent flight\n"); // if the fligth not exists
        printf("\n");
        printf("__________________________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }
    if (searchfligthfunction(database, search) == 1) // if the flith exists
    {

        fseek(database, 0, SEEK_SET); // position the cursor
        for (i = 0; i < count3; i++)
        {
            fread(&fly, sizeof(Basicfly), 1, database); // read the file
            if (strstr(fly.name, search) == NULL)       // if isnt the rigth fligth
            {
                fwrite(&fly, sizeof(Basicfly), 1, aux); // write on the file
            }
            if (strstr(fly.name, search) != NULL) // if is the rigth fligth
            {
                strcpy(fly2.name, fly.name);
                strcpy(fly2.passengers, fly.passengers);
                fly2.day = fly.day;
                fly2.mth = fly.mth;
                fly2.age = fly.age;
                fly2.hour = fly.hour;
                fly2.min = fly.min;
                fly2.status = 0;                         // change status
                fwrite(&fly2, sizeof(Basicfly), 1, aux); // write on the file
            }
        }

        fclose(database); // close both files
        fclose(aux);

        fclose(database);
        fclose(aux);

        remove("Data_Space.bin");             // delete the file
        rename("Aux3.bin", "Data_Space.bin"); // change the file name

        fseek(database2, 0, SEEK_SET);
        while (fread(&person, sizeof(Reserve), 1, database2) != 0) // print the active fligths
        {
            ++count2; // count the number of active reserves
        }

        fseek(database2, 0, SEEK_SET); // position the cursor
        for (i = 0; i < count2; i++)   //
        {
            fread(&person, sizeof(Reserve), 1, database2); // read the file
            if (strstr(person.flynum, search) == NULL)     // if the flynum is different than the search fligth
            {
                fwrite(&person, sizeof(Reserve), 1, aux2); // write on new file
            }
            if (strstr(person.flynum, search) != NULL) // if the fly num is equal
            {
                strcpy(person2.num, person.num);
                strcpy(person2.flynum, person.flynum);
                strcpy(person2.name, person.name);
                strcpy(person2.CPF, person.CPF);
                person2.sex = person.sex;
                person2.day = person.day;
                person2.mth = person.mth;
                person2.age = person.age;
                person2.status = 0;                         // change the status
                fwrite(&person2, sizeof(Reserve), 1, aux2); // write on new file
            }
        }

        fclose(database2); // close files
        fclose(aux2);
        fclose(database2);
        fclose(aux2);

        remove("Data_reserve.bin");             // remove the old file
        rename("Aux2.bin", "Data_reserve.bin"); // change the files name

        printf("\n__________________________________________\n");
        printf("\nSuccessfully completed flight cancellation\n"); // successfullt fligth cancellation
    }

    fclose(aux);
    fclose(aux2);
    remove("Aux2.bin");
    remove("Aux3.bin");

    printf("____________________________________________\n");
    printf("\nDo you want to cancel another flight ?\n"); // if the person wants to cancel another fligth
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose); // choose

    if (choose == 1)
    {
        system("cls || clear");
        CancelF(); // if yes, return to the function
    }
    else

        printf("Press enter to continue\n");
    system("cls || clear"); // clean the window
}

void CancelR()
{
    FILE *database; // var files
    FILE *aux;
    Reserve person;
    Reserve person2;
    int choose, i, count2 = 0;
    char search[MAX_SIZE];
    database = Open_file("Data_reserve.bin", "r+b"); // open files
    aux = Open_fileaux("Aux2.bin", "w+b");

    printf("__________________________________________\n");
    printf("_______________Cancel Reserve_____________\n"); // visual
    printf("__________________________________________\n");
    printf("\n");
    printf("Active reserves:\n");

    fseek(database, 0, SEEK_SET);
    while (fread(&person, sizeof(Reserve), 1, database) != 0) // print the active fligths
    {
        count2++;
        if (person.status == 1) // print the reserve number if it is active
        {

            printf(" %s\n", person.num);
        }
    }

    printf("________________________________________________\n");
    printf("\nPlease, type the reserve that you like to cancel:\n");
    printf("Cancel: ");
    scanf("%s", search); // write the option that the person wants to cancel
    if (searchpersonfunction(database, search) == 0)
    {
        printf("__________________________________________\n");
        printf("\n");
        printf("\nNon-existent reserve\n"); // if the fligth not exists
        printf("\n");
        printf("__________________________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }
    if (searchpersonfunction(database, search) == 1) // if the flith exists
    {

        fseek(database, 0, SEEK_SET); // position the cursor
        for (i = 0; i < count2; i++)  //
        {
            fread(&person, sizeof(Reserve), 1, database); // read the file
            if (strstr(search, person.num) == NULL)       // if the flynum is different than the search fligth
            {
                fwrite(&person, sizeof(Reserve), 1, aux); // write on new file
            }
            if (strstr(search, person.num) != NULL)
            {
                strcpy(person2.num, person.num);
                strcpy(person2.flynum, person.flynum);
                strcpy(person2.name, person.name);
                strcpy(person2.CPF, person.CPF);
                person2.sex = person.sex;
                person2.day = person.day;
                person2.mth = person.mth;
                person2.age = person.age;
                person2.status = 0;                        // change the status
                fwrite(&person2, sizeof(Reserve), 1, aux); // write on new file
            }
        }

        fclose(database); // close files
        fclose(aux);
        fclose(database);
        fclose(aux);

        remove("Data_reserve.bin");             // remove the old file
        rename("Aux2.bin", "Data_reserve.bin"); //  rename the file

        printf("\n__________________________________________\n");
        printf("\nSuccessfully completed reserve cancelation\n"); // successfullt fligth cancellation
    }
    remove("Aux2.bin");
    remove("Aux2");

    printf("____________________________________________\n");
    printf("\nDo you want to cancel another reserve ?\n"); // if the person wants to cancel another fligth
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose); // choose

    if (choose == 1)
    {
        system("cls || clear");
        CancelR(); // if yes, return to the function
    }
    else

        printf("Press enter to continue\n");
    system("cls || clear"); // clean the window
}

void DeleteF()
{
    FILE *database; // VARs
    FILE *database2;
    FILE *aux, *aux2;
    Basicfly fly;
    Reserve person;
    int choose, count = 0, i, count2 = 0;
    char search[MAX_SIZE];
    database = Open_file("Data_Space.bin", "r+b");    // open files
    database2 = Open_file("Data_reserve.bin", "r+b"); // open files
    aux = Open_fileaux("Aux3.bin", "w+b");
    aux2 = Open_fileaux("Aux2.bin", "w+b");

    printf("__________________________________________\n");
    printf("_______________Delete Fligth______________\n"); // visual
    printf("__________________________________________\n");
    printf("\n");
    printf("Active Fligths:\n");

    fseek(database, 0, SEEK_SET);
    while (fread(&fly, sizeof(Basicfly), 1, database) != 0) // print the active fligths
    {
        ++count;
        printf(" %s\n", fly.name);
    }

    printf("________________________________________________\n");
    printf("\nPlease, type the fligth that you like to delete:\n");
    printf("Delete: ");
    scanf("%s", search); // write the option that the person wants to cancel

    if (searchfligthfunction(database, search) == 0)
    {
        printf("__________________________________________\n");
        printf("\n");
        printf("\nNon-existent flight\n"); // if the fligth not exists
        printf("\n");
        printf("__________________________________________\n");
        printf("\nPress enter to continue\n");
        getchar();
    }
    if (searchfligthfunction(database, search) == 1) // if the fligth exists
    {

        fseek(database, 0, SEEK_SET);
        for (i = 0; i < count; i++) // run in the database
        {
            fread(&fly, sizeof(Basicfly), 1, database);
            if (strstr(fly.name, search) == NULL) // if the fligth is different
            {
                fwrite(&fly, sizeof(Basicfly), 1, aux); // write the fligth
            }
        }

        fclose(database); // close files
        fclose(aux);
        fclose(database);
        fclose(aux);

        remove("Data_Space.bin");             // remove the old file
        rename("Aux3.bin", "Data_Space.bin"); // rename the new file

        fseek(database2, 0, SEEK_SET);
        while (fread(&person, sizeof(Reserve), 1, database2) != 0) // print the active fligths
        {
            ++count2; // counter
        }

        fseek(database2, 0, SEEK_SET);
        for (i = 0; i < count2; i++) // run in the file
        {
            fread(&person, sizeof(Reserve), 1, database2);
            if (strstr(person.flynum, search) == NULL) // if the fly num is different
            {
                fwrite(&person, sizeof(Reserve), 1, aux2); // write in the file
            }
        }

        fclose(database2); // close the files
        fclose(aux2);
        fclose(database2);
        fclose(aux2);

        remove("Data_reserve.bin");             // remove file
        rename("Aux2.bin", "Data_reserve.bin"); // change the name

        printf("\n__________________________________________\n");
        printf("\nSuccessfully completed flight delete\n"); // successfullt fligth cancellation
    }

    fclose(aux); // close both files
    fclose(aux2);
    remove("Aux2.bin");
    remove("Aux3.bin");

    printf("____________________________________________\n");
    printf("\nDo you want to delete another flight ?\n"); // if the person wants to cancel another fligth
    printf("1-Yes\n2-No\n");
    printf("Answer: ");
    scanf("%d", &choose); // choose

    if (choose == 1)
    {
        system("cls || clear");
        DeleteF(); // if yes, return to the function
    }
    else

        printf("Press enter to continue\n");
    system("cls || clear"); // clean the window
}

void menu()
{                        // menu function
    unsigned int choose; // variable to alloc the number choseen by usuary

    do
    {

        printf("_______________________________\n"); // visual menu
        printf("_________Galatic Birds_________\n");
        printf("______Trip to Karman line______\n");
        printf("_______________________________\n");
        printf("\n");
        printf("__________Main Menu____________\n");
        printf("___Please, choose your option:__\n");
        printf("_______Only numbers:____________\n");
        printf("\n");
        printf("1- Register flight.\n");
        printf("2- Register reserve.\n");
        printf("3- Consult flight.\n");
        printf("4- Consult reserve.\n");
        printf("5- Consult passenger.\n");
        printf("6- Cancel flight.\n");
        printf("7- Cancel reserve.\n");
        printf("8- Delete flight.\n");
        printf("9- Exit the program\n");
        printf("\n");
        printf("Your choice: ");
        scanf("%d", &choose); // alloc var;

        switch (choose)
        { // "switch" to foward the usuary to his choosen option
        case 1:
            system("cls || clear");
            RegisterF(); // basic struct, function, a system call to clean the screen, and break ;
            break;
        case 2:
            system("cls || clear");
            RegisterR();
            break;

        case 3:
            system("cls || clear");
            ConsultF();
            break;

        case 4:
            system("cls || clear");
            ConsultR();
            break;

        case 5:
            system("cls || clear");
            ConsultP();
            break;

        case 6:
            system("cls || clear");
            CancelF();
            break;

        case 7:
            system("cls || clear");
            CancelR();
            break;

        case 8:
            system("cls || clear");
            DeleteF();
            break;

        case 9: // used to left form program , here, the system call is to close the program with "exit";
            printf("Good Bye... From Space!!\n");
            exit(0);
            break;

        default: // if the usuary choose a  invalid number, the default will show a mensage to him and will return to main menu, cleaning the screen
            printf("Invalid Option, Please, choose a valid procedure\n");
            printf("Please, type any key to continue\n");
            system("pause");
            system("cls || clear");
            break;
        }
    } while (1); // condition to repeat the main menu
}

int main() // main function
{
    menu(); // Call menu
    return 0;
}