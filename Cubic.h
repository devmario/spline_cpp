//
//  Spline.h
//  DessertTown
//
//  Created by wonhee jang on 13. 4. 5..
//  Copyright (c) 2013년 vanillabreeze. All rights reserved.
//

#ifndef __DessertTown__Cubic__
#define __DessertTown__Cubic__

#include <iostream>

namespace Spline {
	
	class Cubic {
	public:
		float* controll_point;
		unsigned int length;
		unsigned int number_part;
		
		Cubic() = default;
		Cubic(float* _controll_point, unsigned int _length, unsigned int _number_part);
		virtual ~Cubic();
		
		virtual float* generate(int* _length);
		virtual void p(int _i, float _t, float* _cp, float* _sp, int _idx);
		virtual float blend(int _i, float _t);
	};
};

#endif /* defined(__DessertTown__Spline__) */
