//
// Created by Nathan Bollom on 9/4/18.
//

#include "context.h"
#include <GL/glew.h>
#include <il.h>
#include <ilu.h>
#include <string>
#include <istream>
#include <memory>
#include "glimage.h"

namespace NinjaFramework {
    namespace TwoD {

        Image_Ptr Context::LoadImage(const std::string &identifier, std::istream &stream) {
            if (_textures.count(identifier)) {
                return _textures[identifier];
            }
            ILenum type = ilTypeFromExt(identifier.c_str());
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
            _textures[identifier] = image;
            return image;
        }

        void Context::FreeImage(const std::string &identifier) {
            if (_textures.count(identifier)) {
                GLuint texture = std::static_pointer_cast<GLImage>(_textures[identifier])->Texture();
                glDeleteTextures(1, &texture);
                _textures.erase(identifier);
            }
        }

        void Context::FreeAllImages() {
            for (auto &tex: _textures) {
                GLuint texture = std::static_pointer_cast<GLImage>(tex.second)->Texture();
                glDeleteTextures(1, &texture);
                _textures.erase(tex.first);
            }
        }

        std::shared_ptr<Context> default_context = nullptr;

        std::shared_ptr<Context> GetDefaultContext() {
            if (default_context == nullptr) {
                std::function<void(void)> activate = [](){

                };
                std::function<bool(void)> is_active = []() {
                    return true;
                };
                default_context = std::make_shared<Context>(activate, is_active);
            }
            return default_context;
        }

    }
}
