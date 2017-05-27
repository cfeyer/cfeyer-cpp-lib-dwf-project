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

#include "Device_Enumerator.hpp"

#include <digilent/waveforms/dwf.h>

#include "DWF_Call_Wrapper.hpp"
#include "Device.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {

Device_Enumerator::Device_Enumerator()
{
   scan();
}


Device_Enumerator::~Device_Enumerator()
{
   while( m_device_ptrs.empty() == false )
   {
      Device * & p_device = m_device_ptrs.back();
      delete p_device;
      p_device = nullptr;
      m_device_ptrs.pop_back();
   }
}


void Device_Enumerator::scan()
{
   int device_count = -1;
   DWF_CALL_WRAPPER( FDwfEnum( enumfilterAll, &device_count ) );

   for( int device_index = 0; device_index < device_count; device_index++ )
   {
      Device * p_device = new Device( device_index );
      m_device_ptrs.push_back( p_device );
   }
}


int Device_Enumerator::get_device_count() const
{
   return m_device_ptrs.size();
}


::cfeyer::cpp_api_dwf::Device_Interface & Device_Enumerator::get_device( int device_index )
{
   return *( m_device_ptrs.at( device_index ) );
}


} // namespace cpp_lib_dwf
} // namespace cfeyer
