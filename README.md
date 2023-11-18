# Movie_Streaming_And_recommendation-IN-C
    User Login:
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

    Memory Management:

    Dynamic memory allocation is used for the users array.
    Memory is freed at the end of the program.
