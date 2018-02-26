//
// Created by nbollom on 30/01/18.
//

#ifndef NINJAFRAMEWORK_IMAGE_H
#define NINJAFRAMEWORK_IMAGE_H

#include <memory>

class Image {

protected:
    unsigned int _width;
    unsigned int _height;

public:
    explicit Image(unsigned int width, unsigned int height) : _width(width), _height(height) {}

    unsigned int Width();
    unsigned int Height();

};

typedef std::shared_ptr<Image> Image_Ptr;

#endif //NINJAFRAMEWORK_IMAGE_H
