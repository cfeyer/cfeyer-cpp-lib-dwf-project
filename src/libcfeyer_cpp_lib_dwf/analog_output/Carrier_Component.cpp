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

#include "analog_output/Carrier_Component.hpp"
#include <digilent/waveforms/dwf.h>

#include <cfeyer/cpp_api_dwf/analog_output/Waveform_Shape_Enum.hpp>

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

Carrier_Component::Carrier_Component( HDWF device_descriptor,
                           int channel_index ) :
   Abstract_Signal_Component( device_descriptor, channel_index, AnalogOutNodeCarrier )
{
}


Carrier_Component::~Carrier_Component()
{
}


void Carrier_Component::set_amplitude_volts( double amplitude )
{
   set_amplitude( amplitude );
}


double Carrier_Component::get_amplitude_volts() const
{
   return get_amplitude();
}


double Carrier_Component::get_min_amplitude_volts() const
{
   return get_min_amplitude();
}


double Carrier_Component::get_max_amplitude_volts() const
{
   return get_max_amplitude();
}

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer

