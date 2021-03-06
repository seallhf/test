/*
Copyright (c) 2016, David lu
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

namespace mycnn{


	template<typename DTYPE>
	void cacu_sumbysize(SUM SUMTYPE ,DTYPE *x, int length, DTYPE *y, int sum_size)
	{

#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		int block_num = length / sum_size;
		DTYPE *xp;
		if (BYWIDTH == SUMTYPE){
			for (int b = 0; b < block_num; ++b){
				xp = x + b*sum_size;
				for (int i = 0; i < sum_size; ++i)
					y[b] += xp[i];
			}
		}
		else if (BYHEIGHT == SUMTYPE){
			for (int b = 0; b < block_num; ++b){
				xp = x + b*sum_size;
				for (int i = 0; i < sum_size; ++i)
					y[i] += xp[i];
			}
		}
#endif
	}

	template<typename DTYPE>
	void cacu_cxsize(DTYPE *x, int length, DTYPE *a, int size,DTYPE *y)
	{

#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		int block_size = length / size;
		DTYPE *xp;
		DTYPE *yp;
		for (int b = 0; b < size; ++b)
		{
			xp = x + b*block_size;
			yp = y + b*block_size;
			for (int j = 0; j < block_size; ++j)
				yp[j] = xp[j] * a[b];
		}
#endif
	}

	template<typename DTYPE>
	void cacu_sxsize(DTYPE *x, int length, DTYPE a, DTYPE *y)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		for (int j = 0; j < length; ++j)
			y[j] = x[j] * a;
#endif
	}

	template<typename DTYPE>
	void cacu_cdxsize(DTYPE *x, int length, DTYPE *a, int size, DTYPE *y)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		int block_size = length / size;
		DTYPE *xp;
		DTYPE *yp;
		for (int b = 0; b < size; ++b)
		{
			xp = x + b*block_size;
			yp = y + b*block_size;
			for (int j = 0; j < block_size; ++j)
				yp[j] = xp[j] / a[b];
		}
#endif
	}

	template<typename DTYPE>
	void cacu_sdxsize(DTYPE *x, int length, DTYPE a, DTYPE *y)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		for (int j = 0; j < length; ++j)
			y[j] = x[j] / a;
#endif
	}

	template<typename DTYPE>
	void cacu_ssxpy(DTYPE *x, DTYPE a, int size, DTYPE *y, DTYPE b, int length, DTYPE *z)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		int block_size = length / size;
		DTYPE *yp,*zp;
		for (int i = 0; i < size; ++i){
			yp = y + i*block_size;
			zp = z + i*block_size;
			for (int j = 0; j < block_size; ++j)
				zp[j] = a*x[i] + b*yp[j];
		}
#endif
	}


	template<typename DTYPE>
	void cacu_sqr(DTYPE *x, int length, DTYPE *y)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		for (int j = 0; j < length; ++j)
			y[j] = x[j] * x[j];
#endif
	}

	template<typename DTYPE>
	void cacu_root(DTYPE *x, int length, DTYPE *y)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		for (int j = 0; j < length; ++j)
			y[j] = x[j] * x[j];
#endif
	}

	template<typename DTYPE>
	void cacu_stdbychannel(DTYPE *x, int length, DTYPE *y, DTYPE epsilon)
	{
#if __PARALLELTYPE__ == __GPU__
		LOG_INFO("Haven't finished yet!");
#else
		for (int j = 0; j < length; ++j)
			y[j] = (float_t)pow(x[j] + epsilon, 0.5);
#endif
	}
};