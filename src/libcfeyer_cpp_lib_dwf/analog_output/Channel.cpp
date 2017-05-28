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

#include "analog_output/Channel.hpp"

#include <digilent/waveforms/dwf.h>
#include "DWF_Call_Wrapper.hpp"
#include "analog_output/Carrier_Component.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

Channel::Channel( HDWF device_descriptor,
                  int channel_index ) :
   m_device_descriptor( device_descriptor ),
   m_channel_index( channel_index ),
   mp_carrier_component( new_carrier_component() )
{
}


::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * Channel::new_carrier_component()
{
   ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * p_component = nullptr;

   if( query_has_node( AnalogOutNodeCarrier ) )
   {
      p_component = new Carrier_Component( m_device_descriptor, m_channel_index ); //TODO Move test to Signal_Component ctor
   }

   return p_component;
}


Channel::~Channel()
{
   stop();
}


void Channel::start()
{
   DWF_CALL_WRAPPER( FDwfAnalogOutConfigure( m_device_descriptor, m_channel_index, true ) );
}


void Channel::stop()
{
   DWF_CALL_WRAPPER( FDwfAnalogOutConfigure( m_device_descriptor, m_channel_index, false ) );
}


void Channel::reset()
{
   DWF_CALL_WRAPPER( FDwfAnalogOutReset( m_device_descriptor, m_channel_index ) );
}


::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * Channel::get_carrier_component() const
{
   return mp_carrier_component;
}


int Channel::query_node_info() const
{
   int buffer = 0;
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeInfo( m_device_descriptor,
                                            m_channel_index,
                                            &buffer ) );
   return buffer;
}


bool Channel::query_has_node( AnalogOutNode node_index ) const
{
   int node_bitfield = query_node_info();
   return IsBitSet( node_bitfield, node_index );
}

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer
