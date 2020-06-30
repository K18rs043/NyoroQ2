//ColorDetection.c
#include "ColorDetection.h"
#include "ev3api.h"

#define REFLECT_WHITE	95      //白検出用反射光の閾値
#define REFLECT_BLACK	30      //黒検出用反射光の閾値
#define REFLECT_RED		48      //赤検出用反射光の閾値

float midpoint = (REFLECT_WHITE - REFLECT_BLACK) / 2 + REFLECT_BLACK;

//色検出
int DetectionColor(int color_sensor){

    float reflect = 0;            //反射光の値
    int color = 0;              //検出色

    //カラーセンサで反射光の強さを測定
    reflect = ev3_color_sensor_get_reflect(color_sensor);
    printf("reflect = %d\n", reflect);

    if(reflect >= 95){
        color = WHITE;//白
    }else if(reflect <= 30){
        //黒
        color = BLACK;
    }else if(midpoint-1 <= reflect && reflect <= midpoint+1){
        color = GLAY;
    }else{
        color = RED;
    }

    return color;
}