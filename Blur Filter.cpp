#include <iostream>
#include "Image_Class.h"

void BlurImage(Image& img, int radius) {
    Image result = img;

    for (int i = 0; i < img.height; ++i) {
        for (int j = 0; j < img.width; ++j) {
            long long sumR = 0,sumG = 0,sumB = 0;
            int count = 0;

            for ( int deltaI = -radius; deltaI <= radius; ++deltaI) {
                for ( int deltaJ = -radius; deltaJ <= radius; ++deltaJ) {
                    int newI = i + deltaI;
                    int newJ = j + deltaJ;

                    if ( newI >= 0 && newI < img.height && newJ >= 0 && newJ < img.width ) {
                        sumR += img.getPixel(newJ, newI,0);
                        sumG += img.getPixel(newJ, newI,1);
                        sumB += img.getPixel(newJ, newI,2);
                        count++;
                    }
                }
            }
            result.setPixel(j, i , 0, sumR / count );
            result.setPixel(j, i , 1, sumG / count );
            result.setPixel(j, i , 2, sumB / count );
        }
    }
    img = result;
}
int main() {
    Image img("sea.jpg");
    int blurDegree;
    std::cout << "Enter blur degree: (e.g.: 3 for low,6 for medium,9 for high): ";
    std::cin >> blurDegree;
    BlurImage (img, blurDegree);
    img.saveImage("photofilter.jpg");

    std::cout << "Image saved!" << std::endl;
    return 0;
};