/*
 * IsoSurface.h
 *
 * Author: shadow_walker <shadowwalkersb@gmail.com>
 *
 */

#ifndef SRC_TOOLKIT_VISUALIZATION_ISOSURFACE_H_
#define SRC_TOOLKIT_VISUALIZATION_ISOSURFACE_H_

#include "DisplayBase.h"

namespace Visualization {

    /*
     *
     */
    class IsoSurface : public DisplayBase {
        public:
            IsoSurface(Volume & V);
            virtual ~IsoSurface();

            bool calculateDisplay();
            void load3DTexture();

            void draw(int subSceneIndex, bool selectEnabled);
            void setSampleInterval(const int size);
            void setSurfaceValue(const float value);
            void setMaxSurfaceValue(const float value);
            bool setCuttingPlane(float position, float vecX, float vecY, float vecZ);

        private:
            int displayRadius;
            Vec3F radiusOrigin;

    };

} /* namespace Visualization */

#endif /* SRC_TOOLKIT_VISUALIZATION_ISOSURFACE_H_ */
