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

#include <cfeyer/cpp_api_dwf/Device_Interface.hpp>
#include <cfeyer/cpp_lib_dwf/Device_Enumerator.hpp>

int main( int argc, char * argv[] )
{
   ::cfeyer::cpp_lib_dwf::Device_Enumerator device_enumerator;

   int device_count = device_enumerator.get_device_count();

   std::cout << "Device count: " << device_count << std::endl;

   for( int device_index = 0; device_index < device_count; device_index++ )
   {
      std::cout << "device index " << device_index << ":" << std::endl;

      ::cfeyer::cpp_api_dwf::Device_Interface & device =
         device_enumerator.get_device( device_index );

      std::cout << "name: " << device.get_name() << "\n"
                << "user: "<< device.get_user_name() << "\n"
                << "serial: " << device.get_serial_number() << "\n"
                << "busy: " << device.is_busy()
                << std::endl;

      device.open();
   }

   return 0;
}
