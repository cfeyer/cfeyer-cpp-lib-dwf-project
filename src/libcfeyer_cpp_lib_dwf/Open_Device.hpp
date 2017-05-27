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

#ifndef CFEYER__CPP_LIB_DWF__OPEN_DEVICE_HPP
#define CFEYER__CPP_LIB_DWF__OPEN_DEVICE_HPP

#include <cfeyer/cpp_api_dwf/Open_Device_Interface.hpp>
#include "Device.hpp"

#include <digilent/waveforms/dwf.h>

namespace cfeyer {

namespace cpp_lib_dwf {

class Open_Device : public ::cfeyer::cpp_lib_dwf::Device,
                    public ::cfeyer::cpp_api_dwf::Open_Device_Interface
{
   public:

      Open_Device( int device_index );
      ~Open_Device();

      Open_Device() = delete;
      Open_Device( const Open_Device & ) = delete;
      Open_Device & operator = ( const Open_Device & ) = delete;

      ::cfeyer::cpp_api_dwf::analog_output::Channels_Interface & get_analog_outputs();

   private:

      const HDWF m_device_descriptor;

      static HDWF open( int device_index );
      void close();

      ::cfeyer::cpp_api_dwf::analog_output::Channels_Interface * mp_analog_outputs;
};

} // namespace cpp_lib_dwf
} // namespace cfeyer

#endif /* CFEYER__CPP_LIB_DWF__OPEN_DEVICE_HPP */
