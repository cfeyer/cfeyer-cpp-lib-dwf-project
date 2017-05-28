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

#include "analog_output/Abstract_Signal_Component.hpp"
#include <digilent/waveforms/dwf.h>
#include "DWF_Call_Wrapper.hpp"

#include <cfeyer/cpp_api_dwf/analog_output/Waveform_Shape_Enum.hpp>
#include "analog_output/Waveform_Shape_Translate.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

Abstract_Signal_Component::Abstract_Signal_Component( HDWF device_descriptor,
                           int channel_index,
                           int node_index ) :
   m_device_descriptor( device_descriptor ),
   m_channel_index( channel_index ),
   m_node_index( node_index ),
   m_min_sample_frequency_hz( query_min_sample_frequency_hz() ),
   m_max_sample_frequency_hz( query_max_sample_frequency_hz() ),
   m_min_amplitude( query_min_amplitude() ),
   m_max_amplitude( query_max_amplitude() )
{
}


Abstract_Signal_Component::~Abstract_Signal_Component()
{
}


void Abstract_Signal_Component::enable()
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeEnableSet( m_device_descriptor,
                                                 m_channel_index,
                                                 m_node_index,
                                                 true ) );
}


void Abstract_Signal_Component::disable()
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeEnableSet( m_device_descriptor,
                                                 m_channel_index,
                                                 m_node_index,
                                                 false ) );
}


bool Abstract_Signal_Component::is_enabled() const
{
   BOOL buffer = false;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeEnableGet( m_device_descriptor,
                                                 m_channel_index,
                                                 m_node_index,
                                                 &buffer ) );

   return buffer;
}


void Abstract_Signal_Component::set_waveform_shape( ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::Enum waveform )
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFunctionSet( m_device_descriptor,
                                                   m_channel_index,
                                                   m_node_index,
                                                   Waveform_Shape_Translate::to_dwf( waveform ) ) );
}


::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::Enum Abstract_Signal_Component::get_waveform_shape() const
{
   FUNC buffer = funcDC;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFunctionGet( m_device_descriptor,
                                                   m_channel_index,
                                                   m_node_index,
                                                   &buffer ) );

   return Waveform_Shape_Translate::from_dwf( buffer );
}


void Abstract_Signal_Component::write( double samples[], int sample_count )
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeDataSet( m_device_descriptor,
                                               m_channel_index,
                                               m_node_index,
                                               samples,
                                               sample_count ) );
}


void Abstract_Signal_Component::set_sample_frequency_hz( double frequency )
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFrequencySet( m_device_descriptor,
                                                    m_channel_index,
                                                    m_node_index,
                                                    frequency ) );
}


double Abstract_Signal_Component::get_sample_frequency_hz() const
{
   double buffer = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFrequencyGet( m_device_descriptor,
                                                    m_channel_index,
                                                    m_node_index,
                                                    &buffer ) );
   return buffer;
}


double Abstract_Signal_Component::get_min_sample_frequency_hz() const
{
   return m_min_sample_frequency_hz;
}


double Abstract_Signal_Component::get_max_sample_frequency_hz() const
{
   return m_max_sample_frequency_hz;
}


void Abstract_Signal_Component::set_amplitude( double amplitude )
{
   DWF_CALL_WRAPPER( FDwfAnalogOutNodeAmplitudeSet( m_device_descriptor,
                                                    m_channel_index,
                                                    m_node_index,
                                                    amplitude ) );
}


double Abstract_Signal_Component::get_amplitude() const
{
   double buffer = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeAmplitudeGet( m_device_descriptor,
                                                    m_channel_index,
                                                    m_node_index,
                                                    &buffer ) );
   return buffer;
}


double Abstract_Signal_Component::get_min_amplitude() const
{
   return m_min_amplitude;
}


double Abstract_Signal_Component::get_max_amplitude() const
{
   return m_max_amplitude;
}


double Abstract_Signal_Component::query_min_sample_frequency_hz() const
{
   double min = 0.0;
   double max = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFrequencyInfo( m_device_descriptor,
                                                     m_channel_index,
                                                     m_node_index,
                                                     &min,
                                                     &max ) );

   return min;
}


double Abstract_Signal_Component::query_max_sample_frequency_hz() const
{
   double min = 0.0;
   double max = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeFrequencyInfo( m_device_descriptor,
                                                     m_channel_index,
                                                     m_node_index,
                                                     &min,
                                                     &max ) );

   return max;
}


double Abstract_Signal_Component::query_min_amplitude() const
{
   double min = 0.0;
   double max = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeAmplitudeInfo( m_device_descriptor,
                                                     m_channel_index,
                                                     m_node_index,
                                                     &min,
                                                     &max ) );

   return min;
}


double Abstract_Signal_Component::query_max_amplitude() const
{
   double min = 0.0;
   double max = 0.0;

   DWF_CALL_WRAPPER( FDwfAnalogOutNodeAmplitudeInfo( m_device_descriptor,
                                                     m_channel_index,
                                                     m_node_index,
                                                     &min,
                                                     &max ) );

   return max;
}

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer

