#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bcell.h"
#include "Pass.h"
#define BBLACK   "\033[1;30m"
#define BRED     "\033[1;31m"
#define BGREEN   "\033[1;32m"
#define BYELLOW  "\033[1;33m"
#define BBLUE    "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"
#define RES     "\033[0m"
#define pr printf
#define CELL_SIZE 5000000
#define mCELL_SIZE 10000000
/*#define NULL ((void*)0)*/
/*Три ячейки и каждые по 5.000.000 символов*/
/*они в виртуальной памяти.*/
char inp1[CELL_SIZE];char inp2[CELL_SIZE];
char inp3[CELL_SIZE];
// Для команд
char ex[250];

// (Bcell)
char book1[100];char author1[60];char year1[30];
char Binp1[10000000];char book2[100];
char author2[60];char year2[30];char Binp2[10000000];

// (Pass)
char site1[100];char login1[60];char password1[60];

char site2[100];char login2[60];char password2[60];

char book1[100], author1[60], year1[30];
char book2[100], author2[60], year2[30];
char Binp1[10000000], Binp2[10000000];
/*--------------------*/
/*А здесь уже malloc память*/
char site1[100], login1[60], password1[60];
char site2[100], login2[60], password2[60];
char *Minp1; char *Minp2; char *Minp3;
char ex[250];
void logo () {
    printf("__     __ \n");
    printf("\\ \\   / / \n");
    printf(" \\ \\_/ /  \n");
    printf("  \\___/  \n\n");
    pr(BGREEN);printf("CellVault\n");pr(RES);
    pr(BRED);pr("_______________\n\n");pr(RES);
    pr(BCYAN);printf("\nStatic/Dynamic hybrid cell storage\n\n");pr(RES);
}

char input[6000001];
void IDE() {
    int ch;
    int ch_inp;
    printf("1 - Писать код\n");
    printf("2 - Компелировать\n");
    printf("3 - Выход\n");
    while(1) {
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Пишите:\n");
                scanf("%6000000s",input);
                printf("Код сохранен\n");
                break;
            case 2:
                printf("10 - Компелировать и запускать\n");
                printf("20 - Выход\n\n");
                while (1) {
                    scanf("%d",&ch_inp);
                    if (ch_inp == 10) {
                       FILE *f = fopen("main.c","w");
                       if (f == NULL) {
                           printf("Ошибка создание файла\n");
                           break;
                       }
                       fprintf(f, "%s", input);
                       fclose(f);
                       printf("Файл создан\n");
                       system("gcc main.c -o main 2>&1");
                       system("./main");
                    }
                    if (ch_inp == 20) { break; }
                }
                break;
            case 3: return;
        }
    }
}
void input_ () {
    int ch_i, ch_view, cls, inp_num, cls_all;
    char term[250], ch_w[250], ex2[250], i_save[250], Fch[250];
    char *cname[6]={"Vcell1","Vcell2","Vcell3","Mcell1","Mcell2","Mcell3"};
    FILE *f;
    char filename[100];
    while (1) {
        scanf("%d", &inp_num);
        switch (inp_num) {
            case 5:
                pass();
                break;
            case 6:
                Bcell_();
                break;
            case 7:
                IDE();
                break;
            case 1:
                printf("\n%s - Смотреть ячейку один\n",cname[0]);printf("%s - Смотреть ячейку два\n",cname[1]);
                printf("%s - Смотреть ячейку три\n",cname[2]);printf("%s - Смотреть malloc ячейку один\n",cname[3]);
                printf("%s - Смотреть malloc ячейку два\n",cname[4]);printf("%s - Смотреть malloc ячейку три\n",cname[5]);
                printf("-------------------------------\n\n");
                scanf("%200s", ch_w);
                if (strcmp(ch_w, "Vcell1") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", inp1);
                    scanf("%200s", ex2);

                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Vcell1.txt", "w");
                        fprintf(f, "%s", inp1);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                if (strcmp(ch_w, "Vcell2") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", inp2);
                    scanf("%200s", ex2);
                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Vcell2.txt", "w");
                        fprintf(f, "%s", inp2);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                if (strcmp(ch_w, "Vcell3") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", inp3);
                    scanf("%200s", ex2);
                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Vcell3.txt", "w");
                        fprintf(f, "%s", inp3);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                if (strcmp(ch_w, "Mcell1") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", Minp1);

                    scanf("%200s", ex2);

                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Mcell1.txt", "w");
                        fprintf(f, "%s", Minp1);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                if (strcmp(ch_w, "Mcell2") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", Minp2);

                    scanf("%200s", ex2);

                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Mcell2.txt", "w");
                        fprintf(f, "%s", Minp2);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                if (strcmp(ch_w, "Mcell3") == 0) {
                    printf("\nЗдесь будет то что вы написали: \n");printf("_______________________________\n\n");
                    printf("%s", Minp3);

                    scanf("%200s", ex2);

                    if (strcmp(ex2, "EX") == 0) {
                        break;
                    }
                    else if (strcmp(ex2, "SAV")==0) {
                        f = fopen("Mcell3.txt", "w");
                        fprintf(f, "%s", Minp3);
                        fclose(f);
                    }
                    else {
                        printf("Неизвестная команда\n");
                    }
                }
                break;
            case 4: return;
            case 2:
                printf("\n1 - Написать в ячейку %s\n",cname[0]);printf("2 - Напистаь в ячейку %s\n",cname[1]);
                printf("3 - Написать в ячейку %s\n",cname[2]);printf("4 - Написать в malloc ячейку %s\n",cname[3]);
                printf("5 - Написать в malloc ячейку %s\n",cname[4]);printf("6 - Написать в malloc ячейку %s\n\n",cname[5]);
                scanf("%d", &ch_i);
                if (ch_i == 1) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", inp1);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[0]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", inp1);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                else if (ch_i == 2) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", inp2);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[1]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", inp2);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                else if (ch_i == 3) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", inp3);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[2]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", inp3);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                else if (ch_i == 4) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", Minp1);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[3]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", Minp1);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                else if (ch_i == 5) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", Minp2);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[4]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", Minp2);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                else if (ch_i == 6) {
                    printf("\nПишите:\n\n");
                    scanf(" %[^\n]", Minp3);
                    scanf("%200s", ex);
                    if (strcmp(ex, "EX_") == 0) {
                        sprintf(filename, "%s.txt", cname[5]);
                        f = fopen(filename, "w");
                        fprintf(f, "%s", Minp3);
                        fclose(f);
                        break;
                    }
                    else {
                        printf("\nНеизвестная команда");
                    }
                }
                break;
            case 3:
                printf("\nTerminal CellVault:\n\n");
                printf("Напишите help\n\n");
                while (1) {
                    scanf("%200s", term);
                    if (strcmp(term, "SAVi") == 0) {
                        printf("\n%s - Сохранить ячейку один\n",cname[0]);
                        printf("%s - Сохранить ячейку два\n",cname[1]);printf("%s - Сохранить ячейку три\n",cname[2]);
                        printf("%s - Сохранить malloc ячейку один\n",cname[3]);printf("%s - Сохранить malloc ячейку два\n",cname[4]);
                        printf("%s - Сохранить malloc ячейку три\n",cname[5]);printf("-------------------------------\n\n");
                        printf("Напишите ячейку: \n");
                        scanf("%200s", i_save);
                        if (strcmp(i_save, cname[0]) == 0) {
                            sprintf(filename, "%s.txt", cname[0]);f = fopen(filename, "w");
                            fprintf(f, "%s", inp1);fclose(f);
                        }
                        else if (strcmp(i_save, cname[1]) == 0) {
                            sprintf(filename, "%s.txt", cname[1]);f = fopen(filename, "w");
                            fprintf(f, "%s", inp2);fclose(f);
                        }
                        else if (strcmp(i_save, cname[2]) == 0) {
                            sprintf(filename, "%s.txt", cname[2]);f = fopen(filename, "w");
                            fprintf(f, "%s", inp3);fclose(f);
                        }
                        else if (strcmp(i_save, cname[3])==0) {
                            sprintf(filename, "%s.txt", cname[3]);f = fopen(filename, "w");
                            fprintf(f, "%s", Minp1);fclose(f);
                        }
                        else if (strcmp(i_save, cname[4])==0) {
                            sprintf(filename, "%s.txt", cname[4]);f = fopen(filename, "w");
                            fprintf(f, "%s", Minp2);fclose(f);
                        }
                        else if (strcmp(i_save, cname[5])==0) {
                            sprintf(filename, "%s.txt", cname[5]);f = fopen(filename, "w");
                            fprintf(f, "%s", Minp3);fclose(f);
                        }
                        else if (strcmp(i_save, "exit")==0) {break;}
                        else {printf("Неизвестная ячейка\n");}
                    }
                    else if (strcmp(term, "bcell")==0) {
                        Bcell_();
                    }
                    else if (strcmp(term, "sav_all") == 0) {
                        printf("\nSAVE - сохранить все ячейки\n");printf("exit - выйти\n\n");scanf("%200s", Fch);
                        if (strcmp(Fch, "SAVE") == 0) {
                            sprintf(filename, "%s.txt", cname[0]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", inp1);
                            fclose(f);
                            printf("Файл создан\n");
                            sprintf(filename, "%s.txt", cname[1]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", inp2);
                            fclose(f);
                            printf("Файл создан\n");
                            sprintf(filename, "%s.txt", cname[2]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", inp3);
                            fclose(f);
                            printf("Файл создан\n");
                            sprintf(filename, "%s.txt", cname[3]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", Minp1);
                            fclose(f);
                            printf("Файл создан\n");
                            sprintf(filename, "%s.txt", cname[4]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", Minp2);
                            fclose(f);
                            printf("Файл создан\n");
                            sprintf(filename, "%s.txt", cname[5]);
                            f = fopen(filename, "w");
                            fprintf(f, "%s", Minp3);
                            fclose(f);
                        }
                        if (strcmp(Fch, "exit") == 0) { break; }
                    }
                    else if (strcmp(term, "clear_all")==0) {
                        printf("\n1 - очистить все ячейки\n2 - выйти\n\n");
                        while (1) {
                            scanf("%d", &cls_all);
                            switch (cls_all) {
                                case 1:
                                    inp1[0] = 0;
                                    inp2[0] = 0;
                                    inp3[0] = 0;
                                    Minp1[0] = 0;
                                    Minp2[0] = 0;
                                    Minp3[0] = 0;
                                    printf("Все ячейки очищены\n");
                                    break;
                                case 2:
                                    break;
                                default:
                                    printf("Неверный выбор\n");
                            }
                            if (cls_all == 2) break;
                        }
                    }
                    else if (strcmp(term, "list")==0) {
                        printf("\n%s (%u символов)\n",cname[0],(unsigned)strlen(inp1)); printf("%s (%u символов)\n",cname[1],(unsigned)strlen(inp2));
                        printf("%s (%u символов)\n",cname[2],(unsigned)strlen(inp3)); printf("%s (%u символов)\n",cname[3],(unsigned)strlen(Minp1));
                        printf("%s (%u символов)\n",cname[4],(unsigned)strlen(Minp2)); printf("%s (%u символов)\n\n",cname[5],(unsigned)strlen(Minp3));
                    }
                    else if (strcmp(term, "view_all")==0) {
                        printf("%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s",inp1,inp2,inp3,Minp1,Minp2,Minp3);
                    }
                    else if (strcmp(term, "exit") == 0) { break; }
                    else if (strcmp(term, "help") == 0) {
                        printf("\nhelp\nSAVi\nlist\nview\nclear\nexit\nsav_all\n\n");
                    }
                    else if (strcmp(term, "view") == 0) {
                        while (1) {
                            scanf("%d", &ch_view);
                            switch (ch_view) {
                                case 1:
                                   printf("----------------\n");
                                   printf("%s\n", inp1);
                                   printf("----------------\n");break;
                                case 2:
                                   printf("----------------\n");
                                   printf("%s\n", inp2);
                                   printf("----------------\n");break;
                                case 3:
                                   printf("----------------\n");
                                   printf("%s\n", inp3);
                                   printf("----------------\n");break;
                                case 4:
                                   printf("----------------\n");
                                   printf("%s\n", Minp1);
                                   printf("----------------\n");break;
                                case 5:
                                   printf("----------------\n");
                                   printf("%s\n", Minp2);
                                   printf("----------------\n");break;
                                case 6:
                                   printf("----------------\n");
                                   printf("%s\n", Minp3);
                                   printf("----------------\n");break;
                                case 7:
                                   break;
                                default:
                                   printf("Нет такой ячейки\n");
                            }
                            if (ch_view == 7) break;
                        }
                    }
                    else if (strcmp(term, "clear")==0) {
                        printf("\nОчистка ячейки:\n");
                        printf("\n1- %s\n",cname[0]);
                        printf("2 - %s\n",cname[1]);
                        printf("3 - %s\n",cname[2]);
                        printf("4 - %s\n",cname[3]);
                        printf("5 - %s\n",cname[4]);
                        printf("6 - %s\n",cname[5]);
                        printf("7 - Выход\n");
                        printf("------------------\n\n");
                        scanf("%d", &cls);
                        switch (cls) {
                            case 1: inp1[0] = 0;break;
                            case 2: inp2[0] = 0;break;
                            case 3: inp3[0] = 0;break;
                            case 4: Minp1[0] = 0;break;
                            case 5: Minp2[0] = 0;break;
                            case 6: Minp3[0] = 0;break;
                            case 7:break;
                            default:
                                printf("Неизвестная ячейка\n");
                                break;
                        }
                    }
                }
                break;
        }
    }
}
int main () {
    logo ();
    Minp1 = malloc(mCELL_SIZE);
    if (Minp1==NULL){printf("Ошибка\n"); exit(1);}
    Minp2 = malloc(mCELL_SIZE);
    if (Minp2==NULL){printf("Ошибка\n");free(Minp1);
        Minp1=NULL;exit(1);
    }
    Minp3 = malloc(mCELL_SIZE);
    if (Minp3==NULL){printf("Ошибка\n");free(Minp1);free(Minp2);
        Minp1=NULL;Minp2=NULL;exit(1);
    }
    printf("1 - Смотреть\n");
    printf("2 - Писать текст\n");
    printf("3 - Терминал\n");
    printf("4 - Выйти\n");
    printf("5 - pass\n");
    printf("6 - Bcell\n");
    printf("7 - IDE\n");
    input_();
    free(Minp1);free(Minp2);free(Minp3);
}
