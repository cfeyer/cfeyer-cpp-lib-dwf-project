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

#include "Device.hpp"

#include <iostream>

#include "DWF_Call_Wrapper.hpp"

#include "Open_Device.hpp"


namespace cfeyer {
namespace cpp_lib_dwf {

Device::Device( int device_index ) :
   m_device_index( device_index )
{
}


Device::~Device()
{
}


std::string Device::get_name() const
{
   char buffer[32] = { '\0' };
   DWF_CALL_WRAPPER( FDwfEnumDeviceName( m_device_index, buffer ) );
   buffer[31] = '\0';

   return buffer;
}


std::string Device::get_user_name() const
{
   char buffer[32] = { '\0' };
   DWF_CALL_WRAPPER( FDwfEnumUserName( m_device_index, buffer ) );
   buffer[31] = '\0';

   return buffer;
}


std::string Device::get_serial_number() const
{
   char buffer[32] = { '\0' };
   DWF_CALL_WRAPPER( FDwfEnumSN( m_device_index, buffer ) );
   buffer[31] = '\0';

   return buffer;
}


bool Device::is_busy() const
{
   BOOL buffer = 0;
   DWF_CALL_WRAPPER( FDwfEnumDeviceIsOpened( m_device_index, &buffer ) );

   return ( buffer ? true : false );
}


::cfeyer::cpp_api_dwf::Open_Device_Interface * Device::open()
{
   return new Open_Device( m_device_index );
}


} // namespace cpp_lib_dwf
} // namespace cfeyer
