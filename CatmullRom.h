//
//  CatmullRom.h
//  DessertTown
//
//  Created by wonhee jang on 13. 4. 5..
//  Copyright (c) 2013년 vanillabreeze. All rights reserved.
//

#ifndef __DessertTown__CatmullRom__
#define __DessertTown__CatmullRom__

#include <iostream>
#include "Cubic.h"

namespace Spline {
	class CatmullRom : public Cubic {
	public:
		CatmullRom(float* _controll_point, unsigned int _length, unsigned int _number_part);
		virtual float blend(int _i, float _t);
	};
};

#endif /* defined(__DessertTown__CatmullRom__) */
