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


#include "../ops/operator_factory.h"

namespace mycnn{

	class layer : public layer_base{


	public:

		layer(int output_channel = 0, int kernel_size = 0, int stride = 0, int pad = 0, int input_dim = 0, int channel = 0,
			phrase_type phrase = train)
			:layer_base(output_channel, kernel_size, stride, pad, input_dim, channel,
			phrase){


		};

		void init(){
		
		}


		int caculate_data_space(){

		}

		layer* op(op_name op_) {

			args *args_ = new args(_output_channel, _kernel_size, _stride, _pad, _input_dim, _channel, _ARGSEND);
			blobs *blobs_ = cacu_allocator::create_blobs();
			if (out_blob != NULL)
				blobs_->push_back(out_blob);
			add_op(operator_factory::create_op(op_, blobs_, args_));
			out_blob = (blob*)(ops[ops.size() - 1])->out_data();
			return this;
		}

		layer* op(op_name op_, blob *blob_) {
			args *args_ = new args(_output_channel, _kernel_size, _stride, _pad, _input_dim, _channel, _ARGSEND);
			blobs *blobs_ = cacu_allocator::create_blobs();
			blobs_->push_back(blob_);
			if (out_blob!=NULL)
				blobs_->push_back(out_blob);
			add_op(operator_factory::create_op(op_, blobs_, args_));
			out_blob = (blob*)(ops[ops.size() - 1])->out_data();
			return this;
		}

		layer* op(op_name op_, blobs *blobs_) {
			args *args_ = new args(_output_channel, _kernel_size, _stride, _pad, _input_dim, _channel, _ARGSEND);
			if (out_blob != NULL)
				blobs_->push_back(out_blob);
			add_op(operator_factory::create_op(op_, blobs_, args_));
			out_blob = (blob*)(ops[ops.size() - 1])->out_data();
			return this;
		}

		template<class OPTYPE>
		inline OPTYPE* get_op(int i)
		{
			return (OPTYPE*)ops[i];
		}

		inline blob_base* get_oblob()
		{
			return out_blob;
		}

		~layer(){
		

		};

	protected:

		inline void add_op(operator_base* const op)
		{
			ops.push_back(op);
		}

	private:

		blob_base* out_blob;

	};

};