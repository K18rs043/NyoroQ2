	//ColorDetection.c
#include "ColorDetection.h"
#include "ev3api.h"

#define REFLECT_WHITE	95      //白検出用反射光の閾値
#define REFLECT_BLACK	30      //黒検出用反射光の閾値
#define REFLECT_RED		48      //赤検出用反射光の閾値

//色検出
int DetectionColor(int color_sensor){

    int reflect = 0;            //反射光の値
    int color = 0;              //検出色

    //カラーセンサで反射光の強さを測定
    reflect = ev3_color_sensor_get_reflect(color_sensor);
    printf("reflect = %d\n", reflect);

    if(reflect >= REFLECT_WHITE){
        //白
        color = WHITE;
    }else if(reflect <= REFLECT_BLACK){
        //黒
        color = BLACK;
    }else{
        //赤
        color = RED;
    }

    return color;
}