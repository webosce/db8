// Copyright (c) 2009-2023 LG Electronics, Inc.
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


#ifndef MOJREACTOR_H_
#define MOJREACTOR_H_

#include "core/MojCoreDefs.h"
#include "core/MojSignal.h"

class MojReactor : private MojNoCopy
{
public:
	typedef MojSignal<MojSockT> SockSignal;

	inline virtual ~MojReactor() {}
	virtual MojErr init() = 0;
	virtual MojErr run() = 0;
	virtual MojErr stop() = 0;
	virtual MojErr dispatch() = 0;
	virtual MojErr addSock(MojSockT sock) = 0;
	virtual MojErr removeSock(MojSockT sock) = 0;
	virtual MojErr notifyReadable(MojSockT sock, SockSignal::SlotRef slot) = 0;
	virtual MojErr notifyWriteable(MojSockT sock, SockSignal::SlotRef slot) = 0;
};

#endif /* MOJREACTOR_H_ */
