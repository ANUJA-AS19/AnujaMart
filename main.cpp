#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// =====================================================
// USER CLASS
// =====================================================

class User
{
private:
    string username;
    string password;

public:

    // Default Constructor
    User()
    {
        username = "";
        password = "";
    }

    // Parameterized Constructor
    User(string u, string p)
    {
        username = u;
        password = p;
    }

    // =================================================
    // INPUT VALIDATION
    // =================================================

    bool validateInput()
    {
        // Username length validation
        if (username.length() < 3)
        {
            cout << "\nUsername must contain at least 3 characters!\n";
            return false;
        }

        // Username should contain only letters
        for (int i = 0; i < username.length(); i++)
        {
            if (!isalpha(username[i]))
            {
                cout << "\nUsername must contain only letters!\n";
                return false;
            }
        }

        // Password length validation
        if (password.length() < 6)
        {
            cout << "\nPassword must contain at least 6 characters!\n";
            return false;
        }

        return true;
    }

    // =================================================
    // CHECK IF USER EXISTS
    // =================================================

    bool userExists()
    {
        ifstream file("users.txt");

        string storedUsername;
        string storedPassword;

        while (file >> storedUsername >> storedPassword)
        {
            if (storedUsername == username)
            {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    // =================================================
    // REGISTER FUNCTION
    // =================================================

    bool registerUser()
    {
        if (!validateInput())
        {
            return false;
        }

        if (userExists())
        {
            cout << "\nUser already exists!\n";
            return false;
        }

        ofstream file("users.txt", ios::app);

        if (!file)
        {
            cout << "\nUnable to open user database!\n";
            return false;
        }

        file << username << " "
             << password << endl;

        file.close();

        cout << "\nRegistration successful!\n";

        return true;
    }

    // =================================================
    // LOGIN FUNCTION
    // =================================================

    bool loginUser()
    {
        ifstream file("users.txt");

        if (!file)
        {
            cout << "\nUser database not found!\n";
            return false;
        }

        string storedUsername;
        string storedPassword;

        while (file >> storedUsername >> storedPassword)
        {
            if (storedUsername == username &&
                storedPassword == password)
            {
                file.close();

                cout << "\nLogin successful!\n";
                cout << "Welcome to AnujaMart, "
                     << username << "!\n";

                return true;
            }
        }

        file.close();

        cout << "\nInvalid username or password!\n";

        return false;
    }

    // =================================================
    // USER SESSION
    // =================================================

    void userSession()
    {
        bool loggedIn = true;

        int choice;

        while (loggedIn)
        {
            cout << "\n====================================\n";
            cout << "          ANUJAMART ACCOUNT\n";
            cout << "====================================\n";

            cout << "Logged in as: "
                 << username << "\n\n";

            cout << "1. View Profile\n";
            cout << "2. Logout\n";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    cout << "\n------------------------------------\n";
                    cout << "              PROFILE\n";
                    cout << "------------------------------------\n";

                    cout << "Username: "
                         << username << endl;

                    cout << "Account Status: Active\n";

                    cout << "------------------------------------\n";

                    break;
                }

                case 2:
                {
                    loggedIn = false;

                    cout << "\nLogout successful!\n";
                    cout << "Returning to main menu...\n";

                    break;
                }

                default:
                {
                    cout << "\nInvalid choice!\n";
                }
            }
        }
    }
};

// =====================================================
// SEED DATA
// =====================================================

void createSeedData()
{
    ifstream checkFile("users.txt");

    if (checkFile)
    {
        string username;
        string password;

        if (checkFile >> username >> password)
        {
            checkFile.close();
            return;
        }

        checkFile.close();
    }

    ofstream file("users.txt");

    if (!file)
    {
        cout << "\nUnable to create user database!\n";
        return;
    }

    // Default admin account
    file << "admin admin123" << endl;

    file.close();
}

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    createSeedData();

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "          WELCOME TO ANUJAMART\n";
        cout << "====================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // =========================================
            // REGISTER
            // =========================================

            case 1:
            {
                string username;
                string password;

                cout << "\nEnter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                User user(username, password);

                user.registerUser();

                break;
            }

            // =========================================
            // LOGIN
            // =========================================

            case 2:
            {
                string username;
                string password;

                cout << "\nEnter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                User user(username, password);

                if (user.loginUser())
                {
                    user.userSession();
                }

                break;
            }

            // =========================================
            // EXIT
            // =========================================

            case 3:
            {
                cout << "\nThank you for using AnujaMart!\n";
                cout << "Have a great day!\n";

                break;
            }

            // =========================================
            // INVALID OPTION
            // =========================================

            default:
            {
                cout << "\nInvalid choice! Please try again.\n";
            }
        }

    } while (choice != 3);

    return 0;
} 
