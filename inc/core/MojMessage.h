// Copyright (c) 2009-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0


#ifndef MOJMESSAGE_H_
#define MOJMESSAGE_H_

#include "core/MojCoreDefs.h"
#include "core/MojSignal.h"

class MojMessage : public MojSignalHandler
{
public:
	virtual ~MojMessage() {}
	virtual MojErr dispatch() = 0;
	virtual const MojChar* queue() const = 0;

protected:
	friend class MojMessageDispatcher;

	MojListEntry m_queueEntry;
};

#endif /* MOJMESSAGE_H_ */
