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

#include "Open_Device.hpp"

#include <iostream>

#include "DWF_Call_Wrapper.hpp"

#include "Analog_Output_Channels.hpp"


namespace cfeyer {
namespace cpp_lib_dwf {

Open_Device::Open_Device( int device_index ) :
   Device( device_index ),
   m_device_descriptor( open( m_device_index ) ),
   mp_analog_outputs( new Analog_Output_Channels( m_device_descriptor ) )
{
}


Open_Device::~Open_Device()
{
   delete mp_analog_outputs;
   mp_analog_outputs = nullptr;

   close();
}


HDWF Open_Device::open( int device_index )
{
   HDWF device_descriptor = hdwfNone;
   DWF_CALL_WRAPPER( FDwfDeviceOpen( device_index, &device_descriptor ) );
   return device_descriptor;
}


void Open_Device::close()
{
   DWF_CALL_WRAPPER( FDwfDeviceClose( m_device_descriptor ) );
}


::cfeyer::cpp_api_dwf::Analog_Output_Channels_Interface & Open_Device::get_analog_outputs()
{
   return *mp_analog_outputs;
}



} // namespace cpp_lib_dwf
} // namespace cfeyer
