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

#ifndef CFEYER__CPP_API_DWF__ANALOG_OUTPUT__ABSTRACT_SIGNAL_COMPONENT_HPP
#define CFEYER__CPP_API_DWF__ANALOG_OUTPUT__ABSTRACT_SIGNAL_COMPONENT_HPP

#include <cfeyer/cpp_api_dwf/analog_output/Abstract_Signal_Component_Interface.hpp>
#include <digilent/waveforms/dwf.h>

namespace cfeyer {

namespace cpp_api_dwf {
namespace analog_output {
enum class Waveform_Shape_Enum;
}
}

namespace cpp_lib_dwf {
namespace analog_output {


class Abstract_Signal_Component : virtual public ::cfeyer::cpp_api_dwf::analog_output::Abstract_Signal_Component_Interface
{
   public:

      Abstract_Signal_Component() = delete;
      Abstract_Signal_Component( const Abstract_Signal_Component & ) = delete;
      Abstract_Signal_Component & operator = ( const Abstract_Signal_Component & ) = delete;

      virtual ~Abstract_Signal_Component();

      void enable() override;
      void disable() override;
      bool is_enabled() const override;

      void set_waveform_shape( ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::Enum waveform ) override;
      ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape::Enum get_waveform_shape() const override;

      void set_data( double samples[], int sample_count ) override;
      int get_min_data_samples() const override;
      int get_max_data_samples() const override;

      void set_sample_frequency_hz( double frequency ) override;
      double get_sample_frequency_hz() const override;
      double get_min_sample_frequency_hz() const override;
      double get_max_sample_frequency_hz() const override;

   protected:

      Abstract_Signal_Component( HDWF device_descriptor,
                                 int channel_index,
                                 int node_index );

      const HDWF m_device_descriptor;
      const int m_channel_index;
      const int m_node_index;
   
      void set_amplitude( double amplitude );
      double get_amplitude() const;
      double get_min_amplitude() const;
      double get_max_amplitude() const;

   private:

      const double m_min_sample_frequency_hz;
      const double m_max_sample_frequency_hz;

      const double m_min_amplitude;
      const double m_max_amplitude;

      double query_min_sample_frequency_hz() const;
      double query_max_sample_frequency_hz() const;

      double query_min_amplitude() const;
      double query_max_amplitude() const;
};

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer

#endif /* CFEYER__CPP_API_DWF__ANALOG_OUTPUT__ABSTRACT_SIGNAL_COMPONENT_HPP */
