#include <stdio.h>

int gui(int x_ball, int y_ball, int y_right, int y_left){//отрисовка
    for (int i=0; i < 101*21+1; i++){ 
        if (i == 0){
            printf("|");
        }
        else if (i == 101*21){// последний символ поля
            printf("|\n");
        }
        else if (i%101 == 0){//боковые границы
            printf("|\n|");
        }
        else if ((i>0 && i<101) || (i > 101*20 )){//верхняя и нижняя границы
            printf("-");
        }
        else if ((i % 101 == 1) && (101 * y_right - 100 == i || 101 * (y_right + 1) - 100 == i || 101 * (y_right + 2) - 100 == i))//правая ракетка
        {
            printf("|");
        }
        else if ((i % 101 == 100) && (101 * y_right - 1 == i || 101 * (y_right+1) - 1 == i || 101 * (y_right+2) - 1 == i))//левая ракетка
        {
            printf("|");
        }
        else if (101*(y_ball-1)+x_ball == i){
            printf("*");
        }
        else{// заполняем поле пробелами
            printf(" ");
        }
        }
}


int main(){
    gui(51,11,10,10);
}