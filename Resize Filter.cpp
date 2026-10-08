#include <iostream>
#include "Image_Class.h"

using namespace std;

void ResizeImage(Image& img, int newWidth, int newHeight) {

    Image resizedImg(newWidth, newHeight);

    double scaleI = (double) img.width / newWidth;
    double scaleJ = (double) img.height / newHeight;

    for ( int i = 0; i < newWidth; ++i) {
        for ( int j = 0; j < newHeight; ++j ) {

            int origI = i * scaleI;
            int origJ = j * scaleJ;

            for ( int k = 0; k < img.channels; ++k ) {

                int color = img.getPixel(origI, origJ, k);
                resizedImg.setPixel(i, j,k, color);
            }
        }
    }
    resizedImg.saveImage("photofilter.jpg");
    cout << "Image Resized!" << endl;
}

int main() {

    const string filename = "photo.jpg";

    Image img(filename);

    int choice;
    int newWidth , newHeight = 0;

    cout <<"1. Enter new Dimensions ( Width x Height )\n ";
    cout <<"2. Enter Scaling Ratio percentage \n ";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        cout <<"Enter new Width and Height: ";
        cin >> newWidth >> newHeight;
    }
    else if (choice == 2) {
        float ratio;
        cout <<"Enter new Scale Ratio (e.g, 50 for half size,200 for double size: ";
        cin >> ratio;

        newWidth = img.width * (ratio / 100.0);
        newHeight = img.height * (ratio / 100.0);
    }
    else {
        cout <<"Invalid Choice!" <<endl;
        return 1;
    }
    ResizeImage(img, newWidth, newHeight);
    return 0;
}

