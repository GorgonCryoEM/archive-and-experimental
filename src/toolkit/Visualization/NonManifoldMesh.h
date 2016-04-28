#ifndef TOOLKIT_PROTEINMORPH_NON_MANIFOLD_MESH_H
#define TOOLKIT_PROTEINMORPH_NON_MANIFOLD_MESH_H

#include <vector>
//#include <string>
#include <map>
#include <set>
#include <queue>
#include <fstream>

#include "Mesh.h"

#include "MathTools/BasicDefines.h"
#include "Core/volume.h"
#include "GorgonGL.h"
#include "Visualization/Rasterizer.h"
#include "Core/IdList.h"

using namespace std;
using namespace MathTools;
using namespace Foundation;
using namespace SkeletonMaker;

namespace Core {

    typedef map<TKey, Vertex > TV;
    typedef map<TKey, IdList >   TE;

    class NonManifoldMesh : public Volume, public Mesh {
        public:
            NonManifoldMesh();
            NonManifoldMesh(const Volume & src);
            void clear();
            void draw(bool drawSurfaceBorders, bool drawSurfaces,
                      bool drawLines, bool drawPoints, bool annotateSurfaces,
                      bool annotateLines, bool annotatePoints,
                      bool disableSurfaceLighting, bool disableCurveLighting,
                      bool disablePointLighting, int lineThickness,
                      bool smoothSurfaceNormals);

            int addMarchingVertex(Vec3F location, int hashKey);

            int addVertex(Vec3F location);
            int addEdge(IdList edge);
            IdList addEdge(int vertexId1, int vertexId2);

            Vec3F getVertexNormal(int vertexId);
            Vec3F getFaceNormal(int faceId);

            void addQuad(int vertexId1, int vertexId2, int vertexId3, int vertexId4);
            bool isSurfaceVertex(int ix) const;
            int getClosestVertexIndex(Vec3F pos);
            vector<TKey> getPath(TKey edge0Ix, TKey edge1Ix);
            vector<TKey> getNeighboringVertexIndices(TKey vertexIx);
            vector<Vec3F> sampleTriangle(int faceId, double discretizationStep);

            Volume toVolume();
            static NonManifoldMesh loadOffFile(string fileName);

        public:
            TV vertices;
            TE curves;

            bool fromVolume;

            friend ostream& operator<<(ostream& out, const NonManifoldMesh& obj);
    };
}

#endif
