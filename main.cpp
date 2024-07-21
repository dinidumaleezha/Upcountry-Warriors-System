#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------Start-Global Variables----------------------------------------//
char choice;
int P_ID;
string userName, password;
string selectTeam, selectTeam1, selectTeam2, inputTeamID;
string teamID, teamName, teamPath, teamPath1, teamPath2, teamName1, teamName2;
string inputID, userID, line, recordLine, teame2Str, nameStr;
string playerName, playerFirsName, playerLastName, playerDob, playerScored, playerTeam, playerTeam2;

const string F_PlayersData = "players.txt";
const string F_teamData = "teamData.txt";
const string F_path = "team";
const string adminUsername = "user";
const string adminPassword = "1234";

bool loginSuccess = false;
bool playerFound = false;
bool anotherTeam = false;
bool inAnotherTeam = false;
bool noInvalid = false; //----Check-N------------------------------------//
//---------End-Global Variables------------------------------------------//

//---------Start-Function Declarations-----------------------------------//
void welcomeMenu();
void checkLogin();
void mainMenu();
void logout();

void managePlayers();
void addPlayers();
void displayAllPlayers();
void searchPlayers();
void removePlayers(); // Player's Teame Check
void removePlayer(string userName); // Remove Player

void manageTeams();
void addTeams();
void ViewTeam();
void TeamDetail(string fileName);
void AddMemberTeam1(int ID, string playerfName, string playerlName, string teamPath);
void AddMemberTeam2(int ID, string playerfName, string playerlName, string teamPath);

void selectTeamData(string inputTeamID);
void checkTeam(string checkID); //--See if the player has more than one team--//
void backOption();
//---------End-Function Declarations-------------------------------------//

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

//---------Start-Select Team---------------------------------------------//
void selectTeamData(string inputTeamID){
    ifstream inFile(F_teamData);
    if (inFile.is_open()) {
        while (inFile >> teamID >> teamName) {
            if (teamID == inputTeamID) {
                //cout << "\n\t\t\t " << teamID << " | " << teamName << endl;
                inFile.close();
                return;
            }
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
}
//---------End-Select Team-----------------------------------------------//

//---------Start-Check Team----------------------------------------------//
void checkTeam(string checkID){
    ifstream inFile(F_PlayersData);
    if (inFile.is_open()) {
        while (getline(inFile, userID)) {
            if (userID == "ID: " + checkID){
                playerFound = true;
                getline(inFile, userID);
                getline(inFile, playerName);
                getline(inFile, playerDob);
                getline(inFile, playerScored);
                getline(inFile, playerTeam);
                getline(inFile, playerTeam2);

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
        ViewTeam();

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

//---------Start-User Login-----------------------------------------------//
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
}
//---------End-User Login-------------------------------------------------//

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
    cout << "\t\t\t [3] Manage Players \n";
    cout << "\t\t\t [4] Manage Teams \n";
    cout << "\t\t\t [5] Logout \n";
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
            managePlayers();
            break;
        case '4':
            system("cls");
            manageTeams();
            break;
        case '5':
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
            } else{
                cout << "\n \t\t\t Player not found!\n";
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

//---------Start-Manage Players------------------------------------------//
void managePlayers(){
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|            \xB2\xB2\xB2\ MANAGE PLAYERS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t [1] Add Players \n";
    cout << "\t\t\t [2] Remove Players \n";
    cout << "\t\t\t [3] Back Menu \n";
    cout << "\n \t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice){
        case '1':
            system("cls");
            addPlayers();
            break;
        case '2':
            system("cls");
            removePlayers();
            break;
        case '3':
            system("cls");
            mainMenu();
            break;
        default:
            system("cls");
            cout << "\n \t\t\t Invalid option selected! \n";
            managePlayers();
            break;
    }
}
//---------End-Manage Players--------------------------------------------//

//---------Start-Add Players---------------------------------------------//

void addPlayers(){
    system("cls");

    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|  ===> Upcountry Warriors Baseball Clubs <===   |\n";
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

    TeamDetail(F_teamData);

    cout << "\n";
    cout << "\n \t\t\t Enter Team Number: ";
    cin >> selectTeam;
    inputTeamID = selectTeam;

    selectTeamData(inputTeamID);
    playerTeam = teamName;
    teamPath1 = teamID;

    cout << "\n \t\t\t Should this player be added to another team? (y or n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        anotherTeam = true;
        cout << "\n \t\t\t Enter Player's Second Team: ";
        cin >> selectTeam2;
        inputTeamID = selectTeam2;

        selectTeamData(inputTeamID);
        playerTeam2 = teamName;
        teamPath2 = teamID;

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
                AddMemberTeam1(P_ID, playerFirsName, playerLastName, teamPath1);
                AddMemberTeam2(P_ID, playerFirsName, playerLastName, teamPath2);
                anotherTeam = false;
            }else{
                outFile << "------------------------------------------------\n";
                AddMemberTeam1(P_ID, playerFirsName, playerLastName, teamPath1);
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
    ofstream outFile("team" + teamPath + ".txt", ios::app);
        if (outFile.is_open()){
            outFile << "ID: " << ID << "\n";
            outFile << "Name: " << playerfName << " " << playerlName << "\n";
            outFile << "------------------------------------------------\n";
            outFile.close();
        } else {
            cout << "\n \t\t\t Error opening file!\n";
        }
}
void AddMemberTeam2(int ID, string playerfName, string playerlName, string teamPath){
    ofstream outFile("team" + teamPath + ".txt", ios::app);
        if (outFile.is_open()){
            outFile << "ID: " << ID << "\n";
            outFile << "Name: " << playerfName << " " << playerlName << "\n";
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
                cout << "\n \t\t\t Player deleted successfully." << endl;

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

//---------Start-Manage Team---------------------------------------------//
void manageTeams(){
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|              \xB2\xB2\xB2\ MANAGE TEAMS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t [1] Add Teams \n";
    cout << "\t\t\t [2] View Teams \n";
    cout << "\t\t\t [3] Back Menu \n";
    cout << "\n \t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice){
        case '1':
            system("cls");
            addTeams();
            break;
        case '2':
            system("cls");
            ViewTeam();
            break;
        case '3':
            system("cls");
            mainMenu();
            break;
        default:
            system("cls");
            cout << "\n \t\t\t Invalid option selected! \n";
            manageTeams();
            break;
    }
}
//---------End-Manage Team----------------------------------------------//

//---------Start-Add Team-----------------------------------------------//
void addTeams(){
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                 \xB2\xB2\xB2\ ADD TEAMS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    cout << "\n \t\t\t Enter Team ID: ";
    cin >> teamID;
    cout << "\n \t\t\t Enter Team Name: ";
    getline(cin >> ws, teamName);

    ofstream outFile(F_teamData, ios::app);
    if (outFile.is_open()){
        outFile << teamID << " " << teamName << "\n";
        outFile.close();
        cout << "\n \t\t\t Team Added Successful! \n";
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }
    backOption();
}
//---------End-Add Team-------------------------------------------------//

void ViewTeam(){
    cout << "\t\t\t ________________________________________________\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|   ===> Upcountry Warriors Baseball Clubs <===  |\n";
    cout << "\t\t\t|                      V.0.1                     |\n";
    cout << "\t\t\t|________________________________________________|\n";
    cout << "\t\t\t|                                                |\n";
    cout << "\t\t\t|                 \xB2\xB2\xB2\ ALL TEAMS \xB2\xB2\xB2\              |\n";
    cout << "\t\t\t|________________________________________________|\n";

    TeamDetail(F_teamData);

    cout << "\n";
    cout << "\n \t\t\t Enter Team Number: ";
    cin >> selectTeam;
    TeamDetail("team" + selectTeam+ ".txt");

    backOption();
}

void TeamDetail(string fileName){

    ifstream inFile(fileName);
    if (inFile.is_open()){
        while (getline(inFile, line)){
            cout << "\n \t\t\t " << line;
        }
        inFile.close();
    } else {
        cout << "\n \t\t\t Error opening file!\n";
    }

}
//---------Start-main----------------------------------------------------//
int main(){

    welcomeMenu();

    return 0;
}
//---------End-Main------------------------------------------------------//

































