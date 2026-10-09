#include <iostream>
#include "Image_Class.h"

void Infrared_Image (Image& img) {
    for (int i = 0; i < img.height; ++i) {
        for (int j = 0; j < img.width; ++j) {

            int colorR = img.getPixel(j,i,0);
            int colorG = img.getPixel(j,i,1);
            int colorB = img.getPixel(j,i,2);

            int avg = ( colorR + colorG + colorB ) / 3;

            img.setPixel(j,i,0,255);

            img.setPixel(j,i,1,255 - avg);
            img.setPixel(j,i,2,255 - avg);
        }
    }
}

int main() {
    Image img("photo.jpg");
    Infrared_Image (img);
    img.saveImage("photofilter.jpg");

    std::cout << "Image saved!" << std::endl;
    return 0;
}