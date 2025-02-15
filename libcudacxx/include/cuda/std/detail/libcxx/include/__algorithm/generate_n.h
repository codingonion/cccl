//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCUDACXX___ALGORITHM_GENERATE_N_H
#define _LIBCUDACXX___ALGORITHM_GENERATE_N_H

#ifndef __cuda_std__
#  include <__config>
#endif // __cuda_std__

#include "../__utility/convert_to_integral.h"

#if defined(_CCCL_IMPLICIT_SYSTEM_HEADER_GCC)
#  pragma GCC system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_CLANG)
#  pragma clang system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_MSVC)
#  pragma system_header
#endif // no system header

_LIBCUDACXX_BEGIN_NAMESPACE_STD

template <class _OutputIterator, class _Size, class _Generator>
inline _LIBCUDACXX_HIDE_FROM_ABI _LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX11 _OutputIterator
generate_n(_OutputIterator __first, _Size __orig_n, _Generator __gen)
{
  using _IntegralSize = decltype(__convert_to_integral(__orig_n));
  _IntegralSize __n   = static_cast<_IntegralSize>(__orig_n);
  for (; __n > 0; ++__first, (void) --__n)
  {
    *__first = __gen();
  }
  return __first;
}

_LIBCUDACXX_END_NAMESPACE_STD

#endif // _LIBCUDACXX___ALGORITHM_GENERATE_N_H
