#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include <vector>



int main(int argc, char** argv)
{
    Mat_<u_char> image = imread("cow.jpg", IMREAD_GRAYSCALE);

    if (image.empty()) 
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); 
        return -1;
    }

    try {
        if (image.rows <= 1024 && image.cols <= 1024) {
            cout << "image size is ok" << endl;
        }
        else {
            throw image;
        }
    }
    catch (Mat matrix) {
        cout << "image size is incorrect, " << "rows: " << matrix.rows << " columns: " << matrix.cols << endl; 
    }

    


    Mat integralImg;
	integral(image, integralImg, CV_64F);

    int x,y,h,w;
    x = y = h = w = 0;
    
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    try {
        cout << "h: ";
        cin >> h;
        if (h > 16){
            throw h;
        }
    }
    catch (int h){
        cout << "h: " << h << " is wrong number";
        return 1;
    }

    try {
        cout << "w: ";
        cin >> w;
        if (w > 16){
            throw w;
        }
    }
    catch (int w){
        cout << "w: " << w << " is wrong number";
        return 1;
    }


    double p1 = integralImg.at<double>((y), (x));
	double p2 = integralImg.at<double>((y), (x + w));
	double p3 = integralImg.at<double>((y + h), (x));
	double p4 = integralImg.at<double>((y + h), (x + w));
    
    cout << "sum: " << (p1+p4) - (p2+p3);

    return 0;
}
