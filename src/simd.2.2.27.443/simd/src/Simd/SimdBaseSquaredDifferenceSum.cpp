/*
* Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2015 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "Simd/SimdMath.h"
#include "Simd/SimdBase.h"

namespace Simd
{
    namespace Base
    {
		void SquaredDifferenceSum(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride, 
			size_t width, size_t height, uint64_t * sum)
		{
			assert(width < 0x10000);

			*sum = 0;
			for(size_t row = 0; row < height; ++row)
			{
				int rowSum = 0;
				for(size_t col = 0; col < width; ++col)
				{
					rowSum += SquaredDifference(a[col], b[col]);
				}
				*sum += rowSum;
				a += aStride;
				b += bStride;
			}
		}

		void SquaredDifferenceSumMasked(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride, 
			const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum)
		{
			assert(width < 0x10000);

			*sum = 0;
			for(size_t row = 0; row < height; ++row)
			{
				int rowSum = 0;
				for(size_t col = 0; col < width; ++col)
				{
					if(mask[col] == index)
						rowSum += SquaredDifference(a[col], b[col]);
				}
				*sum += rowSum;
				a += aStride;
				b += bStride;
				mask += maskStride;
			}
		}

        float SquaredDifferenceSum32f(const float * a, const float * b, size_t size)
        {
            float sum = 0;
            for(size_t i = 0; i < size; ++i)
                sum += Simd::Square(a[i] - b[i]);
            return sum;
        }
    }
}
