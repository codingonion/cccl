//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// basic_string<charT,traits,Allocator>& operator+=(charT c);

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S>
void
test(S s, typename S::value_type str, S expected)
{
    s += str;
    LIBCPP_ASSERT(s.__invariants());
    assert(s == expected);
}

int main(int, char**)
{
    {
    typedef std::string S;
    test(S(), 'a', S("a"));
    test(S("12345"), 'a', S("12345a"));
    test(S("1234567890"), 'a', S("1234567890a"));
    test(S("12345678901234567890"), 'a', S("12345678901234567890a"));
    }
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    test(S(), 'a', S("a"));
    test(S("12345"), 'a', S("12345a"));
    test(S("1234567890"), 'a', S("1234567890a"));
    test(S("12345678901234567890"), 'a', S("12345678901234567890a"));
    }

  return 0;
}
