#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User()
    {
        username = "";
        password = "";
    }

    User(string u, string p)
    {
        username = u;
        password = p;
    }

    bool validateInput()
    {
        if (username.length() < 3)
        {
            cout << "\nUsername must contain at least 3 characters!\n";
            return false;
        }

        if (password.length() < 6)
        {
            cout << "\nPassword must contain at least 6 characters!\n";
            return false;
        }

        return true;
    }

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

    file << "admin admin123" << endl;

    file.close();
}

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

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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

            case 3:
            {
                cout << "\nThank you for using AnujaMart!\n";
                cout << "Have a great day!\n";

                break;
            }

            default:
            {
                cout << "\nInvalid choice! Please try again.\n";
            }
        }

    } while (choice != 3);

    return 0;
}
