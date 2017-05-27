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

#include "Analog_Output_Channel.hpp"

#include <digilent/waveforms/dwf.h>

#include "DWF_Call_Wrapper.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {

Analog_Output_Channel::Analog_Output_Channel( HDWF device_descriptor,
                                              int channel_index ) :
   m_device_descriptor( device_descriptor ),
   m_channel_index( channel_index )
{
}


Analog_Output_Channel::~Analog_Output_Channel()
{
   disable();
}


void Analog_Output_Channel::enable()
{
//   DWF_CALL_WRAPPER( FDwfEnum( enumfilterAll, &device_count ) );
}


void Analog_Output_Channel::disable()
{
//   DWF_CALL_WRAPPER( FDwfEnum( enumfilterAll, &device_count ) );
}


bool Analog_Output_Channel::is_enabled() const
{
   return false;
}


} // namespace cpp_lib_dwf
} // namespace cfeyer
