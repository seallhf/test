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


#include <ostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>

using namespace std;

namespace mycnn {

	enum param_init_type {
		constant, xavier, gaussian, msra
	};

	enum phrase_type {
		test, train
	};

	enum run_mode {
		cpu, gpu
	};

	typedef float float_t;

	typedef string chars_t;

	typedef vector<int> CACU_ARGS;

	typedef vector<float_t> vec_t;

	typedef vector<unsigned int> vec_i;

	typedef vector<float_t*> vec_f;


	//string split
	vector<string> split(string str, string pattern) {
		vector<string> ret;
		if (pattern.empty())
			return ret;
		size_t start = 0, index = str.find_first_of(pattern, 0);
		while (index != str.npos) {
			if (start != index) {
				if (str.substr(start, index - start) != "")
					ret.push_back(str.substr(start, index - start));
			}
			start = index + 1;
			index = str.find_first_of(pattern, start);
		}
		if (!str.substr(start).empty()) {
			if (str.substr(start) != "")
				ret.push_back(str.substr(start));
		}
		return ret;
	}

};
