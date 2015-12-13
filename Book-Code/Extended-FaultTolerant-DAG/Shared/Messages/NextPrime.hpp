/*
Copyright (c) 2015 James Dean Mathias

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _NEXTPRIMEMESSAGE_HPP_
#define _NEXTPRIMEMESSAGE_HPP_

#include "TaskMessage.hpp"

//
// Google Protocol Buffers cause hella warnings, ignore them
#pragma warning(push, 0)
#include "NextPrime.pb.h"
#pragma warning(pop)

namespace Tasks
{
	class NextPrimeTask;
}

namespace Messages
{
	// -----------------------------------------------------------------
	//
	// @details This class is used to send a next prime task message
	// to a compute node.
	//
	// -----------------------------------------------------------------
	class NextPrime : public TaskMessage<PBMessages::NextPrime>
	{
	public:
		NextPrime() :
			TaskMessage(Messages::Type::NextPrime)
		{
		}

		NextPrime(uint64_t taskId, uint32_t lastPrime) :
			TaskMessage(Messages::Type::NextPrime, taskId)
		{
			m_message.set_lastprime(lastPrime);
		}

	private:
		friend class Tasks::NextPrimeTask;
	};
}

#endif // _NEXTPRIMEMESSAGE_HPP_
