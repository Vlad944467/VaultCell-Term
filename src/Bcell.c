#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Bcell.h"

char *NLcell[3]={"Lcell1","Lcell2","Lcell3"};
char Lcell1[1000],Lcell2[1000],Lcell3[1000];
void number () {
    int numb;
    char N_ch[10];
    char c_h[10];
    char s_ch[21];
    FILE *F;
    printf("1 - Написать номер\n");
    printf("2 - Выйти\n");
    printf("3 - Смотреть\n\n");
    while (1) {
        scanf("%d", &numb);
        switch(numb) {
            case 1:
                printf("\n%s - номер ячейка 1\n",NLcell[0]);
                printf("%s - номер ячейка 2\n",NLcell[1]);
                printf("%s - номер ячейка 3\n\n",NLcell[2]);
                while (1) {
                    scanf("%9s", N_ch);
                    if(strcmp(N_ch,NLcell[0])==0){
                    scanf("%999s",Lcell1);
                    }else if(strcmp(N_ch,NLcell[1])==0){
                    scanf("%999s",Lcell2);
                    }else if(strcmp(N_ch,NLcell[2])==0){
                    scanf("%999s",Lcell3);
                    }else if(strcmp(N_ch, "ex")==0){ break;
                    }else{ printf("Неизвестная команда, чтоб выйти напишите ex\n");}
                }
                break;
            case 2: return;
            case 4:
                printf("%s - Сохранить номер ячейку 1\n", NLcell[0]);
                printf("%s - Сохранить номер ячейку 2\n", NLcell[1]);
                printf("%s - Сохранить номер ячейку 3\n", NLcell[2]);
                printf("exit - Выйти\n\n");

                while (1) {
                    scanf("%20s", s_ch);
                    if(strcmp(s_ch,NLcell[0])==0){
                        F = fopen("Lcell1.txt", "w");
                        fprintf(F, "%s", Lcell1);fclose(F);
                        printf("Файл Lcell1.txt создан\n");return;
                    }
                    else if (strcmp(s_ch, NLcell[1]) == 0) {
                        F = fopen("Lcell2.txt", "w");fprintf(F, "%s", Lcell2);fclose(F);
                        printf("✅ Файл Lcell2.txt создан\n");return;
                    }
                    else if (strcmp(s_ch, NLcell[2]) == 0) {
                        F = fopen("Lcell3.txt", "w");fprintf(F, "%s", Lcell3);fclose(F);
                        printf("✅ Файл Lcell3.txt создан\n");return;
                    }
                    else if (strcmp(s_ch, "exit") == 0) {return;}
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                break;
            case 3:
                printf("%s - Смотреть ячейку 1\n",NLcell[0]);
                printf("%s - Смотреть ячейку 2\n",NLcell[1]);
                printf("%s - Смотреть ячейку 3\n\n",NLcell[2]);
                while (1) {
                    scanf("%9s",c_h);
                    if(strcmp(c_h,NLcell[0])==0){
                    printf("%s",Lcell1);break;
                    }
                    if(strcmp(c_h,NLcell[1])==0){
                    printf("%s",Lcell2);break;
                    }
                    if(strcmp(c_h,NLcell[2])==0){
                    printf("%s",Lcell3);break;
                    }
                    if(strcmp(c_h,"ex")==0){return;}
                    else{printf("Неизвестная команда\n");}
                }
                break;
        }
    }
}

void Bcell_() {
    int ch_ch, CH_B, CH_B2;
    FILE *F;
    printf("1 - Писать в ячейку Tcell 1\n");
    printf("2 - Писать в ячейку Tcell 2\n");
    printf("3 - Выход\n");
    printf("4 - Сохранить все Tcell\n");
    printf("5 - Сохранить\n");
    printf("6 - Clear\n");
    printf("7 - Clear all\n");
    while (1) {
        scanf("%d", &ch_ch);
        if (ch_ch == 1) {
            printf("Название: ");scanf("%98s",book1);printf("Год: ");scanf("%28s",year1);
            printf("Содержимое:\n\n");scanf(" %[^\n]",Binp1);
        }
        else if (ch_ch == 2) {
            printf("Название: ");scanf("%98s",book2);printf("Год: ");scanf("%28s",year2);
            printf("Содержимое:\n\n");scanf(" %[^\n]",Binp2);
        }
        else if (ch_ch == 3) { break; }
        else if (ch_ch == 4) {
            F = fopen("Tcell1.txt", "w");
            fprintf(F, "%s\n%s\n%s\n\n",book1,year1,Binp1);fclose(F);
            F = fopen("Tcell2.txt", "w");
            fprintf(F, "%s\n%s\n%s\n\n",book2,year2,Binp2);fclose(F);
        }
        else if (ch_ch == 5) {
            printf("\n1 - Сохранить Tcell 1\n2 - Сохранить Tcell 2\n3 - Выйти\n");
            while (1) {
                scanf("%d", &CH_B);
                if (CH_B == 1) {
                    F = fopen("Tcell1.txt", "w");fprintf(F, "%s\n%s\n%s\n\n",book1,year1,Binp1);fclose(F);
                }
                if (CH_B == 2) {
                    F = fopen("Tcell2.txt", "w");fprintf(F, "%s\n%s\n%s\n\n",book2,year2,Binp2);fclose(F);
                }
                if (CH_B == 3) { break; }
                else { printf("Неизвестная команда, напишите 3 чтоб выйти\n");}
            }
        }
        else if (ch_ch == 6) {
            printf("1 - Очистить Tcell 1\n2 - Очистить Tcell 2\n\n");
            scanf("%d", &CH_B2);
            if (CH_B2 == 1) {
                book1[0] = 0;year1[0] = 0;
                Binp1[0] = 0;break;
            }
            if (CH_B2 == 2) {
                book2[0] = 0;year2[0] = 0;
                Binp2[0] = 0;break;
            }
            else { printf("Вы вернулись назад\n"); break;}
        }
        else if (ch_ch == 7) {
            book1[0] = 0;year1[0] = 0;
            Binp1[0] = 0;break;
            book2[0] = 0;year2[0] = 0;
            Binp2[0] = 0;break;
        }
        else { printf("Неизвестная команда, напишите 3 чтоб выйти\n");}
    }
}
