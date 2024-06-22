#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string userName, password, firstName, lastName, Dob, line;
string playerName, playerFirsName, playerLastName, playerDob, playerTeam, playerScored;
const string F_UserData = "userdata.txt";
const string F_PlayersData = "players.txt";
const string aadminCode = "icbt";
int userID, P_ID;
char choice;

bool loginSuccess = false;

void welcomeMenu();
void mainMenu();
void useRegister();
void checkLogin();
void addPlayers();
void searchPlayers();
void removePlayers();
void editPlayerInfo();
void manageTeams();
void displayAllPlayers();
void logout();
void backOption();

void backOption(){
    cout << "\n";
    cout << "\n \t\t\t Enter any key to go to the previous menu: ";
    cin >> choice;
    if (choice){
        system("cls");
        if (loginSuccess){
            mainMenu();
        }else{
            welcomeMenu();
        }
    }
}

void useRegister() {
    system("cls");

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                User Registration               |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter First Name: ";
    cin >> firstName;

    cout << "\n \t\t\t Enter Last Name: ";
    cin >> lastName;

    cout << "\n \t\t\t Enter Password: ";
    cin >> password;

    ofstream outFile(F_UserData, ios::app);
    if (outFile.is_open()) {
        outFile << "User ID: " << userID << "\n";
        outFile << "First Name: " << firstName << "\n";
        outFile << "Password: " << password << "\n";
        outFile << "Full Name: " << firstName << " " << lastName << "\n";
        outFile << "------------------------------------------------\n";
        outFile.close();
        cout << "\n \t\t\t Registration Successful! \n";
        checkLogin();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}

void checkLogin() {

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                  Welcome Back!                 |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Username: ";
    cin >> userName;

    cout << "\n \t\t\t Enter Password: ";
    cin >> password;

    ifstream inFile(F_UserData);
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line == "First Name: " + userName) {
                getline(inFile, line);
                if (line == "Password: " + password) {
                    loginSuccess = true;
                    break;
                }
            }
        }
        inFile.close();

        if (loginSuccess) {
            cout << "\n \t\t\t Login Successful! \n";
            system("cls");
            mainMenu();
        } else {
            system("cls");
            cout << "\n \t\t\t Invalid Username or Password! \n";
            checkLogin();
        }
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}

void welcomeMenu(){

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                Hello! Welcome User!            |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    cout << " \t\t\t  \n";
    cout << " \t\t\t [1] Log In \n";
    cout << " \t\t\t [2] Register \n";
    cout << " \t\t\t [3] Display All Players \n";
    cout << " \t\t\t [4] Exit \n";

    cout << " \t\t\t  \n";
    cout << "\t\t\t Select Your Choice: ";
    cin >> choice;

    if (choice == '1') {
        system("cls");
        checkLogin();

    } else if (choice == '2') {
        system("cls");
        useRegister();

    } else if (choice == '3'){
        system("cls");
        displayAllPlayers();

    } else if (choice == '4'){
        system("cls");
        cout << "\n \t\t\t Exiting program. Goodbye!" << "\n";

    }else {
        system("cls");
        cout << "\n \t\t\t Invalid option selected! \n";
        welcomeMenu();
    }
}

void mainMenu(){

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                   Welcome back!                |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t [1] Display All Players \n";
    cout << "\t\t\t [2] Search Players \n";
    cout << "\t\t\t [3] Add Players \n";
    cout << "\t\t\t [4] Remove Players \n";
    cout << "\t\t\t [5] Edit Player Information \n";
    cout << "\t\t\t [6] Manage Teams \n";
    cout << "\t\t\t [7] Logout \n";
    cout << "\n \t\t\t Enter your choice: ";

    cin >> choice;

    switch (choice) {
        case '1':
            system("cls");
            displayAllPlayers();
            break;
        case '2':
            system("cls");
            searchPlayers();
            break;
        case '3':
            system("cls");
            addPlayers();
            break;
        case '4':
            system("cls");
            break;
        case '5':
            system("cls");
            break;
        case '6':
            system("cls");
            break;
        case '7':
            system("cls");
            welcomeMenu();
            break;
        default:
            system("cls");
            cout << "\n \t\t\t Invalid option selected! \n";
            mainMenu();
            break;
    }
}

void displayAllPlayers(){

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                    All Players                 |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << "\n \t\t\t " << line;
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }

    backOption();
}

void searchPlayers(){

    cout << " \t\t\t ________________________________________________\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|                  Search Players                |\n";
    cout << " \t\t\t|                                                |\n";
    cout << " \t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << " \t\t\t|                      V.0.1                     |\n";
    cout << " \t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Name : ";
    cin >> userName;

    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        while (getline(inFile, playerName)) {
            if (playerName == "First Name: " + userName){
                getline(inFile, playerDob);
                getline(inFile, playerScored);
                getline(inFile, playerTeam);
                cout << "\n \t\t\t " << playerName;
                cout << "\n \t\t\t " << playerDob;
                cout << "\n \t\t\t " << playerScored;
                cout << "\n \t\t\t " << playerTeam;
            }
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }

    backOption();
}

void addPlayers(){
    system("cls");

    cout << "\n \t\t\t Enter Player's First Name: ";
    cin >> playerFirsName;

    cout << "\n \t\t\t Enter Player's Last Name: ";
    cin >> playerLastName;

    cout << "\n \t\t\t Enter Player's Date of Birth: ";
    cin >> playerDob;

    cout << "\n \t\t\t Enter Player's Runs Scored: ";
    cin >> playerScored;

    cout << "\n \t\t\t Enter Player's Team: ";
    cin >> playerTeam;

    ofstream outFile(F_PlayersData, ios::app);
    if (outFile.is_open()) {
        outFile << "ID: " << P_ID << "\n";
        outFile << "First Name: " << playerFirsName << "\n";
        outFile << "Full Name: " << playerFirsName << " " << playerLastName << "\n";
        outFile << "Date of Birth: " << playerDob << "\n";
        outFile << "Runs Scored: " << playerScored << "\n";
        outFile << "Team: " << playerTeam << "\n";
        outFile << "------------------------------------------------\n";
        outFile.close();
        cout << "\n \t\t\t Add Record Successful! \n";
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }

    backOption();
}

int main(){

    welcomeMenu();

    return 0;
}
