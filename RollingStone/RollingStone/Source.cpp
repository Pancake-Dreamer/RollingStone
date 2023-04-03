#include <iostream>
#include <string>
#include "sqlite3.h"
//#include "sqlite3.c"
//# include <B:\RollingStone\sqlite3ext.h>
//# include <B:\RollingStone\sqlite3.c>
//#pragma comment(lib, "sqlite3.lib")

using namespace std;


int main() {

    cout << "Welcome to my thing!" << endl; 

    sqlite3* db;

    int rc = sqlite3_open("RS.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM Album ORDER BY AlbumRank DESC;", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int rank = sqlite3_column_int(stmt, 2);
        std::cout << id << ". " << title << " ( #" << rank << ")" << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    /*bool isFinished = false;
    int selection = 0;
    string albumName;
    string artistName;

    cout << "Please select one of the following options" << endl << endl;
    cout << "1. Search by Album" << endl;
    cout << "2. Search by Artist" << endl;
    cout << "3. Quit" << endl << endl;

    while (!isFinished) {
        cout << "What'll it be? ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            cout << "You selected 1" << endl << endl;
            cout << "Enter the album title you'd like to search for: ";
            getline(cin, albumName);
            break;
        case 2:
            cout << "You selected 2" << endl << endl;
            cout << "Enter the artist you'd like to search for: ";
            getline(cin, artistName);
            break;
        case 3:
            isFinished = true;
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid selection. Please try again." << endl << endl;
            break;
        }
        
    }*/

	system("pause");
	return 0;
}

