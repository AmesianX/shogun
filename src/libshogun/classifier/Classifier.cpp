/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2009 Soeren Sonnenburg
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "classifier/Classifier.h"
#include "lib/Parameter.h"

#ifdef HAVE_BOOST_SERIALIZATION
#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_GUID(shogun::CClassifier, "CClassifier");
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(shogun::CClassifier);
#endif //HAVE_BOOST_SERIALIZATION

using namespace shogun;

CClassifier::CClassifier() : CSGObject(), max_train_time(0), labels(NULL),
	solver_type(ST_AUTO)
{
	m_parameters->add_float64(&max_train_time, "max_train_time",
							  "Maximum training time.");
	m_parameters->add_int32((int32_t*) &solver_type, "solver_type");
	m_parameters->add_sgobject((CSGObject**) &labels, "labels");
}

CClassifier::~CClassifier()
{
    SG_UNREF(labels);
}
