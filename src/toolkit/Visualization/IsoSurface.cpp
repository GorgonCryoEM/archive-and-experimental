/*
 * IsoSurface.cpp
 *
 * Author: shadow_walker <shadowwalkersb@gmail.com>
 *
 */

#include "IsoSurface.h"

namespace Visualization {

    IsoSurface::IsoSurface()
            : surfaceMesh(VolumeSurfaceMeshType())
    {
        displayRadius = 1;
        _useDisplayRadius = false;
    }

    IsoSurface::~IsoSurface() {
    }

    bool IsoSurface::calculateDisplay() {
        bool redraw = false;
        #ifndef USE_OCTREE_OPTIMIZATION
            //appTimeManager.PushCurrentTime();
            //appTimeManager.PushCurrentTime();
            surfaceMesh.Clear();
            //appTimeManager.PopAndDisplayTime("Marching Cubes)  Clearing : %f seconds |");
            redraw = false;

            if(drawEnabled && volData != NULL) {
                redraw = true;
                int maxX = getSizeX();
                int maxY = getSizeY();
                int maxZ = getSizeZ();
                for(int i = 0; i < maxX; i+=sampleInterval) {
                    for(int j = 0; j < maxY; j+=sampleInterval) {
                        for(int k = 0; k < maxZ; k+=sampleInterval) {
                            MarchingCube(*this, surfaceMesh, surfaceValue, i, j, k, sampleInterval);
                        }
                    }
                }
                /*for(iX = max(radiusOrigin.X() - displayRadius, 0); iX < min(maxX, radiusOrigin.X() + displayRadius); iX+=sampleInterval) {
                    for(iY = max(radiusOrigin.Y() - displayRadius, 0); iY < min(maxY, radiusOrigin.Y() + displayRadius); iY+=sampleInterval) {
                        for(iZ = max(radiusOrigin.Z() - displayRadius, 0); iZ < min(maxZ, radiusOrigin.Z() + displayRadius); iZ+=sampleInterval) {
                            MarchingCube(dataVolume, surfaceMesh, surfaceValue, iX, iY, iZ, sampleInterval);
                        }
                    }
                }*/
            }
            //appTimeManager.PopAndDisplayTime("Meshing: %f seconds |");
        #else
            appTimeManager.PushCurrentTime();
            appTimeManager.PushCurrentTime();
            surfaceMesh.Clear();
            appTimeManager.PopAndDisplayTime("Octree)          Clearing : %f seconds |");
            marchingCubeCallCount = 0;
            redraw = false;
            if(drawEnabled && dataVolume != NULL && octree != NULL) {
                redraw = true;
                calculateOctreeNode(octree->GetRoot());
            }

            appTimeManager.PopAndDisplayTime("Meshing: %f seconds |");
        #endif
        //printf("Marching Cubes called %d times\n", marchingCubeCallCount);

            return redraw;

    }

    void IsoSurface::draw(int subSceneIndex, bool selectEnabled) {
        if(subSceneIndex == 0)
            surfaceMesh.draw(true, selectEnabled, _useDisplayRadius, displayRadius, radiusOrigin);
    }

    void IsoSurface::setDisplayRadius(const int radius) {
        displayRadius = radius;
    }

    void IsoSurface::setDisplayRadiusOrigin(float radiusOriginX, float radiusOriginY, float radiusOriginZ) {
        radiusOrigin = Vec3F(radiusOriginX, radiusOriginY, radiusOriginZ);
    }

    void IsoSurface::useDisplayRadius(bool useRadius) {
        _useDisplayRadius = useRadius;
    }

} /* namespace Visualization */
