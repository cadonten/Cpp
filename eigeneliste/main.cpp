#include <iostream>

using namespace std;

class lElement{

public:
    lElement* next;
    lElement* prev;
    int value;

    lElement( int Ivalue, lElement* Iprev =0 , lElement* Inext = 0){

        next = Inext;
        prev = Iprev;
        value = Ivalue;
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

     void sort (){

         lElement* run = root;

         while (run -> next){

            if (run -> value  <= run -> next -> value){
                run = run -> next;

            }

            else {

                int a = run-> value;
                run -> value = run->next->value;
                run -> next -> value = a;
                run = root;
            }

         }
     }

    void printMe(){

        lElement* run = root;

        while (run){
            cout << run->value<<endl;
            run = run->next;
        }
        cout <<endl;
    }

    void printInvert(){

        lElement* run = root;

        while (run->next){
            run = run->next;
        }

        while (run->prev){
            cout<<run->value<<endl;
            run = run->prev;

        }
        cout <<root->value<<endl;
     }
};


int main(int argc, char *argv[])
{
    List liste;

    for (int i = 0; i < 10; i++){
        int randNumb = rand() % 9 + 1;
        liste.addL(randNumb);
    }

    liste.printMe();
    liste.sort();
    liste.printMe();
    liste.printInvert();
    return 0;
}
