#include <iostream>

using namespace std;

class lElement{

public:
    lElement* next;
    lElement* nextnext;
    lElement* prev;
    lElement* prevprev;
    int value;

    lElement( int Ivalue, lElement* Iprev =0 , lElement* Inext = 0, lElement* Iprevprev = 0, lElement* Inextnext = 0){

        next = Inext;
        prev = Iprev;
        value = Ivalue;
        nextnext = Inextnext;
        prevprev = Iprevprev;
    }
    ~lElement(){

        if (prev)
            prev -> next = next;
        if (next)
            next -> prev = prev;

    }

};

class List {

public:
    lElement* root;
        List () {
            root = 0;
        }
         ~List(){

            lElement* run = root;

            while (run){

                lElement* nxt = run->next;
                delete run;
                run = nxt;
            }
         }
     void addL ( int val ){

         if (!root){
             root = new lElement(val);
             return;
         }
         lElement* run = root;

         while (run -> next){

             run = run -> next;
         }
         run -> next = new lElement(val, run);
     }

    lElement* findPos (int pos){

        lElement* run = root;
        int count = 0;
        while(count < pos ){
            run = run->next;
            count++;
        }
        return run;
    }

    void addZw (lElement* zweig, int zValue){

        for ( int i = 0; i < 8; i++){

            zweig -> nextnext = new lElement(zValue, zweig, zweig->next, zweig);
            zweig = zweig->nextnext;
            zValue = rand() % 9 + 1;
        }

    }

    void printMe(){

        lElement* run = root;

        while (run){
            cout << run->value;

            if (run->nextnext){

                lElement* runZw = run;
                while (runZw->nextnext){
                    cout<<"  "<<runZw->nextnext->value;
                    runZw = runZw->nextnext;
                }
            }
            cout <<endl;
            run = run->next;
        }
        cout <<endl;
    }

};


int main(int argc, char *argv[])
{
    List liste;

    for (int i = 0; i < 10; i++){
        int randNumb = rand() % 9 + 1;
        liste.addL(randNumb);
    }

    liste.addZw(liste.findPos(5), rand() % 9 + 1);
    liste.printMe();
    return 0;
}
