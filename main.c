/*User Login:
        Users can log in with a username and password.
        If the login is successful, the user is presented with a menu of options.

    User Registration:
        Users can choose to register a new account.
        The registration process collects information such as full name, mailing address, age, username, and password.

    Movie Display (showMovie function):
        Movies are displayed with details such as name, length, details, and genre.
        The display is influenced by the user's age:
            If the user is 16 years or older, R-rated movies are also shown.
            If the user is under 16, R-rated movies are skipped.

    Movie Selection:
        After displaying the available movies, the user can select a movie by its number.

    Movie Playback Simulation:
        Upon selecting a movie, a simulated message indicates that the movie is playing.
        A recommendation list is then shown based on the selected movie's genre.

    Recommendation Logic (recom function):
        The recom function takes the primary key of the selected movie as input.
        It recommends other movies with the same genre (excluding the selected movie).
        The recommended movies are displayed with their details.

    User Personal Information:
        Users can view their personal information, including full name, username, email, and age.

    Movie Category Display (category function):
        Users can explore movies by category based on their age.
        Categories include Drama, R-Rated (if 16 or older), Action, War, and Sci-Fi.

    Input Validation:
        Some basic input validation is performed, such as handling unexpected menu options.
        Validation messages are displayed for invalid inputs.

    Logout:

    Users can choose to log out of the system.

*/



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char username[25];
    char mail[30];
    int age;
    char password[15];
    char fullname[30];

};
struct User *users = NULL;
int usercount = 0;

struct Movie
{
    int primary;
    char name[30];
    char length[20];
    char details[50];
    char genre[10];
    int agelimit;
};


struct Movie movies[]=
{

    {1, "Inception", "2h 28min", "A mind-bending heist movie", "Sci-Fi", 13},
    {2, "The Shawshank Redemption", "2h 22min", "Two imprisoned men bond over a number of years", "Drama", 16},
    {3, "The Dark Knight", "2h 32min", "A criminal mastermind known as the Joker", "R-Rated", 16},
    {4, "Pulp Fiction", "2h 34min", "Various interconnected stories of crime", "Crime", 18},
    {5, "Forrest Gump", "2h 22min", "Life is like a box of chocolates", "War", 12},
    {6, "The Godfather", "2h 55min", "A tale of a powerful Italian-American crime family", "R-Rated", 16},
    {7, "The Matrix", "2h 16min", "The world is a simulated reality", "R-Rated", 16},
    {8, "Jurassic Park", "2h 7min", "Dinosaurs brought back to life", "Action", 10},
    {9, "Titanic", "3h 14min", "A romance set against the sinking of the Titanic", "Drama", 14},
    {10, "The Lion King", "1h 28min", "A young lion prince's journey to adulthood", "R-Rated", 16},
    {11, "The Avengers", "2h 23min", "A group of superheroes team up to save the world", "Action", 12},
    {12, "Interstellar", "2h 49min", "A group of explorers travels through a wormhole in space", "Sci-Fi", 14},
    {13, "The Social Network", "2h", "The founding and rise of Facebook", "Drama", 15},
    {14, "Inglourious Basterds", "2h 33min", "A group of Jewish U.S. soldiers plot to kill Nazis", "War", 18},

};

void showMovie(char username[], int age)
{

    for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++)
    {

        if (age >=16)
        {
            printf("Movie %d\n", i + 1);
            printf("Name: %s\n", movies[i].name);
            printf("Length: %s\n", movies[i].length);
            printf("Details: %s\n", movies[i].details);
            printf("Genre: %s\n", movies[i].genre);
            printf("-----------------------------------------------\n");
            printf("\n");
        }
        else
        {
            // If the movie is R-Rated, skip it
            if (strcmp(movies[i].genre, "R-Rated") == 0)
            {
                continue;
            }

            printf("Movie %d\n", i + 1);
            printf("Name: %s\n", movies[i].name);
            printf("Length: %s\n", movies[i].length);
            printf("Details: %s\n", movies[i].details);
            printf("Genre: %s\n", movies[i].genre);
            printf("-----------------------------------------------\n");
            printf("\n");
        }
    }
}

void recom(int option2)
{
    for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++)
    {
        if (movies[i].primary == option2)
        {
            char genre[10];
            strcpy(genre, movies[i].genre);

            for (int j = 0; j < sizeof(movies) / sizeof(movies[0]); j++)
            {
                if (strcmp(genre, movies[j].genre) == 0 && movies[j].primary != option2)
                {
                    printf("Recommended Movie %d\n", movies[j].primary);
                    printf("Name: %s\n", movies[j].name);
                    printf("Length: %s\n", movies[j].length);
                    printf("Details: %s\n", movies[j].details);
                    printf("Genre: %s\n", movies[j].genre);
                    printf("-----------------------------------------------\n");
                    printf("\n");
                }

            }

            }
        }
    }



// Resizing the array
void resizearray()
{
    users = realloc(users, (usercount + 1) * sizeof(struct User));
    if (users == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}
void personalDetails(char username[])
{
    for(int i=0;i<usercount;i++)
    {
        if(strcmp(users[i].username,username)==0)
        {
            printf("\n");
            printf("// --YOUR PERSONAL INFORMATION-- //\n");
            printf("Full Name- %s\n",users[i].fullname);
            printf("User Name- %s\n",users[i].username);
            printf("Email- %s\n",users[i].mail);
            printf("User Age- %d\n",users[i].age);
             printf("\n");

        }
    }
}
void cat(char genre[])
{
                for (int j = 0; j < sizeof(movies) / sizeof(movies[0]); j++)
            {
                if (strcmp(genre, movies[j].genre) == 0)
                {
                    printf("\n");
                    printf("Movie No.%d\n", movies[j].primary);
                    printf("Name: %s\n", movies[j].name);
                    printf("Length: %s\n", movies[j].length);
                    printf("Details: %s\n", movies[j].details);
                    printf("Genre: %s\n", movies[j].genre);
                    printf("-----------------------------------------------\n");
                    printf("\n");
                }

            }
}
void category(char username[],int age)
{
    if(age>=16)
    {
        printf("\n");
        printf("N.B. YOUR AGE IS ABOVE OR EQUAL 16 THAT IS WHY R-RATED MOVIES ARE VISIBLE FOR YOU,\nIF LESS THAN 16 YOU WOULD NOT SEE THE OPTION.\n");
        printf("Select Any Option\n1.Drama\n2.R-Rated\n3.Action\n4.War\n5.Sci-Fi\n");
        printf("\n");
        int option;
        scanf("%d",&option);
        char genre[10];
        if(option==1)
        {

            strcpy(genre,"Drama");
            cat(genre);

        }
        else if(option==2)
        {
            strcpy(genre,"R-Rated");
            cat(genre);

        }
        else if(option==3)
        {
            strcpy(genre,"Action");
            cat(genre);
        }
        else if(option==4)
        {
            strcpy(genre,"War");
            cat(genre);
        }
        else if(option==5)
        {
            strcpy(genre,"Sci-Fi");
            cat(genre);
        }
        else
        {
            printf("Validation Error!!\n");
        }
    }
    else if(age<16)
    {
        printf("\n");
        printf("N.B. YOUR AGE LESS 16 THAT IS WHY R-RATED MOVIES ARE NOT VISIBLE FOR YOU,\nIF GREATER OR EQUAL THAN 16 YOU WOULD SEE THE OPTION.\n");
        printf("Select Any Option\n1.Drama\n2.Action\n3.War\n4.Sci-Fi\n");
        printf("\n");
        int option;
        scanf("%d",&option);
        char genre[10];
         if(option==1)
        {

            strcpy(genre,"Drama");
            cat(genre);

        }
                else if(option==2)
        {
            strcpy(genre,"Action");
            cat(genre);
        }
                else if(option==3)
        {
            strcpy(genre,"War");
            cat(genre);
        }
                else if(option==4)
        {
            strcpy(genre,"Sci-Fi");
            cat(genre);
        }
        else
        {
            printf("Validation Error!!\n");
        }



    }
    else
    {
        printf("Input Validation Error!!\n");
    }
}
// Declare all the functions
bool login(char username[], char password[])
{
    for (int i = 0; i < usercount; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            return true;
        }
    }
    return false;
}

void registration(char fullname[], int age, char mail[], char username[], char password[])
{
    resizearray();

    snprintf(users[usercount].fullname, sizeof(users[usercount].fullname), "%s", fullname);
    snprintf(users[usercount].mail, sizeof(users[usercount].mail), "%s", mail);
    users[usercount].age = age;
    snprintf(users[usercount].username, sizeof(users[usercount].username), "%s", username);
    snprintf(users[usercount].password, sizeof(users[usercount].password), "%s", password);

    usercount++;
}

int main()
{
    printf("-----WELCOME TO ABC VIDEO STREAMING SYSTEM-----\n\n");

    while (true)
    {
        printf("Select Any Option\n1.Login\n2.User Registration\n");
        int option;
        scanf("%d", &option);

        if (option == 1)
        {
            printf("\nPlease Enter Your Login Credentials\n");
            printf("-----------------------------------\n");
            printf("Enter Your User Name: ");
            char username[25];
            scanf("%24s", username);
            printf("Enter Your Password: ");
            char password[15];
            scanf("%14s", password);
            int loggedIn = 0;
            if (login(username, password))
            {
                int menu=1;
                loggedIn = 1;
                printf("\nSuccessfully Logged Into The System\n");
                printf("------------------------------------\n");
                printf("\n");
                while(loggedIn)
                {
                printf("1. Search Movie By Genre\n2. See All Available Movies\n"
                       "3. User Information\n4. Logout\n");

                printf("\nSelect Any Option\n");
                int option1;
                scanf("%d", &option1);
                if(option1==1)
                {
                    for(int i=0;i<usercount;i++)
                    {
                        if(strcmp(users[i].username,username)==0)
                        {
                            int age=users[i].age;
                            category(username,age);
                        }
                    }
                }
                else if(option1==2)
                {

                 for(int i = 0; i < usercount; i++)
        {
            if (strcmp(users[i].username, username) == 0)
            {
                int age = users[i].age;
                showMovie(username,age);
                int option2;
                printf("Select Any Movie\n");
                scanf("%d",&option2);
                if(option2<sizeof(movies)/sizeof(movies[0])+1)
                {
                    printf("****************************************\n");
                    printf("\n");
                    printf("Movie Is Playing Here\n");
                    printf("\n");
                    printf("****************************************\n");
                    printf("\n");
                    printf("Playing The Movie\nEnjoy Watching The Movie\n\n");
                    printf("You Might Also Like To Watch\n\n");
                    printf("\n");
                    recom(option2);


                }
            }

        }
                }

                else if(option1==3)
                {
                    personalDetails(username);
                }
                else if(option1==4)
                {
                    printf("\n");
                    printf("Logged Out Successfully From The System\n");
                    printf("\n");
                    loggedIn=0;
                }
                else
                {
                    printf("Input Error!!\n");
                    continue;
                }
            }

            }
            else
            {
                printf("\nOops!! Wrong Login Credentials\nTry Again\n\n");
            }
        }
        else if (option == 2)
        {
            printf("\nAre You Sure You Want To Register A New Account\n1. YES\n2. NO\n");
            int option3;
            scanf("%d", &option3);

            if (option3 == 1)
            {
                getchar(); // Consume the newline character left in the buffer

                printf("\nPlease, Fill In The Registration Form\n\n");

                char fullname[30];
                printf("Enter Your Full Name: ");
                fgets(fullname, sizeof(fullname), stdin);
                fullname[strcspn(fullname, "\n")] = '\0';

                char mail[30];
                printf("Enter Your Mailing Address: ");
                fgets(mail, sizeof(mail), stdin);
                mail[strcspn(mail, "\n")] = '\0';

                int age;
                printf("Enter Your Age: ");
                scanf("%d", &age);
                getchar();
                char username[25];
                printf("Enter Your Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';

                char password[15];
                printf("Enter Your Password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';

                printf("\nEnter Your Payment Details\nRegistration successful\n");
                registration(fullname, age, mail, username, password);
            }
            else
            {
                printf("\nBack To Main Menu\n\n");
            }
        }
        else
        {
            printf("\nInput Validation Error!!\n\n");
            continue;
        }
    }


    free(users);

    return 0;
}
