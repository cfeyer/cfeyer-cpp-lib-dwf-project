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

#include "Library_Implementation.hpp"

#include "Device_Enumerator.hpp"

namespace cfeyer {
namespace cpp_lib_dwf {

Library_Implementation::Library_Implementation() :
   mp_device_enumerator( new Device_Enumerator() )
{
}


Library_Implementation::~Library_Implementation()
{
   delete mp_device_enumerator; mp_device_enumerator = nullptr;
}


::cfeyer::cpp_api_dwf::Device_Enumerator_Interface & Library_Implementation::get_device_enumerator()
{
   return *mp_device_enumerator;
}


} // namespace cpp_lib_dwf
} // namespace cfeyer
