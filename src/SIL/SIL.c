#include "in.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char s[90];
int values[26];
char arg1[20], arg2[20], arg3[20], arg4[20];
char arg5[20];
char strings[26][100];
char cval[26];
float fval[26];
const char *word[] = {
    "mov","add",
    "sub","int_print",
    "print_c","add_num",
    "subt_num","clear",
    "mul_num","div_num",
    "str","print_str",
    "fmov","printfl",
    "movC","printc",
    "fadd","strlen",
    "input_int","input_str",
    "dec","inc","copy",
    "savev","loadv",
    "inputf","inputc"
};
void mov(){
    int idx = arg2[0] - 'a';
    values[idx] = atoi(arg3);
}
void add(){
    int idx = arg2[0] - 'a';
    values[idx] = values[idx] + atoi(arg3);
}
void INT_print(){
    int idx = arg2[0] - 'a';
    printf("%d\n",values[idx]);
}
void sub(){
    int idx = arg2[0] - 'a';
    values[idx] = values[idx] - atoi(arg3);
}
void add_num() {
    int result = atoi(arg2) + atoi(arg3);
    printf("%d\n", result);
}
void subt_num(){
    int result = atoi(arg2) - atoi(arg3);
    printf("%d\n", result);
}
void clear() {
    int idx = arg2[0] - 'a';
    values[idx] = 0;
}
void mul_num() {
    int result = atoi(arg2) * atoi(arg3);
    printf("%d\n", result);
}
void div_num() {
    int result = atoi(arg2) / atoi(arg3);
    printf("%d\n", result);
}
void raz() {
    sscanf(s, "%19s %19s %19s %19s %19s", arg1,arg2,arg3,arg4,arg5);
    if(strcmp(arg1,word[0])==0){//mov
        mov();
    }else if(strcmp(arg1,word[1])==0){//add
        add();
    }else if(strcmp(arg1,word[2])==0){//sub
        sub();
    }else if(strcmp(arg1,word[3])==0){//int_print
        INT_print();
    }else if(strcmp(arg1,word[4])==0){//print_c
    printf("%s\n",s+7);
    }else if(strcmp(arg1,word[5]) == 0) {//add_num
        add_num();
    }else if(strcmp(arg1,word[6]) == 0) {//subt_num
        subt_num();
    }else if(strcmp(arg1, word[7]) == 0) {//clear
        clear();
    }else if(strcmp(arg1,word[8]) == 0) {//mul_num
        mul_num();
    }else if(strcmp(arg1,word[9]) == 0) {//div_num
        div_num();
    }else if(strcmp(arg1,word[10]) == 0) {
    int idx = arg2[0] - 'a';
    strcpy(strings[idx], arg3);
    }else if(strcmp(arg1,word[11]) == 0) {
    int idx = arg2[0] - 'a';
    printf("%s\n", strings[idx]);
    }else if(strcmp(arg1,word[12]) == 0) {
    int idx = arg2[0] - 'a';
    fval[idx] = atof(arg3);
    }else if(strcmp(arg1,word[13]) == 0) {
    int idx = arg2[0] - 'a';
    printf("%f\n",fval[idx]);
    }else if(strcmp(arg1,word[16]) == 0) {
    int idx = arg2[0] - 'a';
    fval[idx] = fval[idx] + atof(arg3);
    }else if(strcmp(arg1,word[14]) == 0) {
    int idx = arg2[0] - 'a';
    cval[idx] = arg3[0];
    }else if(strcmp(arg1,word[15]) == 0) {
    int idx = arg2[0] - 'a';
    printf("%c\n",cval[idx]);
    }else if(strcmp(arg1,word[17]) == 0) {
    int idx = arg2[0] - 'a';
    printf("%zu\n",strlen(strings[idx]));
    }else if(strcmp(arg1,word[18]) == 0) {
    int idx = arg2[0] - 'a';
    scanf(" %d", &values[idx]);                  
    }else if(strcmp(arg1,word[19]) == 0) {
    int idx = arg2[0] - 'a';
    scanf(" %s", strings[idx]);                    
    }else if(strcmp(arg1,word[20]) == 0) {
    int idx = arg2[0] - 'a';
    values[idx] = values[idx] - 1;
    }else if(strcmp(arg1,word[21]) == 0) {
    int idx = arg2[0] - 'a';
    values[idx] = values[idx] + 1;
    }else if(strcmp(arg1,word[22]) == 0) {
    int idx1 = arg2[0] - 'a';
    int idx2 = arg3[0] - 'a';
    values[idx2] = values[idx1];
    }else if(strcmp(arg1,word[23]) == 0) {
    int idx = arg2[0] - 'a';
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "%d", values[idx]);
    fclose(f);
    }else if(strcmp(arg1,word[24]) == 0) {
    int idx = arg2[0] - 'a';           
    FILE *f = fopen("data.txt", "r");  
    if (f) {                            
        fscanf(f, "%d", &values[idx]); 
        fclose(f);                      
        }
    }else if(strcmp(arg1,word[25]) == 0) {
    int idx = arg2[0] - 'a';
    scanf(" %f", &fval[idx]);
    }else if(strcmp(arg1,word[26]) == 0) {
    int idx = arg2[0] - 'a';
    scanf(" %c", &cval[idx]);   
    }else if(strcmp(arg1, "cmp") == 0) {
    int idx1 = arg2[0] - 'a';
    int idx2 = arg3[0] - 'a';
    if (values[idx1] == values[idx2]) printf("0\n");
    else if (values[idx1] > values[idx2]) printf("1\n");
    else printf("-1\n");
    }else if(strcmp(arg1, "dump") == 0) {
        for (int i = 0; i < 26; i++) {
        if (values[i] != 0) printf("%c = %d\n", 'a' + i, values[i]);
        }
    }else if(strcmp(arg1, "*[") == 0) {;}
}    
void inter() {
    int ch;
    puts("Напишите цифру 3 и увидите информацию");
    puts("о использования приложения.");
    puts("\n1 - REPL interpretator");
    puts("2 - to run");
    puts("3 - help\n");
    while (1) {
        scanf(" %d",&ch);
        switch (ch) {
            case 1:
                puts("———————————————————");
                puts("\nSIL interpretator");
                while (1) {
                    printf("> ");
                    fgets(s, sizeof(s), stdin);
                    s[strcspn(s, "\n")] = 0;
                    if (strcmp(s, "exit") == 0) break;
                    raz();
                }
                break;
            case 2:
                int fi;
                puts("Файл должен называтся programm.siv\n");
                scanf(" %d",&fi);
                if(fi==1){
    			    FILE *f = fopen("programm.siv","r");
                    if(!f){
                    puts("Файл пустой или не найден");
                    puts("Нужен файл с названием programm.siv");
                    break;
                    }
    			    while (fgets(s, sizeof(s), f)) { 
        		    s[strcspn(s, "\n")] = 0;
        		    raz();
                    }
                    fclose(f);
                    break;
                }
                break;
            case 3:
                printf("\nЕсли выбираете два, то нужен файл с нужным\n");
                printf("кодом и с названием programm.siv\n\n");
                break;
            default:puts("Неизвестная команда");   
        }    
    }    
    return;
}
