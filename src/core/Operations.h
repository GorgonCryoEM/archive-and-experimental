/*
 * Operations.h
 *
 *  Created on: Feb 5, 2016
 *      Author: shadow_walker
 */

#ifndef SRC_CORE_OPERATIONS_H_
#define SRC_CORE_OPERATIONS_H_

#include "Volume.h"
#include <boost/python.hpp>

using namespace boost::python;

using namespace Core;

class Operation {
    public:
        Operation(Volume &vol);
//        virtual void operator()(Volume &vol) =0;
    protected:
        Volume &volume;
};

class Fill : public Operation {
    public:
        Fill(Volume &vol);
        virtual void operator()(double val);
};

//struct OperationWrapper : public Operation, boost::python::wrapper<Operation> {
//        OperationWrapper(Volume vol)
//                     : Operation(vol)
//                       {}
//};

#endif /* SRC_CORE_OPERATIONS_H_ */
