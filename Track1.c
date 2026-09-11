#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(){
        printf("\n\t\tOptions\n");
        printf("1.Enter & store Data\n");
        printf("2.App Activity\n");
        printf("3.Exit\n");
}
union app{
        char a[100];
        int t;
};
int main(){
    int n;
    union app app;
    FILE *fptr;
        fptr=fopen("Track.txt","w");
        fprintf(fptr,"App\t\tTime\n");
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
                char app[10]={"Instagram","Whatsapp"};
                char prod[100]="";
                int j=0;
                char unprod[100]="";
                    FILE *fptr;
                    fptr=fopen("Track.txt","r");
                    fscanf(fptr,"%*[^\n]\n");
                    while(fscanf(fptr,"%s\t\t%d",app.a,&app.t)!=EOF){
                            for(int i=0;i<2;i++){
                                if(strcmp(app.a,app[i])==0){
                                        strcat(prod[j],app.a);
                                        j++;
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