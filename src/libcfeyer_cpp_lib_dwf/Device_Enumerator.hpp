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

#ifndef CFEYER__CPP_LIB_DWF__DEVICE_ENUMERATOR_HPP
#define CFEYER__CPP_LIB_DWF__DEVICE_ENUMERATOR_HPP

#include <cfeyer/cpp_api_dwf/Device_Enumerator_Interface.hpp>

#include <vector>

namespace cfeyer {
namespace cpp_lib_dwf {

class Device;

class Device_Enumerator : public ::cfeyer::cpp_api_dwf::Device_Enumerator_Interface
{
   public:

      Device_Enumerator();
      ~Device_Enumerator();

      Device_Enumerator( const Device_Enumerator & ) = delete;
      Device_Enumerator & operator = ( const Device_Enumerator & ) = delete;

      int get_device_count() const override;
      ::cfeyer::cpp_api_dwf::Device_Interface & get_device( int device_index ) override;

   private:

      void scan();

      std::vector<Device *> m_device_ptrs;
};

} // namespace cpp_lib_dwf
} // namespace cfeyer

#endif /* CFEYER__CPP_LIB_DWF__DEVICE_ENUMERATOR_HPP */
