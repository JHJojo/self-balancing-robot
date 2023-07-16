#ifndef _MOTOR_H
#define _MOTOR_H

class Motor
{
public:
        Motor();

        void Pin_init();

        void Encoder_init();
        static void EncoderCountRightA();
        static void EncoderCountLeftA();

        void (Motor::*MOVE[4])(int speed);
        void Stop();
        void Forward(int speed);
        void Back(int speed);
        void Left(int speed);
        void Right(int speed);

public:
        static unsigned long encoder_count_right_a;
        static unsigned long encoder_count_left_a;
};
#endif
