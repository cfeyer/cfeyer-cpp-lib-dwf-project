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

#include "Analog_Output_Channels.hpp"

#include <digilent/waveforms/dwf.h>
#include "DWF_Call_Wrapper.hpp"

#include "Analog_Output_Channel.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {

Analog_Output_Channels::Analog_Output_Channels( HDWF device_descriptor ) :
   m_device_descriptor( device_descriptor )
{
   int channel_count = 0;
   DWF_CALL_WRAPPER( FDwfAnalogOutCount( m_device_descriptor, &channel_count ) );

   for( int channel_index = 0; channel_index < channel_count; channel_index++ )
   {
      Analog_Output_Channel * p_channel = new Analog_Output_Channel( m_device_descriptor, channel_index );
      m_channel_ptrs.push_back( p_channel );
   }
}


Analog_Output_Channels::~Analog_Output_Channels()
{
   while( m_channel_ptrs.empty() == false )
   {
      Analog_Output_Channel * & p_channel = m_channel_ptrs.back();
      delete p_channel;
      p_channel = nullptr;
      m_channel_ptrs.pop_back();
   }
}


int Analog_Output_Channels::get_count() const
{
   return m_channel_ptrs.size();
}


::cfeyer::cpp_api_dwf::Analog_Output_Channel_Interface & Analog_Output_Channels::get_channel( int channel_index )
{
   return *( m_channel_ptrs.at( channel_index ) );
}


} // namespace cpp_lib_dwf
} // namespace cfeyer
