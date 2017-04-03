#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VDbl;
typedef vector<VDbl>   MDbl;

void sort(VDbl list, VDbl splitAr, int round);
bool checkRout ( VDbl list);
void printList( VDbl List);

int main(int argc, char *argv[])
{
    int round = 1;
    VDbl list;

    cout << "Laenge der Liste angeben"<<endl;
    int size;
    cin >>size;

    for ( int i = 0; i< size; i++){
        cout << i+1<<". Wert eintragen"<<endl;
        cout << "\t";
        int value;
        cin >> value;
        list.push_back(value);
    }
    cout <<endl;

    VDbl splitAr = {0,list.size()};
    sort (list, splitAr, round);
}

void sort (VDbl list, VDbl splitAr, int round){

  while (checkRout(list) == false){
    VDbl pivot; // enthält alle Splitwerde der Reihe nach und kann so in Schleife nacheinander abgerufen werden
    VDbl sortstep;  // zwischenarray das nach den einzelnen sortierungsschritten entsteht, wird am ende auf list überschrieben
    VDbl splitStep = {0};   // zwischenarray dass alle indizes der trennstellen enthält(neue Pivots) wird dann auf splitArt überschrieben, dass dann die Trennstellen für die näcjste Runde enthält

    for (int i = 0; i < round; i++){
        pivot.push_back(int ( list[ splitAr[i+1] -1] ) );
    }

    for (int i = 0; i<round; i++){
        if (i+1 < splitAr.size() ){
            for (int j = splitAr[i]; j < splitAr[i+1]; j++){

              if ( list[j] < pivot[i] )
                  sortstep.push_back(list[j]);
            }
            int a;
            for (int j = splitAr[i]; j < splitAr[i+1]; j++){

              if ( list[j] == pivot[i] ){
                  sortstep.push_back(list[j]);
                  a = sortstep.size()-1;     //index der neuen Trennstelle im nächsten Durchlauf, daher hier gleichheit.. zwischenvariable für den fall dass mehrere gleich sind. So wird immer die letzte gepusht
              }
            }
            splitStep.push_back(a);

            for (int j = splitAr[i]; j < splitAr[i+1]; j++){

              if ( list[j] > pivot[i] )
                  sortstep.push_back(list[j]);
            }
        }
    }


    splitStep.push_back( sortstep.size());
    round++;
    splitAr = splitStep;
    list = sortstep;

    }
}

bool checkRout(VDbl list){

    for (int i = 0; i< list.size()-1; i++){

        if (list[i] > list[i+1] )
                return false;
    }
    printList(list);
    return true;
}

void printList( VDbl list){
    for (int i = 0; i < list.size(); i++){
        cout<< i+1<<"." << "\t" << list[i]<<endl;
    }
}
