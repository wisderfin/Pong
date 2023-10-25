#include <stdio.h>
#include <stdlib.h>

int gui(int x_ball, int y_ball, int y_right, int y_left, int score_right, int score_left){//отрисовка
    for (int i=0; i < 101*21+1; i++){ 
        if (i == 0){
            printf("|");
        }
        else if (i == 101*21){// последний символ поля
            printf("| score:%d - %d\n", score_left, score_right);
        }
        else if (i%101 == 0){//боковые границы
            printf("|\n|");
        }
        else if ((i>0 && i<101) || (i > 101*20 )){//верхняя и нижняя границы
            printf("-");
        }
        else if ((i % 101 == 1) && (101 * y_left - 100 == i || 101 * (y_left + 1) - 100 == i || 101 * (y_left + 2) - 100 == i))//правая ракетка
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

int control_rocket(){// обработка клавиш
    char key;
    int result;
    scanf("%c", &key);
    if (key == 'a'){
        result = 1;
    }
    else if (key == 'z'){
        result = 2;
    }
    else if (key == 'k'){
        result = 3;
    }
    else if (key == 'm'){
        result = 4;
    }
    else{
        result = 0;
    }
    return result;//возвращаем код движения ракетки
    

    
}

int control_ball(int y_left, int y_right, int x_ball, int y_ball, int modul_x, int modul_y){
    int result;
    for (int i = 0; i < 4; i++){
        if (y_left == y_ball + i){
            result = -1;
        }}
    if (modul_x == -1 && modul_y == -1){
        result = 0;
    }
    else if (modul_x == -1 && modul_y == 1){
        result = 1;
    }
    else if (modul_x == 1 && modul_y == -1){
        result = 2;
    }
    else if (modul_x == 1 && modul_y == 1){
        result = 3;
    }
    return result;
}

int main(){
    int x_ball = 51;
    int y_ball = 11;
    int y_left = 10;
    int y_right = 10;
    int modul_x = 1;
    int modul_y = 1;
    int score_right = 0;
    int score_left = 0;
    gui(x_ball, y_ball, y_right, y_left, score_right, score_left);
    while (1){
        int key = control_rocket();
        if (key == 1 && y_left > 2){//левая ракетка вверх
            y_left--;
        }
        else if (key == 2 && y_left < 18){//левая ракетка вниз
            y_left++;
        }
        else if (key == 3 && y_right > 2){//правая ракетка вверх
            y_right--;
        }
        else if (key == 4 && y_right < 18){//правая ракетка вниз
            y_right++;
        }
        
        int key_ball = control_ball(y_left, y_right, x_ball, y_ball, modul_x, modul_y);
        if (key_ball == 0){
            x_ball--;
            y_ball--;}
        else if (key_ball == 1){
            x_ball--;
            y_ball++;}
        else if (key_ball == 2){
            x_ball++;
            y_ball--;}
        else if (key_ball == 3){
            x_ball++;
            y_ball++;}
        else if (key_ball == -1){
            modul_x*(-1);
        }
        
        if (x_ball < 1 || x_ball > 101){
            x_ball = 51;
            y_ball = 10;
        }
        else if (y_ball == 2 || y_ball == 20){
            modul_y = modul_y*(-1);
        }

        system("clear");
        gui(x_ball, y_ball, y_right, y_left, score_right, score_left);
    }
    
}          