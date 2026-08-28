#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pass.h"

void pass () {
    int cmdp,chp,wch, pclear;
    int save_p;
    FILE *F;
    printf("1 - Добавить пароль\n");
    printf("2 - Показать пароль\n");
    printf("3 - Посмотреть все\n");
    printf("4 - Выход\n");
    printf("5 - Очистить\n");
    printf("6 - Очистить все\n");
    printf("7 - Сохранить\n");
    printf("8 - Сохранить все\n");
    /*printf("3 - Список паролей\n");*/
    while (1) {
        scanf("%d", &cmdp);
        switch (cmdp) {
            case 1:
                while (1) {
                    printf("\n1 - Пространство номер один\n");
                    printf("2 - Пространство номер два\n");
                    printf("4 - Выход\n\n");
                    scanf("%d", &chp);
                    switch (chp) {
                        case 1:
                            printf("Сайт: "); scanf("%99s", site1);
                            printf("Логин: "); scanf("%58s", login1);
                            printf("Пароль: "); scanf("%58s", password1);
                            break;
                        case 2: printf("Сайт: "); scanf("%99s", site2);
                            printf("Логин: "); scanf("%58s", login2);
                            printf("Пароль: "); scanf("%58s", password2);
                            break;
                        case 4:
                            break;
                    }
                    if (chp == 4) break;
                }
                break;
            case 2:
                printf("\n1 - Смотреть пространство один\n");
                printf("\n2 - Смотреть пространство два\n");
                printf("\n3 - Выход\n");
                while (1) {
                    scanf("%d", &wch);

                    if (wch == 1) {
                        printf("Сайт: %s\n",site1);printf("Логин: %s\n",login1);
                        printf("Пароль: %s\n",password1);break;
                    }
                    else if (wch == 3) { break; }
                    else if (wch == 2) {
                        printf("Сайт: %s\n",site2);printf("Логин: %s\n",login2);
                        printf("Пароль: %s\n",password2);break;
                    }else{printf("Такого пространства нет\n");}
                }
                break;
            case 3:
                printf("Сайт: %s\n",site1);printf("Логин: %s\n",login1);
                printf("Пароль: %s\n",password1);
                printf("Сайт: %s\n",site2);printf("Логин: %s\n",login2);
                printf("Пароль: %s\n",password2);
                break;
            case 4: break;
            case 6:
                site1[0] = 0;login1[0] = 0;
                password1[0] = 0;site2[0] = 0;
                login2[0] = 0;password2[0] = 0;
                break;
            case 7:
                while (1) {
                    scanf("%d", &save_p);
                    switch (save_p) {
                        case 1:
                            F = fopen("CellPass1.txt", "w");
                            fprintf(F, "%s\n%s\n%s\n",site1,login1,password1);
                            fclose(F);break;
                        case 2:
                            F = fopen("CellPass2.txt", "w");
                            fprintf(F, "%s\n%s\n%s\n",site2,login2,password2);
                            fclose(F);break;
                        case 3: break;
                        default: printf("Неизвестная команда, напишите 3 для выхода\n");
                    }
                    if (save_p == 3) break;
                }
                break;
                case 8:
                    F = fopen("CellPass1.txt", "w");
                    fprintf(F, "%s\n%s\n%s\n",site1,login1,password1);fclose(F);
                    F = fopen("CellPass2.txt", "w");
                    fprintf(F, "%s\n%s\n%s\n",site2,login2,password2);fclose(F);
                    break;
                case 5:
                printf("\n1 - Очистить пространство один\n");
                printf("2 - Очистить пространство два\n\n");
                while (1) {
                    scanf("%d", &pclear);

                    if (pclear == 1) {
                        site1[0] = 0;
                        login1[0] = 0;
                        password1[0] = 0;break;
                    }
                    else if (pclear == 2) {
                        site2[0] = 0;
                        login2[0] = 0;
                        password2[0] = 0;break;
                    }
                    else if (pclear == 3) { break;
                    } else {
                        printf("Такого пространства нет \n");
                        printf("Чтобы выйти напишите 3\n");
                    }
                }
                break;
        }
    }
}
