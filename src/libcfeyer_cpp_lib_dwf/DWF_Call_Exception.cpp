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

#include "DWF_Call_Exception.hpp"

#include <sstream>

#include <digilent/waveforms/dwf.h>

namespace cfeyer {
namespace cpp_lib_dwf {

DWF_Call_Exception::DWF_Call_Exception( const char * stringified_code ) :
   std::runtime_error( make_what(stringified_code) )
{
}


std::string DWF_Call_Exception::make_what( const char * stringified_code ) const
{
   std::ostringstream strm;

   strm << stringified_code << ": "
        << get_last_dwf_error_message();

   return strm.str();
}


std::string DWF_Call_Exception::get_last_dwf_error_message() const
{
   char buffer[512] = { '\0' };
   FDwfGetLastErrorMsg( buffer ); // Can fail, but if it does, we can't do much
   buffer[511] = '\0';

   return std::string( buffer );
}

} // namespace cpp_lib_dwf
} // cfeyer
