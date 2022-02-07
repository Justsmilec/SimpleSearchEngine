#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

    vector<string> loadSearchedList(vector<string>,string);
    void set_cursor(int,int);
    int check_substring(string,string);
    void Clear()
    {
        cout << "\x1B[2J\x1B[H";
    }

    void display(vector<string> list1,string displayed,bool search);

    void clearConsole(int length);
    int main()
    {
        bool repeat = true;
        string myText = "programming.txt";
        int c,i=0;

		vector<string > list;
		ifstream file(myText);

		string data = "";

		string searchField;
        cout<< "Search...\n\n";


		while(getline(file, data,',')){

            list.push_back(data);
		}
		file.close();

		display(list,"",true);
		cout << "\n\n";

		bool typed = false;
		int count = 0;

        while (repeat)
        {

            set_cursor(25,0);

            Sleep(100);


                char ch2 = getche();

                if(ch2){
                    if(ch2 == '\b'){
                       if(!searchField.empty()){
                        searchField.pop_back();

                       }
                       if(searchField.length() < 3){
                         display(list,searchField,true);

                       }

                    } else{
                        searchField.push_back(ch2);

                    }
                    set_cursor(10,0);
                    cout<<searchField;
                    if(searchField.length() > 3){
                            display(loadSearchedList(list,searchField),searchField,typed);
                    }


                }

                //if(searchField.length() > 3){

                //loadSearchedList(list,searchField);


        }

        return 0;
    }


void set_cursor(int x = 0 , int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition ( handle , coordinates );
}

vector<string> loadSearchedList(vector<string> list1 , string searchField1){

    vector<string> newList;
    newList.clear();
    for(std::vector<string>::size_type i = 0; i != list1.size(); i++) {
            if (list1[i].find(searchField1) != std::string::npos) {
                newList.push_back(list1[i]);
            }
    }
    set_cursor(0,2);
    cout<<newList.size();
    return newList;

}


void display(vector<string> list1,string displayedSearchField,bool search){
    clearConsole(list1.size());

    set_cursor(0,3);

    for(vector<string>::iterator   it = list1.begin();
                                it != list1.end();
                                it++ ){
            cout<< *it;

    }
    set_cursor(20,0);

}

void clearConsole(int length){
    for(int j = 3;j<30;j++){
            set_cursor(20,j);
            printf("\r                             ");


    }
}

