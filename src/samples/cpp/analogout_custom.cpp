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

#include <iostream>
#include <unistd.h>

#include <cfeyer/cpp_lib_dwf/Library.hpp>
#include <cfeyer/cpp_api_dwf/Device_Enumerator_Interface.hpp>
#include <cfeyer/cpp_api_dwf/Device_Interface.hpp>
#include <cfeyer/cpp_api_dwf/Open_Device_Interface.hpp>
#include <cfeyer/cpp_api_dwf/analog_output/Channels_Interface.hpp>
#include <cfeyer/cpp_api_dwf/analog_output/Channel_Interface.hpp>
#include <cfeyer/cpp_api_dwf/analog_output/Carrier_Component_Interface.hpp>
#include <cfeyer/cpp_api_dwf/analog_output/Waveform_Shape_Enum.hpp>


int main( int argc, char * argv[] )
{
   ::cfeyer::cpp_lib_dwf::Library cpp_lib_dwf;

   ::cfeyer::cpp_api_dwf::Device_Enumerator_Interface & device_enumerator = cpp_lib_dwf.get_device_enumerator();

   const int device_index = 0;
   ::cfeyer::cpp_api_dwf::Device_Interface & device =
         device_enumerator.get_device( device_index );

   std::cerr << "name: " << device.get_name() << "\n"
             << "user: "<< device.get_user_name() << "\n"
             << "serial: " << device.get_serial_number() << "\n"
             << "busy: " << device.is_busy()
             << std::endl;

   ::cfeyer::cpp_api_dwf::Open_Device_Interface * p_open_device = device.open();

   const int sample_count = 4096;
   double samples[sample_count];
   for( int n = 0; n < sample_count; n++ )
   {
      samples[n] = 2.0*n/4095-1;
   }

   ::cfeyer::cpp_api_dwf::analog_output::Channel_Interface & ao1 =
      p_open_device->get_analog_outputs().get_channel(0);

   ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface & ao1_carrier =
      *(ao1.get_carrier_component());

   ao1_carrier.enable();
   ao1_carrier.set_waveform_shape( ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::custom );
   ao1_carrier.set_data( samples, sample_count );
   ao1_carrier.set_frequency_hz( 10.0e3 );
   ao1_carrier.set_amplitude_volts( 2.0 );

   ao1.start();

   for( unsigned int duration_seconds = 5; (duration_seconds = sleep( duration_seconds )) > 0; );
   
   delete p_open_device;
   p_open_device = 0;

   return 0;
}
