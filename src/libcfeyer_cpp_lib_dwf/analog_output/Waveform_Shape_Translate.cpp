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

#include "analog_output/Waveform_Shape_Translate.hpp"
#include <digilent/waveforms/dwf.h>
#include <stdexcept>

namespace cfeyer {
namespace cpp_lib_dwf {
namespace analog_output {

FUNC Waveform_Shape_Translate::to_dwf( ::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape_Enum x )
{
   using namespace ::cfeyer::cpp_api_dwf::analog_output;

   FUNC y = funcDC;

   switch( x )
   {
      case Waveform_Shape_Enum::constant:  y = funcDC;       break;
      case Waveform_Shape_Enum::sinusoid:  y = funcSine;     break;
      case Waveform_Shape_Enum::square:    y = funcSquare;   break;
      case Waveform_Shape_Enum::triangle:  y = funcTriangle; break;
      case Waveform_Shape_Enum::ramp_up:   y = funcRampUp;   break;
      case Waveform_Shape_Enum::ramp_down: y = funcRampDown; break;
      case Waveform_Shape_Enum::noise:     y = funcNoise;    break;
      case Waveform_Shape_Enum::custom:    y = funcCustom;   break;
      case Waveform_Shape_Enum::play:      y = funcPlay;     break;
      default: throw std::invalid_argument( __PRETTY_FUNCTION__ );
   }

   return y;
}


::cfeyer::cpp_api_dwf::analog_output::Waveform_Shape_Enum Waveform_Shape_Translate::from_dwf( FUNC x )
{
   using namespace ::cfeyer::cpp_api_dwf::analog_output;

   Waveform_Shape_Enum y = Waveform_Shape_Enum::constant;

   switch( x )
   {
      case funcDC:       y = Waveform_Shape_Enum::constant;  break;
      case funcSine:     y = Waveform_Shape_Enum::sinusoid;  break;
      case funcSquare:   y = Waveform_Shape_Enum::square;    break;
      case funcTriangle: y = Waveform_Shape_Enum::triangle;  break;
      case funcRampUp:   y = Waveform_Shape_Enum::ramp_up;   break;
      case funcRampDown: y = Waveform_Shape_Enum::ramp_down; break;
      case funcNoise:    y = Waveform_Shape_Enum::noise;     break;
      case funcCustom:   y = Waveform_Shape_Enum::custom;    break;
      case funcPlay:     y = Waveform_Shape_Enum::play;      break;
      default: throw std::invalid_argument( __PRETTY_FUNCTION__ );
   }

   return y;
}

} // namespace analog_output
} // namespace cpp_lib_dwf
} // namespace cfeyer
