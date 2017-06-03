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

#ifndef CFEYER__CPP_LIB_DWF__ANALOG_OUTPUT__CHANNEL_HPP
#define CFEYER__CPP_LIB_DWF__ANALOG_OUTPUT__CHANNEL_HPP

#include <cfeyer/cpp_api_dwf/analog_output/Channel_Interface.hpp>
#include <digilent/waveforms/dwf.h>

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

class Channel : public ::cfeyer::cpp_api_dwf::analog_output::Channel_Interface
{
   public:

      Channel( HDWF device_descriptor, int channel_index );
      ~Channel();

      Channel() = delete;
      Channel( const Channel & ) = delete;
      Channel & operator = ( const Channel & ) = delete;

      void start() override;
      void stop() override;
      void reset() override;

      ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * get_carrier_component() const override;

      void set_repeat_count( int repeat_count ) override;
      int get_repeat_count() const override;
      int get_min_repeat_count() const override;
      int get_max_repeat_count() const override;

   private:

      const HDWF m_device_descriptor;
      const int m_channel_index;

      ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * mp_carrier_component;

      ::cfeyer::cpp_api_dwf::analog_output::Carrier_Component_Interface * new_carrier_component();

      int query_node_info() const;
      bool query_has_node( AnalogOutNode node_index ) const;
};

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer

#endif /* CFEYER__CPP_LIB_DWF__ANALOG_OUTPUT__CHANNEL_HPP */
