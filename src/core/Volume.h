#ifndef CORE_SKELETON_MAKER_VOLUME_DATA_H
#define CORE_SKELETON_MAKER_VOLUME_DATA_H

#include <vector>
#include "Dim3D.h"

using namespace std;
//using namespace Core;

namespace Core {
    class Volume {
    public:
        Volume();
        Volume(int sizeX, int sizeY, int sizeZ, double val=0.0);

        bool cmp(const Volume& obj)  const;

        int getSizeX() const;
        int getSizeY() const;
        int getSizeZ() const;
        int getSize() const;
        Dim3D<int> getSizeObj() const;

        double & operator()(int i, int j, int k);
        const double & operator()(int i, int j, int k) const;

    private:
        void setSize(int sizeX, int sizeY, int sizeZ, double val=0.0);

    protected:
        int getIndex(int x, int y, int z) const;

    protected:
        Dim3D<int> size;
        vector<double> data;

        friend ostream& operator<<(ostream& out, const Volume& obj){
            return out<<"\033[33m"
                <<"size:    "<<obj.size
                <<"size:    "<<obj.data.size()
                <<"\033[0m"<<endl;
        }
    };
}


#endif
