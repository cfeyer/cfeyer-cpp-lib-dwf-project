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
#include <math.h>
#include <algorithm>

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

   ::cfeyer::cpp_api_dwf::analog_output::Channel_Interface & ao1 =
      p_open_device->get_analog_outputs().get_channel(0);

   ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface & ao1_carrier =
      *(ao1.get_carrier_component());

   ao1_carrier.enable();
   ao1_carrier.set_waveform_shape( ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::play );

   // Play f(t) = sin(t/(2*pi)) for t=[0,1) seconds at 500,000 samples / sec (500,000 samples total)
   const int sample_count = 500000;
   double samples[sample_count] = {0.0};

   const double t_initial_sec = 0.0;
   const double t_final_sec = 1.0;
   const double t_sample = (t_final_sec - t_initial_sec) / sample_count;
   const double pi = 3.14159;

   for( int n = 0; n < sample_count; n++ )
   {
      double t = static_cast<double>(n) * t_sample;
      samples[n] = sin( 2.0 * pi * t );
   }

   ao1_carrier.set_frequency_hz( 500e3 );
   ao1_carrier.set_amplitude_volts( 2.0 );

   int sent_samples_count = 0;
   int next_send_samples_count = 0;

   //next_send_samples_count = std::min( ao1_carrier.get_max_data_samples(), sample_count - sent_samples_count );
   //std::cout << "set_data( " << next_send_samples_count << " )" << std::endl;
   //ao1_carrier.set_data( &samples[sent_samples_count], next_send_samples_count );
   //sent_samples_count += next_send_samples_count;

   ao1.start();

   while( sample_count > sent_samples_count )
   {
      int free_sample_count = 0;
      int lost_sample_count = 0;
      int corrupted_sample_count = 0;

      ao1.get_status();
      ao1_carrier.get_play_status( free_sample_count, lost_sample_count, corrupted_sample_count );

      if( lost_sample_count > 0 )
      {
         std::cout << "Lost " << lost_sample_count << " samples" << std::endl;
      }

      if( corrupted_sample_count > 0 )
      {
         std::cout << "Corrupted " << corrupted_sample_count << " samples" << std::endl;
      }

      next_send_samples_count = std::min( free_sample_count, sample_count - sent_samples_count );

      if( next_send_samples_count > 0 )
      {
//         std::cout << "write_play_samples( " << next_send_samples_count << " )" << std::endl;
         ao1_carrier.write_play_samples( &samples[sent_samples_count], next_send_samples_count );
      }

      sent_samples_count += next_send_samples_count;
   }
   
   delete p_open_device;
   p_open_device = 0;

   return 0;
}
