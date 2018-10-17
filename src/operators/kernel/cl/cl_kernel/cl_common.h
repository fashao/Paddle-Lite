/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma OPENCL EXTENSION cl_khr_fp16 : enable

inline half4 activation(half4 in
#ifdef PRELU
                        ,
                        half4 prelu_alpha
#endif
) {
  half4 output;
#ifdef PRELU
  output = select(prelu_alpha * in, in, in >= (half4)0.0);
#endif

#ifdef RELU
  output = fmax(in, (half4)(0.0f));
#endif
  return output;
}