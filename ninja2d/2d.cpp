//
// Created by nbollom on 29/01/18.
//

#include "2d.h"
#include <GL/glew.h>
#include <il.h>
#include <ilu.h>
#include <string>
#include <istream>
#include <memory>
#include <map>
#include "glimage.h"

typedef std::tuple<const std::string, int> TexKey;

std::map<TexKey, GLImage_Ptr> _textures;

//NOTE: consider bulk allocating/deleting GL textures for speed/reuse
//I can store free textures in std::set (ordered) and use first
//context would be semi-difficult to manage though

Image_Ptr LoadImage(const std::string &filename, std::istream &stream, int context) {
    auto key = std::make_tuple(filename, context);
    if (_textures.count(key)) {
        return _textures[key];
    }
    ILenum type = ilTypeFromExt(filename.c_str());
    ILuint il_image = ilGenImage();
    ilBindImage(il_image);
    std::string src_data(std::istreambuf_iterator<char>(stream), {});
    ilLoadL(type, src_data.c_str(), (ILuint)src_data.length());
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    auto width = ilGetInteger(IL_IMAGE_WIDTH);
    auto height = ilGetInteger(IL_IMAGE_HEIGHT);
    auto channels = ilGetInteger(IL_IMAGE_CHANNELS);
    auto depth = ilGetInteger(IL_IMAGE_DEPTH);
    GLenum format = channels == 4 ? GL_RGBA : GL_RGB;
    const short multiple = 2;
    int remainder = width % multiple;
    if (remainder != 0) {
        width = width + (multiple - remainder);
        iluScale((ILuint)width, (ILuint)height, (ILuint)depth);
    }
    int image_width = width;
    int image_height = height;
    ILubyte *data = ilGetData();
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, (GLvoid*) data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    ilDeleteImage(il_image);
    auto image = std::make_shared<GLImage>(width, height, texture);
    _textures[key] = image;
    return image;
}

void FreeImage(const std::string &filename, int context) {
    auto key = std::make_tuple(filename, context);
    if (_textures.count(key)) {
        GLuint texture = _textures[key]->Texture();
        glDeleteTextures(1, &texture);
        _textures.erase(key);
    }
}

void FreeAllImages(int context) {
    for (auto &tex: _textures) {
        if (std::get<1>(tex.first) == context) {
            GLuint texture = tex.second->Texture();
            glDeleteTextures(1, &texture);
            _textures.erase(tex.first);
        }
    }
}
