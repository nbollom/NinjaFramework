//
// Created by Nathan Bollom on 9/4/18.
//

#ifndef NINJAFRAMEWORK_CONTEXT_H
#define NINJAFRAMEWORK_CONTEXT_H

#include <map>
#include "image.h"

namespace NinjaFramework {
    namespace TwoD {
        class Context {

        private:
            std::map<const std::string, Image_Ptr> _textures;
            std::function<void(void)> _activate;
            std::function<bool(void)> _is_active;

        public:
            explicit Context(std::function<void(void)> &activate, std::function<bool(void)> &is_active) :
                    _activate(activate), _is_active(is_active) {}

            Image_Ptr LoadImage(const std::string &identifier, std::istream &stream);
            Image_Ptr GetImage(const std::string &identifier);
            bool HasImage(const std::string &identifier);
            void FreeImage(const std::string &identifier);
            void FreeAllImages();
        };


#ifndef NINJA_2D_MULTI_CONTEXT
        std::shared_ptr<Context> GetDefaultContext();
#endif

    }
}

#endif //NINJAFRAMEWORK_CONTEXT_H
