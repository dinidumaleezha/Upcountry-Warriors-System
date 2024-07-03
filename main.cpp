#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------Start-Variables-----------------------------------------------//
string userName, password, firstName, lastName, Dob, line, recordLine;
string playerName, playerFirsName, playerLastName, playerDob,playerTeam2, playerTeam, playerScored;
const string F_UserData = "userdata.txt";
const string F_PlayersData = "players.txt";
const string adminUsername = "user";
const string adminPassword = "1234";
int userID, P_ID;
char choice;

bool loginSuccess = false;
bool playerFound = false;
bool anotherTeam = false;
bool noInvalid = false; //----Check-N------------------------------------//
//---------End-Variables-------------------------------------------------//

//---------Start-Function Declaration------------------------------------//
void welcomeMenu();
//void useRegister();
void checkLogin();
void mainMenu();
void displayAllPlayers();
void addPlayers();
void searchPlayers();
void removePlayers();
void editPlayerInfo();
void manageTeams();
void logout();
void backOption();
//---------End-Function Declaration--------------------------------------//

//---------Start-Back Option---------------------------------------------//
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
//---------End-Back Option-----------------------------------------------//

//---------Start-Welcome Menu--------------------------------------------//
void welcomeMenu(){

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|           \xB2\xB2\xB2\ HELLO! WELCOME USER! \xB2\xB2\xB2\         |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\t\t\t \n";
    cout << "\t\t\t [1] Log In \n";
    //cout << "\t\t\t [2] Register \n";
    cout << "\t\t\t [2] Display All Players \n";
    cout << "\t\t\t [3] Exit \n";

    cout << " \t\t\t  \n";
    cout << "\t\t\t Select Your Choice: ";
    cin >> choice;

    if (choice == '1') {
        system("cls");
        checkLogin();

    } else if (choice == '2'){
        system("cls");
        displayAllPlayers();

    } else if (choice == '3'){
        system("cls");
        cout << "\n \t\t\t Exiting program. Goodbye!" << "\n";

    }else {
        system("cls");
        cout << "\n \t\t\t Invalid option selected! \n";
        welcomeMenu();
    }
}
//---------End-Welcome Menu----------------------------------------------//

//---------Start-Use Register--------------------------------------------//
void useRegister() {
    system("cls");

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                User Registration               |\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";

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
        system("cls");
        checkLogin();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}
//---------End-Use Register----------------------------------------------//

//---------Start-Use Login-----------------------------------------------//
void checkLogin() {

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                  Welcome Back!                 |\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Username: ";
    cin >> userName;

    cout << "\n \t\t\t Enter Password: ";
    cin >> password;

    if (userName == adminUsername){
        if (password == adminPassword){
                loginSuccess = true;
        } else {
            system("cls");
            cout << "\n \t\t\t Invalid Password! \n";
            checkLogin();
        }
    } else {
        system("cls");
        cout << "\n \t\t\t Invalid Username! \n";
        checkLogin();
    }

    if (loginSuccess){
            cout << "\n \t\t\t Login Successful! \n";
            system("cls");
            mainMenu();
    }
/*
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
*/
}
//---------End-Use Login-------------------------------------------------//

//---------Start-Main Menu-----------------------------------------------//
void mainMenu(){

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|  ====> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                    MAIN MENU                   |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t [1] Display All Players \n";
    cout << "\t\t\t [2] Search Players \n";
    cout << "\t\t\t [3] Add Players \n";
    cout << "\t\t\t [4] Remove Players \n";
    cout << "\t\t\t [5] Edit Player Information \n";
    cout << "\t\t\t [6] Add Teams \n";
    cout << "\t\t\t [7] Manage Teams \n";
    cout << "\t\t\t [8] Logout \n";
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
            removePlayers();
            break;
        case '5':
            system("cls");
            break;
        case '6':
            system("cls");
            break;
        case '7':
            system("cls");
            break;
        case '8':
            system("cls");
            loginSuccess = false;
            welcomeMenu();
            break;
        default:
            system("cls");
            cout << "\n \t\t\t Invalid option selected! \n";
            mainMenu();
            break;
    }
}
//---------End-Main Menu-------------------------------------------------//

//---------Start-Display AllPlayers--------------------------------------//
void displayAllPlayers(){

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|               \xB2\xB2\xB2\ ALL PLAYERS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

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
//---------End-Display AllPlayers----------------------------------------//

//---------Start-Search Players------------------------------------------//
void searchPlayers(){

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|              \xB2\xB2\xB2\ SEARCH PLAYERS \xB2\xB2\xB2\            |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Name : ";
    cin >> userName;

    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        while (getline(inFile, playerName)) {
            if (playerName == "First Name: " + userName){
                getline(inFile, playerName);
                getline(inFile, playerDob);
                getline(inFile, playerScored);
                getline(inFile, playerTeam);
                getline(inFile, playerTeam2);
                cout << "\n \t\t\t " << playerName;
                cout << "\n \t\t\t " << playerDob;
                cout << "\n \t\t\t " << playerScored;
                cout << "\n \t\t\t " << playerTeam;
                cout << "\n \t\t\t " << playerTeam2;
            }
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }

    backOption();
}
//---------End-Search Players--------------------------------------------//

//---------Start-Add Players---------------------------------------------//
void addPlayers(){
    system("cls");

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|               \xB2\xB2\xB2\ ADD PLAYERS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Player's ID: ";
    cin >> P_ID;

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

    cout << "\n \t\t\t Should this player be added to another team? (y or n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        anotherTeam = true;
        cout << "\n \t\t\t Enter Player's Team 2: ";
        cin >> playerTeam2;
    } else if (choice == 'n' || choice == 'N'){
        noInvalid = true;
    }
    ofstream outFile(F_PlayersData, ios::app);
        if (outFile.is_open()) {
            outFile << "ID: " << P_ID << "\n";
            outFile << "First Name: " << playerFirsName << "\n";
            outFile << "Full Name: " << playerFirsName << " " << playerLastName << "\n";
            outFile << "Date of Birth: " << playerDob << "\n";
            outFile << "Runs Scored: " << playerScored << "\n";
            outFile << "Team: " << playerTeam << "\n";

            if (anotherTeam){
                outFile << "Team 2: " << playerTeam2 << "\n";
                outFile << "------------------------------------------------\n";
                cout << "\n \t\t\t Add Record Successful! \n";
                anotherTeam = false;
            }else{
                outFile << "------------------------------------------------\n";
                if (noInvalid){
                    cout << "\n \t\t\t Add Record Successful! \n";
                } else {
                    cout << "\n \t\t\t You have entered another code instead of 'n' and, \n";
                    cout << "\n \t\t\t We have included this player in " << playerTeam << " group only.";
                }
            }
            outFile.close();
        } else {
            cout << "\n \t\t\t Error opening file!\n";
        }

    backOption();
}
//---------End-Add Players-----------------------------------------------//

//---------Start-Remove Players------------------------------------------//
void removePlayers(){

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|             \xB2\xB2\xB2\ REMOVE PLAYERS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter the name of the player to delete: ";
    cin >> userName;

    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        vector<string> fileContents;

        while (getline(inFile, line)) {
            if (line == "First Name: " + userName) {

                playerFound = true;

                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);

            } else {
                fileContents.push_back(line);
            }
        }
        inFile.close();

        if (playerFound) {
            ofstream outFile(F_PlayersData);
            if (outFile.is_open()) {
                for (const string& recodeLine : fileContents) {
                    outFile << recodeLine << endl;
                }
                outFile.close();
                cout << "\n \t\t\t Player " << userName << " deleted successfully." << endl;
                backOption();
            } else {
                cout << "\n \t\t\t Error opening file for writing!\n";
            }
        } else {
            cout << "\n \t\t\t Player not found!\n";
        }

    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}
//---------End-Remove Players--------------------------------------------//

//---------Start-main----------------------------------------------------//
int main(){

    welcomeMenu();

    return 0;
}
//---------End-Main------------------------------------------------------//
