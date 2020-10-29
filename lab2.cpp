#include <stdio.h>
#include <stdlib.h>

typedef struct person* Pozicija;
struct person{
    char *name,*surname;
    int year;
    Pozicija next;
};

void Print(Pozicija P); //pass Head->next
void AddBegin(Pozicija P, char* n, char *s, int y); //pass Head
void AddEnd(Pozicija P, char* n, char *s, int y); //pass Head
Pozicija FindSurname(Pozicija P, char *s); //pass Head->next
void DeletePerson(Pozicija P, char *s); //pass Head
void DeletePerson(Pozicija P, Pozicija A); //pass Head
void AddAfter(Pozicija P, Pozicija A); //pass head
void AddBefore(Pozicija P, Pozicija A); //pass head->next

int main(){

Pozicija Head = (Pozicija)malloc(sizeof(person));
Head->next = NULL;

Print(Head->next);
AddBegin(Head,(char*)"aldo",(char*) "bujevic", 1997);
Print(Head->next);
AddBegin(Head,(char*)"mimi",(char*) "lija", 2000);
AddBegin(Head,(char*)"lala", (char*)"teletabi", 2004);
AddBegin(Head,(char*)"roko", (char*)"lija", 2012);

AddEnd(Head,(char*)"jure", (char*)"zvoncic", 2015);
Print(Head->next);
Pozicija P = FindSurname(Head->next,(char*)"lija");
if(P!=NULL) printf("---%s\t%s\t%d---\n",P->name,P->surname,P->year);

DeletePerson(Head,(char*)"lija");

Print(Head->next);

return 0;
}

void Print(Pozicija P){
        while(P != NULL){
            printf("%s\t%s\t%d\n",P->name,P->surname,P->year);
            P = P->next;
        }
    printf("_________________________________________\n");
    return;
}
void AddBegin(Pozicija P, char* n, char *s, int y){
    Pozicija temp = (Pozicija)malloc(sizeof(person));
    temp->name = (char*)malloc(255*sizeof(char));
    temp->surname = (char*)malloc(255*sizeof(char));
    temp->name = n;
    temp->surname = s;
    temp->year = y;
    temp->next = P->next;
    P->next = temp;
    return;
}
void AddEnd(Pozicija P, char* n, char *s, int y){
    while(P->next != NULL)
        P=P->next;
    AddBegin(P, n, s, y);
    return;
}
Pozicija FindSurname(Pozicija P, char *s){
    if(P!=NULL){
        while(P->next != NULL){
            //printf("Comparing %s with %s\n",P->surname,s);
            if(P->surname == s){
                //printf("Comparing %s with %s\n",P->surname,s);
                return P;
                }
            P=P->next;
        }
    }
    //printf("NO MATCHES\n");
    return NULL;
}
void DeletePerson(Pozicija P, char* s){
    Pozicija temp = P;
    P = P->next;
    if(P!=NULL){
        while(P->next != NULL){
            if(P->surname == s){
                temp->next = P->next;
                free(P);
                P=temp;
                //break; //ako zelimo da brise samo prvu osobu u listi s tim prezimenom
                }
            temp = P;
            P = P->next;
        }
    }
    return;
}

void DeletePerson(Pozicija P, Pozicija A){
    Pozicija temp = P;
    P = P->next;
    if(P!=NULL){
        while(P->next != NULL){
            if(P == A){
                temp->next = P->next;
                free(P);
                P=temp;
                //break; //ako zelimo da brise samo prvu osobu u listi s tim prezimenom
                }
            temp = P;
            P = P->next;
        }
    }
    return;
}

