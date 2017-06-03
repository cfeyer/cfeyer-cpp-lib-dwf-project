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

#include "analog_output/Idle_Value_Translate.hpp"
#include <digilent/waveforms/dwf.h>
#include <stdexcept>

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

DwfAnalogOutIdle Idle_Value_Translate::to_dwf( ::cfeyer::cpp_api_dwf::analog_output::Idle_Value::Enum x )
{
   using namespace ::cfeyer::cpp_api_dwf::analog_output;

   DwfAnalogOutIdle y = DwfAnalogOutIdleOffset;

   switch( x )
   {
      case Idle_Value::offset:  y = DwfAnalogOutIdleOffset;       break;
      default: throw std::invalid_argument( __PRETTY_FUNCTION__ );
   }

   return y;
}


::cfeyer::cpp_api_dwf::analog_output::Idle_Value::Enum Idle_Value_Translate::from_dwf( DwfAnalogOutIdle x )
{
   using namespace ::cfeyer::cpp_api_dwf::analog_output;

   Idle_Value::Enum y = Idle_Value::Enum::offset;

   switch( x )
   {
      case DwfAnalogOutIdleOffset:       y = Idle_Value::offset;  break;
      default: throw std::invalid_argument( __PRETTY_FUNCTION__ );
   }

   return y;
}

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer
