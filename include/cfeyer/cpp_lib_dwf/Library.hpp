// MIT License
// 
// Copyright (c) 2017 Chris Feyerchak
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef CFEYER__CPP_LIB_DWF__LIBRARY_HPP
#define CFEYER__CPP_LIB_DWF__LIBRARY_HPP

#include <cfeyer/cpp_api_dwf/Library_Interface.hpp>

namespace cfeyer {

namespace cpp_lib_dwf {

class Library : public ::cfeyer::cpp_api_dwf::Library_Interface
{
   public:

      Library();
      ~Library();

      ::cfeyer::cpp_api_dwf::Device_Enumerator_Interface & get_device_enumerator();

   private:

      Library( const Library & ); // disallow
      Library & operator = ( const Library & ); // disallow

      Library_Interface * mp_impl;
};

} // namespace cpp_lib_dwf
} // namespace cfeyer

#endif /* CFEYER__CPP_LIB_DWF__LIBRARY_HPP */
