#include <iostream>
using namespace std;


class KalmanFilter
{

private:

    // State variables
    double position;
    double velocity;


    // Uncertainty matrix
    double uncertainty;


    // Process noise
    double processNoise;


    // Sensor noise
    double sensorNoise;



public:


    KalmanFilter()
    {
        position = 0;
        velocity = 0;

        uncertainty = 1;

        processNoise = 0.1;

        sensorNoise = 2;
    }



    // Prediction step
    void predict(double acceleration, double dt)
    {

        // Motion equations
        position =
            position +
            velocity * dt +
            0.5 * acceleration * dt * dt;


        velocity =
            velocity +
            acceleration * dt;



        // Increase uncertainty
        uncertainty += processNoise;

    }



    // Correction step
    void update(double measurement)
    {

        // Kalman Gain
        double kalmanGain =
            uncertainty /
            (uncertainty + sensorNoise);



        // Correct prediction
        position =
            position +
            kalmanGain *
            (measurement - position);



        // Reduce uncertainty
        uncertainty =
            (1 - kalmanGain)
            * uncertainty;

    }



    double getPosition()
    {
        return position;
    }


    double getVelocity()
    {
        return velocity;
    }

};



int main()
{

    KalmanFilter robot;


    // Fake robot sensor readings
    double sensorData[] =
    {
        1.2,
        2.1,
        3.9,
        5.2,
        6.1,
        8.3
    };


    double dt = 1.0;


    for(int i=0;i<6;i++)
    {

        // Robot prediction
        robot.predict(
            0.5,
            dt
        );


        // Sensor measurement
        robot.update(
            sensorData[i]
        );


        cout
        << "Robot Position: "
        << robot.getPosition()
        << " meters | Velocity: "
        << robot.getVelocity()
        << " m/s"
        << endl;

    }


    return 0;
}
