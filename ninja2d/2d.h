//
// Created by nbollom on 29/01/18.
//

#ifndef NINJAFRAMEWORK_2D_H
#define NINJAFRAMEWORK_2D_H

#include "image.h"

#endif //NINJAFRAMEWORK_2D_H

Image_Ptr LoadImage(const std::string &filename, std::istream &stream, int context=0);
void FreeImage(const std::string &filename, int context=0);
void FreeAllImages(int context=0);
