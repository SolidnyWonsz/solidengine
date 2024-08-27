#pragma once

#include <common/defines.h>
#include <vector>

namespace Loader {
    class OBJ {
        public:
            OBJ(const char *path);

            std::vector<float> &GetVertices();
            std::vector<unsigned int> &GetIndices();

        private:
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
    };
}