#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------Start-Variables-----------------------------------------------//
string inputID,userID, userName, password, firstName, lastName, Dob, line, recordLine;
string playerName, playerFirsName, playerLastName, playerDob,playerTeam2, playerTeam, playerScored;
string team1Path, team2Path;
string teame2Str, nameStr; //----Substring-------------------------------//
const string F_UserData = "userdata.txt";
const string F_PlayersData = "players.txt";
const string adminUsername = "user";
const string adminPassword = "1234";
int P_ID, selectTeam, selectTeam2;
char choice;

bool loginSuccess = false;
bool playerFound = false;
bool anotherTeam = false;
bool inAnotherTeam = false;
bool noInvalid = false; //----Check-N------------------------------------//
//---------End-Variables-------------------------------------------------//

//---------Start-Team Structures-----------------------------------------//
struct {
  int number;
  string teamName;
  string teamFileName;
} team1, team2, team3, team4, team5;
//---------End-Team Structures-------------------------------------------//

//---------Start-Function Declarations-----------------------------------//
void welcomeMenu();
//void useRegister();
void checkLogin();
void mainMenu();
void displayAllPlayers();
void ViewTeamDetails();
void addPlayers();
void searchPlayers();
void removePlayers(); // Player's Teame Check
void removePlayer(string userName); // Remove Player
void editPlayerInfo();
void manageTeams();
void AddMemberTeam1(int ID, string playerfName, string playerlName, string teamPath);
void AddMemberTeam2(int ID, string playerfName, string playerlName, string teamPath);
void logout();
void teamDeclarations();
void checkTeam(string checkID); //--See if the player has more than one team--//
void backOption();
//---------End-Function Declarations-------------------------------------//

//---------Start-Team Declarations---------------------------------------//
void teamDeclarations(){
    team1.number = 1;
    team1.teamName = "New York Yankees";
    team1.teamFileName = "team1.txt";

    team2.number = 2;
    team2.teamName = "Chicago Cubs";
    team2.teamFileName = "team2.txt";

    team3.number = 3;
    team3.teamName = "Detroit Tigers";
    team3.teamFileName = "team3.txt";

    team4.number = 4;
    team4.teamName = "Iowa Cubs";
    team4.teamFileName = "team4.txt";

    team5.number = 5;
    team5.teamName = "Reno Aces";
    team5.teamFileName = "team5.txt";
}
//---------End-Team Declarations-----------------------------------------//

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

//---------Start-Check Team----------------------------------------------//
void checkTeam(string checkID){
    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        while (getline(inFile, userID)) {
            if (userID == "ID: " + checkID){
                playerFound = true;
                getline(inFile, userID); // Line 1
                getline(inFile, playerName);// Line 2
                getline(inFile, playerDob); // Line 3
                getline(inFile, playerScored); // Line 4
                getline(inFile, playerTeam); // Line 5
                getline(inFile, playerTeam2); // Line 6

                teame2Str = playerTeam2.substr(0, 6);
                nameStr = playerName.substr(11);

                if (teame2Str == "Team 2"){
                    inAnotherTeam = true;
                }
            }else{
                playerFound = false;
            }
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}
//---------End-Check Team------------------------------------------------//

//---------------------------Main requirements---------------------------//

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
    cout << "\t\t\t [2] View Team Details \n";
    cout << "\t\t\t [3] Exit \n";

    cout << " \t\t\t  \n";
    cout << "\t\t\t Select Your Choice: ";
    cin >> choice;

    if (choice == '1') {
        system("cls");
        checkLogin();

    } else if (choice == '2'){
        system("cls");
        ViewTeamDetails();

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
void useRegister(){
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
    if (outFile.is_open()){
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
void checkLogin(){
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

    switch (choice){
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
        while (getline(inFile, line)){
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

    cout << "\n \t\t\t Enter User ID: ";
    cin >> inputID;

    checkTeam(inputID);

    ifstream inFile(F_PlayersData);
    if (inFile.is_open()){
        while (getline(inFile, userID)){
            if (userID == "ID: " + inputID){
                getline(inFile, userID);
                getline(inFile, playerName);
                getline(inFile, playerDob);
                getline(inFile, playerScored);
                getline(inFile, playerTeam);
                cout << "\n \t\t\t " << playerName;
                cout << "\n \t\t\t " << playerDob;
                cout << "\n \t\t\t " << playerScored;
                cout << "\n \t\t\t " << playerTeam;

                if (inAnotherTeam){
                    getline(inFile, playerTeam2);
                    cout << "\n \t\t\t " << playerTeam2;
                    inAnotherTeam = false;
                }
                break;
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

    cout << "\n \t\t\t All Teams \n";
    teamDeclarations();
    cout << "\n \t\t\t " << team1.number << ". " << team1.teamName << endl;
    cout << "\t\t\t " << team2.number << ". " << team2.teamName << endl;
    cout << "\t\t\t " << team3.number << ". " << team3.teamName << endl;
    cout << "\t\t\t " << team4.number << ". " << team4.teamName << endl;
    cout << "\t\t\t " << team5.number << ". " << team5.teamName << endl;

    cout << "\n \t\t\t Enter Team Number: ";
    cin >> selectTeam;

    if (selectTeam == team1.number){
        playerTeam = team1.teamName;
        team1Path = team1.teamFileName;
    } else if (selectTeam == team2.number){
        playerTeam = team2.teamName;
        team1Path = team2.teamFileName;
    } else if (selectTeam == team3.number){
        playerTeam = team3.teamName;
        team1Path = team3.teamFileName;
    } else if (selectTeam == team4.number){
        playerTeam = team4.teamName;
        team1Path = team4.teamFileName;
    } else if (selectTeam == team5.number){
        playerTeam = team5.teamName;
        team1Path = team5.teamFileName;
    } else {
        cout << "\n \t\t\t Invalid selected! \n";
    }

    cout << "\n \t\t\t Should this player be added to another team? (y or n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        anotherTeam = true;
        cout << "\n \t\t\t Enter Player's Second Team: ";
        cin >> selectTeam2;

        if (selectTeam2 == team1.number){
            playerTeam2 = team1.teamName;
            team2Path = team1.teamFileName;
        } else if (selectTeam2 == team2.number){
            playerTeam2 = team2.teamName;
            team2Path = team2.teamFileName;
        } else if (selectTeam2 == team3.number){
            playerTeam2 = team3.teamName;
            team2Path = team3.teamFileName;
        } else if (selectTeam2 == team4.number){
            playerTeam2 = team4.teamName;
            team2Path = team4.teamFileName;
        } else if (selectTeam2 == team5.number){
            playerTeam2 = team5.teamName;
            team2Path = team5.teamFileName;
    } else {
        cout << "\n \t\t\t Invalid selected! \n";
    }

    } else if (choice == 'n' || choice == 'N'){
        noInvalid = true;
    }
    ofstream outFile(F_PlayersData, ios::app);
        if (outFile.is_open()){
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
                AddMemberTeam1(P_ID, playerFirsName, playerLastName, team1Path);
                AddMemberTeam2(P_ID, playerFirsName, playerLastName, team2Path);
                anotherTeam = false;
            }else{
                outFile << "------------------------------------------------\n";
                AddMemberTeam1(P_ID, playerFirsName, playerLastName, team1Path);
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

void AddMemberTeam1(int ID, string playerfName, string playerlName, string teamPath){
    ofstream outFile(teamPath, ios::app);
        if (outFile.is_open()){
            outFile << "ID: " << ID << "\n";
            outFile << "Full Name: " << playerfName << " " << playerlName << "\n";
            outFile << "------------------------------------------------\n";
            outFile.close();
        } else {
            cout << "\n \t\t\t Error opening file!\n";
        }
}
void AddMemberTeam2(int ID, string playerfName, string playerlName, string teamPath){
    ofstream outFile(teamPath, ios::app);
        if (outFile.is_open()){
            outFile << "ID: " << ID << "\n";
            outFile << "Full Name: " << playerName << " " << playerlName << "\n";
            outFile << "------------------------------------------------\n";
            outFile.close();
        } else {
            cout << "\n \t\t\t Error opening file!\n";
        }
}
//---------End-Add Players-----------------------------------------------//

//---------Start-Remove Players------------------------------------------//
void removePlayers(){
    nameStr = " ";
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|              \xB2\xB2\xB2\ REMOVE PLAYERS \xB2\xB2\xB2\            |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter the ID of the player to delete: ";
    cin >> inputID;

    checkTeam(inputID);

    cout << "\n \t\t\t Do you want to remove " << nameStr << "? (y or n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        removePlayer(inputID);
    } else if (choice == 'n' || choice == 'N'){
        system("cls");
        mainMenu();
    } else{
        system("cls");
        mainMenu();
    }
}

void removePlayer(string inputID){
    ifstream inFile(F_PlayersData);
    if (inFile.is_open()){
        vector<string> fileContents;
        while (getline(inFile, line)) {
            if (line == "ID: " + inputID){
                playerFound = true;
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);

                if (inAnotherTeam){
                    getline(inFile, line);
                    inAnotherTeam = false;
                }
            } else {
                fileContents.push_back(line);
            }
        }
        inFile.close();

        if (playerFound){
            ofstream outFile(F_PlayersData);
            if (outFile.is_open()) {
                for (const string& recodeLine : fileContents) {
                    outFile << recodeLine << endl;
                }
                outFile.close();
                playerFound = false;
                cout << "\n \t\t\t Player " << userName << " deleted successfully." << endl;

            } else {
                cout << "\n \t\t\t Error opening file for writing!\n";
            }
        } else {
            cout << "\n \t\t\t Player not found!\n";
        }
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
    backOption();
}
//---------End-Remove Players--------------------------------------------//

void ViewTeamDetails(){
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                 \xB2\xB2\xB2\ ALL TEAMS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    teamDeclarations();
    cout << "\n \t\t\t " << team1.number << ". " << team1.teamName << endl;
    cout << "\t\t\t " << team2.number << ". " << team2.teamName << endl;
    cout << "\t\t\t " << team3.number << ". " << team3.teamName << endl;
    cout << "\t\t\t " << team4.number << ". " << team4.teamName << endl;
    cout << "\t\t\t " << team5.number << ". " << team5.teamName << endl;

    cout << "\n \t\t\t Enter Team Number: ";
    cin >> selectTeam;

}

//---------Start-main----------------------------------------------------//
int main(){

    welcomeMenu();

    return 0;
}
//---------End-Main------------------------------------------------------//

































