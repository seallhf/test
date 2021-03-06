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

	class network
	{
	public:

		network(){
		
		};

		~network(){

		};

		network& operator <<(layer_block* const &layer_block_) {
			for (int i = 0; i < layer_block_->length(); ++i)
				_layers.push_back(layer_block_->layer_bases(i));
			return *this;
		}

		network& operator <<(layer_block &layer_block_) {
			for (int i = 0; i < layer_block_.length(); ++i)
				_layers.push_back(layer_block_.layer_bases(i));
			return *this;
		}

		network& operator <<(layer_base* const &layer_) {

			_layers.push_back(layer_);
			return *this;
		}

		network& operator <<(layer_base &layer_) {

			_layers.push_back(&layer_);
			return *this;
		}

		template<class LAYERTYPE>
		inline LAYERTYPE *&layers(int i){ return (LAYERTYPE*&)_layers[i]; };

		inline layer_base *&layer_bases(int i){ return _layers[i]; };

		inline int length(){ return _layers.size(); };

	private:

		vector<layer_base*> _layers;

		blobs* _input_data;
	};

};