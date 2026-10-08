#include <iostream>
#include "Image_Class.h"

int imageFrame = 10;

void Simple_Frame(Image &img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            if (i < imageFrame || i >= img.width - imageFrame || j < imageFrame || j >= img.height - imageFrame) {
                img(i,j,0) = 255;
                img(i,j,1) = 255;
                img(i,j,2) = 255;
            }
        }
    }
    img.saveImage("photofilter.jpg");
}

void Pattern_Frame(Image &img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            if (i < imageFrame || i >= img.width - imageFrame || j < imageFrame || j >= img.height - imageFrame) {
                if ((i / 8 + j / 8) % 2 == 0) {
                    img(i,j,0) = 0;
                    img(i,j,1) = 0;
                    img(i,j,2) = 0;
                } else {
                    img(i,j,0) = 255;
                    img(i,j,1) = 255;
                    img(i,j,2) = 255;
                }
            }
        }
    }
    img.saveImage("photofilter.jpg");
}
int main() {
    Image image("photo.jpg");
    std::cout << "Choose the Frame Type ( S for Simple,P for Pattern)" << std::endl;
    char choice;
    std::cin >> choice;

    if (choice == 'S') {
        Simple_Frame(image);
    }  else if (choice == 'P') {
        Pattern_Frame(image);
    }  else {
        std::cout << "Invalid Choice" << std::endl;
    }

    std::cout <<"Process Done" << std::endl;

    return 0;
}