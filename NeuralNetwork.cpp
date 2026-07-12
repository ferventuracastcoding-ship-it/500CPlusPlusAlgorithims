#include <iostream>
#include <cmath>

using namespace std;


double sigmoid(double x)
{
    return 1/(1+exp(-x));
}


int main()
{

    double input1=0.5;
    double input2=0.8;


    double weight1=0.7;
    double weight2=0.3;


    double bias=0.2;


    double sum =
        input1*weight1 +
        input2*weight2 +
        bias;


    double output=sigmoid(sum);


    cout<<"AI Output: "
        <<output;

}
