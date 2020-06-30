//RunControl.h

//直進
void forward(int left_motor, int right_motor, int speed);

//モータ停止
void stop(int left_motor, int right_motor);

//カーブ
void turnLeft(int left_motor, int right_motor, int speed,int turnspeed); //左カーブ
void turnRight(int left_motor, int right_motor, int speed,int turnspeed); //右カーブ