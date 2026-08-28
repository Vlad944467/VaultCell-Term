#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Bcell.h"


void Bcell_() {
    int ch_ch, CH_B, CH_B2;
    FILE *F;
    printf("1 - Писать в ячейку Tcell 1\n");
    printf("2 - Писать в ячейку Tcell 2\n");
    printf("3 - Выход\n");
    printf("4 - Сохранить все Tcell\n");
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
        else { printf("Неизвестная команда, напишите 3 чтоб выйти\n");}
    }
}
