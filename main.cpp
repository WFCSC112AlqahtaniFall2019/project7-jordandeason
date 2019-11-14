#include <iostream>
#include<fstream>
#include<string>
#include"Queue.h"
#include"SortedLinkedList.h"
#include"Data.h"
#include"Stack.h"

using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("../WNBAStats.csv");
    outFile.open("stacked.txt");

    if (!inFile.is_open()) {//enters loop if csv file isn't accessible
        cout << "File is not open.";
        return 1;//error
    }

    //objects of classes
    Stack s;
    Queue q;
    SortedLinkedList link;

    string AST;//assists
    string STL;//steals
    string PTS;//points
    string MIN;//minutes played

    //getting the chosen 4 data members
    getline(inFile, AST, ',');
    getline(inFile, STL, ',');
    getline(inFile, PTS, ',');
    getline(inFile, MIN);

    //converting the data members to doubles
    double ASTnum = stod(AST);
    double STLnum = stod(STL);
    double PTSnum = stod(PTS);
    double MINnum = stod(MIN);

    cout << "Reading ../WNBAStats.csv…" << endl;
    //reads csv file while file is found
    while (!inFile.eof()) {
        s.push_head(Data(ASTnum, STLnum, PTSnum, MINnum));//adding new data to the stack
        q.enqueue_tail(Data(ASTnum, STLnum, PTSnum, MINnum));//adding new data to the queue
        link.insertSorted(Data(ASTnum, STLnum, PTSnum, MINnum));//adding new data to the sorted linked list
    }

    cout << "Writing data in stack inserted at head into stacked.txt." << endl;
    bool print = true;
    while (print) {
        outFile << s.print() << endl;//printing stack
        print = s.pop_head();
    }

    inFile.close();
    outFile.close();

    cout << "Writing data in queue inserted at tail into queued.txt." << endl;
    outFile.open("queued");
    print = true;
    while (print) {
        outFile << q.print() << endl;//printing queue
        print = q.dequeue_head();
    }
    outFile.close();

    cout << "Writing data in sorted linked list sorted by MINnum into sorted.txt." << endl;
    outFile.open("sorted");
    link.print(outFile);//printing sorted linked list
    outFile.close();

    return 0;
}