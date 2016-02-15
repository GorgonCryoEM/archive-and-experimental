#include <vector>
#include <iostream>
#include <stdexcept>
#include <type_traits>

using namespace std;

template <int D, class T>
class Dim {
  public:
    Dim()    : dim(T()), dims()  {}
    template<class... Args>
    Dim(T v, Args... args)
//    Dim(T v)
        : dim(v),   dims(args...)
    {
            static_assert(sizeof...(Args)+1==D, "Wrong number of arguments");
//      cout<<"Dim<"<<D<<">::ctor("<<v<<")"<<endl;
    }

    T& operator[](int d) {
      //cout<<"operator[]<"<<D<<">(int "<<d<<")"<<endl;
      return const_cast<T &>(static_cast<const Dim<D,T>& >(*this)[d]);
    }

    const T& operator[](int d) const {
      //cout<<"operator[]<"<<D<<">(int "<<d<<")"<<endl;
      return d==D ? dim : dims[d];
    }

    T dim;
    Dim<D-1,T> dims;
};

template <int D, class T>
ostream& operator<<(ostream& out, const Dim<D,T> &obj){
    out<<obj.dims
	<<" "<<obj.dim;

  return out;
}

template <class T>
class Dim<1,T> {
  public:
    Dim()    : dim(T()) {}

//    template<class... Args>
//    Dim(Args args)
    Dim(T v)
    : dim(v)
    {
//            static_assert(sizeof...(Args)==D. "Wrong number of arguments");
            cout<<"Dim<1>::ctor("<<v<<")"<<endl;
    }

    T& operator[](int d) {
      //cout<<"operator[]<"<<1<<">(int "<<d<<")"<<endl;
      //return dim;
      return const_cast<T &>(static_cast<const Dim<1,T>& >(*this)[d]);
    }

    const T& operator[](int d) const {
      return d==1 ? dim : throw out_of_range("Out of range");
    }

    T dim;
};

template <class T>
ostream& operator<<(ostream& out, const Dim<1,T> &obj){
    out<<obj.dim;

  return out;
}

//template <int D, class T>
//class Dim : public DimBase<D,T>{
//    public:
//        Dim()    : DimBase<D,T>() {}
////        Dim(T v) : DimBase<D,T>(v)   {}
//        template<class... Args>
//        Dim(T v, Args... args) : DimBase<D,T>(v, args...)   {}
//};
//
//template <class T>
//class Dim<1,T> : public DimBase<1,T>{
//    public:
//        Dim()    : DimBase<1,T>() {}
//        Dim(T v) : DimBase<1,T>(v)   {}
////        T x() {
////            return this->operator[](1);
////        }
//};


