#include <iostream>
#include "stacks/myStack.h"

using namespace std;

bool getInput(string &input);
void setToUpperCase(string &who);
void removeSpacesEtal(string &who);
void check(string line);
string reverse(const string &line);

int main()
{
    string input;
    while(getInput(input))
        check(input);

//    stacks::myNode<char> *newNode = new stacks::myNode<char>('A');
//
//    newNode->returnVal();
//    cout << "\naccess: " <<(newNode->access());

    return 0;
}

string reverse(const string &line)
{
    string reversed;
    try
    {
        stacks::myStack<char> abba(line.size());
        for(size_t i = 0; i < line.size(); abba.push(line[i++]));

        while(!abba.isEmpty())
            reversed += abba.pop();

    }
    catch(stacks::BASESTACK_ERRORS e)
    {
        switch(e)
        {
            case stacks::BASE_EMPTY : cout<<"Empty stack error"<<endl;
                break;
            case stacks::BASE_FULL : cout<<"Full stack error"<<endl;
                break;
            default:
                cout <<"\nAn Unknown error has occured." << endl;
        };
    }
    return reversed;
}


void check(string line)
{
    cout<<line<<" is ";
    setToUpperCase(line);
    removeSpacesEtal(line);
    string rLine = reverse(line);

    bool debug = false;
    if (debug)
        cout << "\nReversed Line: "<< rLine;

    if(line != rLine)
        cout<<"not ";
    cout<<"a palindrome"<<endl;
}

bool getInput(string &input)
{
    cout<<"Input: ";
    getline(cin,input);
    return !input.empty();
}

void setToUpperCase(string &who)
{
    for(size_t i = 0; i < who.size(); ++i)
        who[i] = toupper(who[i]);
}

void removeSpacesEtal(string &who)
{
    size_t pos;
    while((pos = who.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) < who.size())
        who.erase(pos,1);
}