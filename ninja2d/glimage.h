//
// Created by nbollom on 30/01/18.
//

#ifndef NINJAFRAMEWORK_GLIMAGE_H
#define NINJAFRAMEWORK_GLIMAGE_H

#include <GL/glew.h>
#include "image.h"

class GLImage : public Image {

private:
    GLuint _texture;

public:
    explicit GLImage(unsigned int width, unsigned int height, GLuint texture) : Image(width, height), _texture(texture) {};
    GLuint Texture();

};

typedef std::shared_ptr<GLImage> GLImage_Ptr;

#endif //NINJAFRAMEWORK_GLIMAGE_H
