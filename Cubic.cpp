//
//  Spline.cpp
//  DessertTown
//
//  Created by wonhee jang on 13. 4. 5..
//  Copyright (c) 2013년 vanillabreeze. All rights reserved.
//

#include "Cubic.h"

using namespace Spline;

Cubic::Cubic(float* _controll_point, unsigned int _length, unsigned int _number_part) {
	number_part = _number_part;
	length = _length + 12;
	controll_point = new float[length];
	for( int i = 6 ; i < length ; i++ )
	{
		controll_point[i] = _controll_point[i - 6];
	}
	controll_point[0] = controll_point[6];
	controll_point[1] = controll_point[7];
	controll_point[2] = controll_point[8];
	controll_point[3] = controll_point[6];
	controll_point[4] = controll_point[7];
	controll_point[5] = controll_point[8];
	controll_point[length - 3] = controll_point[length - 9];
	controll_point[length - 2] = controll_point[length - 8];
	controll_point[length - 1] = controll_point[length - 7];
	controll_point[length - 6] = controll_point[length - 9];
	controll_point[length - 5] = controll_point[length - 8];
	controll_point[length - 4] = controll_point[length - 7];
}

Cubic::~Cubic() {
	delete[] controll_point;
}

float* Cubic::generate(int *_length) {
	int n = length / 3;
	int l = (n - 3) * number_part + 1;
	*_length = l * 3;
	float* sp = new float[*_length];
	p( 2 , 0 , controll_point , sp , 0 );
	int idx = 3;
	for( int i = 2 ; i < n - 1 ; i++ )
	{
		for( int j = 1; j <= number_part ; j++ )
		{
			p( i , j / (float)number_part , controll_point , sp , idx );
			idx += 3;
		}
	}
	return sp;
}

void Cubic::p(int _i, float _t, float* _cp, float* _sp, int _idx) {
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	int k = ( _i - 2 ) * 3;
	for( int j = -2 ; j <= 1 ; j++ )
	{
		float b = blend( j , _t );
		x += b * _cp[k++];
		y += b * _cp[k++];
		z += b * _cp[k++];
	}
	_sp[_idx + 0] = x;
	_sp[_idx + 1] = y;
	_sp[_idx + 2] = z;
}

float Cubic::blend(int i, float t) {
	if( i == -2 )
		return ( ( ( -t + 3 ) * t - 3 ) * t + 1 ) / 6;
	else if( i == -1 )
		return ( ( ( 3 * t - 6 ) * t ) * t + 4 ) / 6;
	else if( i ==  0 )
		return ( ( ( -3 * t + 3 ) * t + 3 ) * t + 1 ) / 6;
	else
		return ( t * t * t ) / 6;
}
