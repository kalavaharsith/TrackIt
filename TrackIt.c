#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(){
        printf("\n\t\tOptions\n");
        printf("1.Enter & store Data\n");
        printf("2.App Activity\n");
        printf("3.Exit\n");
}
struct app{
        char a[100];
        int t;
};
int main(){
    int n;
    struct app app;
    FILE *fptr;
        fptr=fopen("Track.txt","w");
        fprintf(fptr,"App\t\t\tTime\n");
        fclose(fptr);
    do{
        //Menu
        menu();
        
        //Selection of Option
        printf("Enter Option(1-3):");
        scanf("%d",&n);
        getchar();

        
        //Switch Case

        switch(n){
            case 1:{

                printf("Enter App name:");
                fgets(app.a,sizeof(app.a),stdin);
                app.a[strcspn(app.a,"\n")]='\0';
                printf("Enter Time spent:");
                scanf("%d",&app.t);

                FILE *fptr;
                fptr=fopen("Track.txt","a");
                fprintf(fptr,"%s\t\t%d\n",app.a,app.t);
                fclose(fptr);
                break;
            }
            case 2:{
                char prod[100]="";
                char unprod[100]="";
                    FILE *fptr;
                    fptr=fopen("Track.txt","r");
                    fscanf(fptr,"%*[^\n]\n");
                    while(fscanf(fptr,"%[^\t]\t\t%d",app.a,&app.t)!=EOF){
                        if(app.t<=3){
                        strcat(prod,app.a);
                        strcat(prod,"\n");
                       }
                    else{
                        strcat(unprod,app.a);
                        strcat(unprod,"\n");
                    }    
                    }
                    fclose(fptr);

                    printf("Productive apps are:\n");
                    puts(prod);
                    printf("Unproductive apps are:\n");
                    puts(unprod);
                    
                    break;
                }
            case 3:{
                    printf("Thank you!!");
                    exit(0);
            }
    
            default:{
                    printf("Enter valid Option");
                    break;
                }
        }
    
    }while(n!=3);
    return 0;
}