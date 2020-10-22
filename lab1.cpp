
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char *ime,*prezime;
	int bodovi;
}Student;

int main()
{
	FILE *fp;
	char buff;
	int red=1,i;
	fp = fopen("text.txt","r");
	while(!feof(fp)){
	  buff = fgetc(fp);
	  if(buff == '\n')
		red++;
	}
	printf("%d\n",red);
	rewind(fp);

	//red-=1; //potrebno ako .txt file automatski doda \n na kraj dokumenta

	Student *studenti = NULL;
	studenti = (Student*)malloc(sizeof(Student)*red);

	for(i=0;i<red;i++){
		printf("%d\n",i);
		studenti[i].ime = (char*)malloc(255*sizeof(char));
        studenti[i].prezime = (char*)malloc(255*sizeof(char));
        fscanf(fp, "%s %s %d",studenti[i].ime,studenti[i].prezime, &studenti[i].bodovi);
		}
	fclose(fp);

	for(i=0;i<red;i++){
        printf("%d\t",i+1);
		printf("IME PREZIME: %s %s\tBODOVI: %d\tRELATIVNI BODOVI: %d\n", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, (float)studenti[i].bodovi/10.0*100);
	}


	return 0;
}

