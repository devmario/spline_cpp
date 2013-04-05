//
//  CatmullRom.cpp
//  DessertTown
//
//  Created by wonhee jang on 13. 4. 5..
//  Copyright (c) 2013년 vanillabreeze. All rights reserved.
//

#include "CatmullRom.h"

using namespace Spline;

CatmullRom::CatmullRom(float* _controll_point, unsigned int _length, unsigned int _number_part) : Cubic() {
	number_part = _number_part;
	length = _length + 6;
	controll_point = new float[length];
	for( int n = 3 ; n < length ; n++ )
	{
		controll_point[n] = _controll_point[n - 3];
	}
	controll_point[0] = controll_point[3];
	controll_point[1] = controll_point[4];
	controll_point[2] = controll_point[5];
	controll_point[length - 3] = controll_point[length - 6];
	controll_point[length - 2] = controll_point[length - 5];
	controll_point[length - 1] = controll_point[length - 4];
};

float CatmullRom::blend(int i, float t) {
	if( i == -2 )
		return ( ( -t + 2 ) * t - 1 ) * t / 2;
	else if( i == -1 )
		return ( ( ( 3 * t - 5 ) * t ) * t + 2 ) / 2;
	else if( i ==  0 )
		return ( ( -3 * t + 4 ) * t + 1 ) * t / 2;
	else
		return ( ( t - 1 ) * t * t ) / 2;
}