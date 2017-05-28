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

#include <cfeyer/cpp_lib_dwf/Library.hpp>
#include <cfeyer/cpp_api_dwf/Device_Enumerator_Interface.hpp>
#include <cfeyer/cpp_api_dwf/Device_Interface.hpp>
#include <cfeyer/cpp_api_dwf/Open_Device_Interface.hpp>

#include <iostream>


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

   const int analog_in_sample_count = 1000;
   double analog_in_samples[analog_in_sample_count] = {0.0};

   
   delete p_open_device;
   p_open_device = 0;

   return 0;
}
